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
#include "parsing.h"
#include "tableTracer.h"

//InputHandler *inputHandler = InputHandler::getInstance();
//parsing *parsing = parsing::getInstance();
//tableTracer *tracer = tableTracer::getInstance();

//
//void print() {
//    vector<string> temp;
//    for (int i = 0; i < inputHandler->getLHSSize(); ++i) {
//        temp = inputHandler->getRHSByIndex(i);
//        cout << inputHandler->getLHSByIndex(i) << " -> ";
//        for (int j = 0; j < temp.size(); ++j) {
//            cout << temp[j] << " , ";
//        }
//        cout << endl;
//    }
//}
//
//void removeCommaFromReadFile() {
//    vector<string> temp;
//    for (int i = 0; i < inputHandler->getLeftToRight().size(); ++i) {
//        temp = inputHandler->getRHSByIndex(i);
//        for (int j = 0; j < temp.size(); ++j) {
//            if (temp[j].at(0) == '\'' && temp[j].at(temp[j].size() - 1) == '\'') {
//                temp[j] = temp[j].substr(1, temp[j].size() - 2);
//            }
//        }
//        inputHandler->setLeftToRight(inputHandler->getLHS()[i], temp);
//    }
//}
//
//void insert() {
//    inputHandler->setLHS("A");
//
//    vector<string> rhsVector;
//
//    rhsVector.push_back("abB");
//    rhsVector.push_back("aB");
//    rhsVector.push_back("cdg");
//    rhsVector.push_back("cdeB");
//    rhsVector.push_back("cdfB");
//
//    inputHandler->setLeftToRight("A", rhsVector);
//}
//

int main() {
    InputHandler *inputHandler = InputHandler::getInstance();
    parsing *parsing = parsing::getInstance();
    tableTracer *tracer = tableTracer::getInstance();
    //InputHandler *nonFiniteAutomata = InputHandler::getInstance();
    inputHandler->readFile("/home/belal/Downloads/Parser/Parser.txt");
    cout << "sami done" << endl;
    ///////////////////////////////////////////////////////////

    //nonFiniteAutomata->print();
    // insert();
    //removeCommaFromReadFile();


//    cout << "print the current file :" << endl;
//    //print();
//    cout << "left size = " << inputHandler->getLHSSize() << endl;
//    cout << "right size = " << inputHandler->getRHSSize() << endl;
//    ImmediateLeftRecursion *immediateLeftRecursion = ImmediateLeftRecursion::getInstance();
//    NotImmediateLeftRecursion *notImmediateLeftRecursion = NotImmediateLeftRecursion::getInstance();
//    LeftFactoring *leftFactoring = LeftFactoring::getInstance();
//    vector<string> rhsVector;
//    string lhsStr;
//    for (int i = 0; i < inputHandler->getLHSSize(); ++i) {
//        rhsVector = inputHandler->getRHSByIndex(i);
//        lhsStr = inputHandler->getLHSByIndex(i);
//        if (immediateLeftRecursion->isImmediateLeftRecursion(lhsStr, rhsVector)) {
//            immediateLeftRecursion->eliminateImmediateLeftRecursion(lhsStr, rhsVector);
//        }
//    }
//    cout << endl;
//    cout << "Immediate left factoring : " << endl;
//    //print();
//
//    cout << endl;
//    cout << "Not Immediate left factoring : " << endl;
//    notImmediateLeftRecursion->eliminateNotImmediateLeftRecursion();
//    //print();
//
//    cout << endl;
//    cout << "left factoring : " << endl;
//    leftFactoring->perfomLeftFactoring();
//    //print();
//
//    cout << endl;
//    cout << "sara done" << endl;
    ///////////////////////////////////////////////////////////
    parsing->first();
    parsing->follow();
    parsing->initalizeTable();
    parsing->constractTable();
    cout << "belal done" << endl;
    //////////////////////////////////////////////////////////
    tracer->readSymbolTable("/home/belal/Downloads/Parser/symbol_table.txt");
    tracer->trace();
    cout << "sami & mazen done" << endl;
}






//InputHandler *inputHandler = InputHandler::getInstance();


//void print() {
//    vector<string> temp;
//    for (int i = 0; i < inputHandler->getLHSSize(); ++i) {
//        temp = inputHandler->getRHSByIndex(i);
//        cout << inputHandler->getLHSByIndex(i) << " -> ";
//        for (int j = 0; j < temp.size(); ++j) {
//            cout << temp[j] << " , ";
//        }
//        cout << endl;
//    }
//}
//int main() {
//    inputHandler->readFile("/home/belal/Downloads/Parser/Parser.txt");
//    inputHandler->print();
//    print();
//    parsing* parsing = parsing::getInstance();
//    parsing->first();
//    parsing->follow();
//    parsing->initalizeTable();
//    parsing->constractTable();
//    return 0;
//}
