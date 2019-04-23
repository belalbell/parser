//
// Created by sami on 4/22/19.
//

#include "tableTracer.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include<bits/stdc++.h>
#include <map>

using namespace std;

static tableTracer *insatnce = nullptr;

tableTracer *tableTracer::getInstance() {
    if (insatnce == nullptr) {
        insatnce = new tableTracer();
    }
    return insatnce;
}

void tableTracer::readSymbolTable(string address) {
    ifstream in(address);
    string tmp ;

    getline(in, tmp);
    while (getline(in, tmp)) {
        string delimiter = "\t";
        size_t pos = 0;
        pos = tmp.find(delimiter);
        tmp = tmp.substr(0, pos);
        reversedSymbols.insert(reversedSymbols.end() , tmp);
    }
    initializeInputStack();
}

void tableTracer::initializeInputStack(){
    inputSymbols.push("$");
    for (auto it = reversedSymbols.rbegin(); it != reversedSymbols.rend(); ++it){
        inputSymbols.push(*it);
    }
    TokensStack.push("$");
    string starting = nonFiniteAutomata->getStartingState();
    TokensStack.push(starting);

    lhsIndex = parsingTabel->getlhsIndex();
    terminalIndex = parsingTabel->getterminalIndex();
    parsingTable = parsingTabel->getParsingTable();
    followMap = parsingTabel->getFollowMap();

}

void tableTracer::trace(){
    string currentInput ,topOfStack ,action;
    while (!inputSymbols.empty()){
        printStacks();
        currentInput = inputSymbols.top();
        topOfStack = TokensStack.top();
        if (currentInput == topOfStack){
            inputSymbols.pop();
            TokensStack.pop();
            printMatch(currentInput);
        } else{
            action = getEelementFromTable(topOfStack ,currentInput);
            if (action != "error"){
                firstError = false ;
                if (action == "\L"){
                    TokensStack.pop();
                    printLamda();
                } else{
                    TokensStack.pop();
                    rightTokensSeparator(action);
                    pushToStack(RHStokens);
                    printAction(action);
                }
            } else{
                follow.clear();
                bool found = false ;
                if (isupper(topOfStack.at(0))){
                    follow = followMap.at(topOfStack);
                    for (auto it = follow.begin(); it != follow.end(); ++it){
                        if (*it == currentInput){
                            found = true ;
                            TokensStack.pop();
                            firstError = false ;
                            printSynch(topOfStack);
                            break;
                        }
                    }
                    if (!found){
                        //error
                        if (firstError){
                            inputSymbols.pop();

                        } else{
                            inputSymbols.pop();
                            firstError = true ;
                            printError(currentInput);
                        }
                    }
                } else{
                    TokensStack.pop();

                    printError(topOfStack);
                    if (firstError){
                    } else{
                        firstError = true ;
                    }
                }
            }

        }
    }
}

string tableTracer::getEelementFromTable(string leftHandSide ,string input){
    int x = 0;
    int y = 0 ;
    string action;
    x = lhsIndex.at(leftHandSide);
    y = terminalIndex.at(input);
    action = parsingTable.at(x).at(y);
    return action ;

}
void tableTracer::rightTokensSeparator(string rightHandSideToken){
    size_t pos = 0;
    string delimiter = " ";
    string token ,tmp = rightHandSideToken;
    RHStokens.clear();
    while ((pos = tmp.find(delimiter)) != std::string::npos) {
        token = tmp.substr(0, pos);
        RHStokens.insert(RHStokens.end(),token);
        tmp.erase(0, pos + delimiter.length());
    }
    RHStokens.insert(RHStokens.end(),tmp);
}

void tableTracer::pushToStack(vector<string> tokens) {
    for (auto it = tokens.rbegin(); it != tokens.rend(); ++it){
        TokensStack.push(*it);
    }
}

void tableTracer::printStacks(){

    file.open("output.txt", std::ios_base::app);
    stack<string> temp = inputSymbols ;
    stack<string> temp1 = TokensStack ;
    file << "- stack:  ";
    while (!temp1.empty()){
        std::cout << temp1.top() << "\t";
        file << temp1.top() << "\t";
        temp1.pop();
    }
    file <<"\n";
    std::cout << "\n";
    file<<"- input:  ";
    while (!temp.empty()){
        std::cout << temp.top() << "\t";
        file << temp.top() << "\t";
        temp.pop();
    }
    file<<"\n";

    file.close();
}
void tableTracer::printMatch(string match){
    file.open("output.txt", std::ios_base::app);
    std::cout << "match("<< match << ")"<< std::endl;
    file<<"- Action: "<< "match("<< match << ")"<< std::endl;
    file <<"\n\n";
    file.close();
}

void tableTracer::printLamda(){
    file.open("output.txt", std::ios_base::app);
    std::cout << "\L"<<std::endl;
    file<<"- Action: " << "\L"<<std::endl;
    file <<"\n\n";

    file.close();
}
void tableTracer::printAction(string action){
    file.open("output.txt", std::ios_base::app);
    std::cout << action << std::endl;
    file<<"- Action: " <<  action <<std::endl;
    file <<"\n\n";
    file.close();
}
void tableTracer::printSynch(string token){
    file.open("output.txt", std::ios_base::app);
    std::cout << "Synch at ("<< token << ")"<< std::endl;
    file<<"- Action: " << "Synch at ("<< token << ")" << std::endl;
    file <<"\n\n";
    file.close();
}
void tableTracer::printError(string token){
    file.open("output.txt", std::ios_base::app);
    std::cout << "Error at ("<< token << ")"<< std::endl;
    file<<"- Action: " << "Error at ("<< token << ")" << std::endl;
    file <<"\n\n";
    file.close();
}
