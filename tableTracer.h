//
// Created by sami on 4/22/19.
//

#ifndef PARSER_TABLETRACER_H
#define PARSER_TABLETRACER_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <stack>
#include "InputHandler.h"
#include "parsing.h"

using namespace std;

class tableTracer {
private:
    bool firstError = false ;
    stack<string> inputSymbols;
    vector<string> reversedSymbols;
    stack<string> TokensStack;
    map<string,int> terminalIndex;
    map<string,int> lhsIndex;
    vector<vector<string>> parsingTable;
    map<string,vector<string>> followMap;
    vector<string> RHStokens;
    vector<string> follow;
    InputHandler *nonFiniteAutomata = InputHandler::getInstance();
    parsing *parsingTabel = parsing::getInstance();
    std::ofstream file;
public:
    static tableTracer* getInstance();
    void readSymbolTable(string address);
    void initializeInputStack();
    void trace();
    string getEelementFromTable(string leftHandSide ,string input);
    void rightTokensSeparator(string rightHandSideToken);
    void pushToStack(vector<string> tokens);
    void printStacks();
    void printSynch(string token);
    void printError(string token);
    void printLamda();
    void printMatch(string match);
    void printAction(string action);

};


#endif //PARSER_TABLETRACER_H
