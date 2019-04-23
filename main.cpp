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
    inputHandler->setLHS("A");

    vector<string> rhsVector;

    rhsVector.push_back("abB");
    rhsVector.push_back("aB");
    rhsVector.push_back("cdg");
    rhsVector.push_back("cdeB");
    rhsVector.push_back("cdfB");

    inputHandler->setLeftToRight("A", rhsVector);
}


int main() {
     InputHandler *nonFiniteAutomata = InputHandler::getInstance();
    nonFiniteAutomata->readFile("E:\\3rd year 2nd semester\\compiler\\phaseTwo\\parser\\sara.txt");
    //nonFiniteAutomata->print();
   // insert();
    print();
    cout << "left size = " << inputHandler->getLHSSize() << endl;
    cout << "right size = " << inputHandler->getRHSSize() << endl;
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
    cout << "done" << endl;
    notImmediateLeftRecursion->eliminateNotImmediateLeftRecursion();
    leftFactoring->perfomLeftFactoring();

    print();
    cout << "done" << endl;
    return 0;
}