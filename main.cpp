#include <iostream>
#include "InputHandler.h"
#include "InputHandler.h"
#include "ImmediateLeftRecursion.h"
#include "NotImmediateLeftRecursion.h"
#include "LeftFactoring.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include<bits/stdc++.h>
#include <map>

InputHandler *inputHandler = InputHandler::getInstance();

void print() {
    vector<string> temp;
    for (int i = 0; i < inputHandler->getLHSSize(); ++i) {
        temp = inputHandler->getRHSByIndex(i);
        cout << inputHandler->getLHSByIndex(i) << " -> ";
        for (int j = 0; j < temp.size(); ++j) {
            cout << temp[j] << " , ";
        }
        cout << endl;
    }
}

void insert() {
    inputHandler->setLHS("E");
    inputHandler->setLHS("T");
    inputHandler->setLHS("F");

    vector<string> rhsVector;

    rhsVector.push_back("E+T");
    rhsVector.push_back("T");
    inputHandler->setLeftToRight("E", rhsVector);

    rhsVector[0] = "T*F";
    rhsVector[1] = "F";
    inputHandler->setLeftToRight("T", rhsVector);

    rhsVector[0] = "id";
    rhsVector[1] = "(E)";
    inputHandler->setLeftToRight("F", rhsVector);
}


int main() {
    // InputHandler *nonFiniteAutomata = InputHandler::getInstance();
    //nonFiniteAutomata->readFile("E:\\3rd year 2nd semester\\compiler\\phaseTwo\\parser\\sara.txt");
    //nonFiniteAutomata->print();
    insert();
    print();
    cout<<"left size = "<<inputHandler->getLHSSize()<<endl;
    cout<<"right size = "<<inputHandler->getRHSSize()<<endl;
    ImmediateLeftRecursion *immediateLeftRecursion = ImmediateLeftRecursion::getInstance();
    NotImmediateLeftRecursion *notImmediateLeftRecursion = NotImmediateLeftRecursion::getInstance();
    LeftFactoring *leftFactoring = LeftFactoring::getInstance();
    vector<string> rhsVector;
    string lhsStr;
    for (int i = 0; i < inputHandler->getLHSSize(); ++i) {
        rhsVector = inputHandler->getRHSByIndex(i);
        lhsStr = inputHandler->getLHSByIndex(i);
        if (immediateLeftRecursion->isImmediateLeftRecursion(lhsStr, rhsVector)) {
            immediateLeftRecursion->eliminateImmediateLeftRecursion(lhsStr, rhsVector);
        }
    }

    print();

    notImmediateLeftRecursion->eliminateNotImmediateLeftRecursion();
    leftFactoring->perfomLeftFactoring();

    print();
    return 0;
}