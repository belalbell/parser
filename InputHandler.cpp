//
// Created by sami on 4/19/19.
//

#include "InputHandler.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include<bits/stdc++.h>
#include <map>

using namespace std;

static InputHandler *insatnce = nullptr;

InputHandler *InputHandler::getInstance() {
    if (insatnce == nullptr) {
        insatnce = new InputHandler();
    }
    return insatnce;
}

void InputHandler::readFile(string address) {
    ifstream in(address);
    string tmp, nextLine;

    getline(in, tmp);
    tmp.erase(std::remove(tmp.begin(), tmp.end(), '\''), tmp.end());
    while (getline(in, nextLine)) {
        nextLine.erase(std::remove(nextLine.begin(), nextLine.end(), '\''), nextLine.end());
        while (true) {
            if (nextLine.at(0) != '#') {
                tmp.append(" ");
                tmp.append(nextLine);
                getline(in, nextLine);
                nextLine.erase(std::remove(nextLine.begin(), nextLine.end(), '\''), nextLine.end());
            } else {
                tmp.erase(0, 2);
                LeftRightInputs(tmp);
                tmp = nextLine;
                break;
            }
        }
    }
    tmp.erase(0, 2);
    LeftRightInputs(tmp);
    rhsSize = LHSinputs.size();
}

void InputHandler::LeftRightInputs(string line) {
    size_t pos = 0;
    string LHS, RHS;
    string delimiter = "=";
    pos = line.find(delimiter);
    LHS = line.substr(0, pos);
    LHS.erase(remove_if(LHS.begin(), LHS.end(), ::isspace), LHS.end());
    LHSinputs.insert(LHSinputs.end(), LHS);
    line.erase(0, pos + delimiter.length() + 1);
    RHS = line;
    rightInputsSeparator(RHS);
    leftToRight[LHS] = RHSinputs;


}

void InputHandler::rightInputsSeparator(string rightHandSide) {
    size_t pos = 0;
    string delimiter = "|";
    string token;
    RHSinputs.clear();
    while ((pos = rightHandSide.find(delimiter)) != std::string::npos) {
        token = rightHandSide.substr(0, pos);
        RHSinputs.insert(RHSinputs.end(), token);
        rightTokensSeparator(token);
        rightHandSide.erase(0, pos + delimiter.length() + 1);
    }
    RHSinputs.insert(RHSinputs.end(), rightHandSide);
    rightTokensSeparator(rightHandSide);
}

void InputHandler::rightTokensSeparator(string rightHandSideToken) {
    size_t pos = 0;
    string delimiter = " ";
    string token, tmp = rightHandSideToken;
    RHStokens.clear();
    while ((pos = tmp.find(delimiter)) != std::string::npos) {
        token = tmp.substr(0, pos);
        //token.erase(std::remove(token.begin(), token.end(), '\''), token.end());
        checkIfTerminal(token);
        if (!token.empty())
            RHStokens.insert(RHStokens.end(), token);
        tmp.erase(0, pos + delimiter.length());
    }
    //tmp.erase(std::remove(tmp.begin(), tmp.end(), '\''), tmp.end());
    if (!tmp.empty()){
        checkIfTerminal(tmp);
        RHStokens.insert(RHStokens.end(), tmp);
    }
    rightToTokens[rightHandSideToken] = RHStokens;
}


void InputHandler::setLHS(string leftHandSide) {
    LHSinputs.insert(LHSinputs.end(), leftHandSide);
}

vector<string> InputHandler::getLHS() {
    return LHSinputs;
}

void InputHandler::deleteFromLHS(string leftHandSide) {
    LHSinputs.erase(std::remove(LHSinputs.begin(), LHSinputs.end(), leftHandSide), LHSinputs.end());
}


void InputHandler::setLeftToRight(string leftHandSide, vector<string> rightHandSide) {
    leftToRight[leftHandSide] = rightHandSide;
    if (leftHandSide[leftHandSide.size() - 1] == '\'')
        leftHandSide.erase(remove_if(leftHandSide.begin(), leftHandSide.end(), ::isspace), leftHandSide.end());
    for (auto it = rightHandSide.begin(); it != rightHandSide.end(); ++it) {
        rightTokensSeparator(*it);
    }
    rhsSize++;
}

map<string, vector<string>> InputHandler::getLeftToRight() {
    return leftToRight;
}

void InputHandler::deleteFromLeftToRight(string leftHandSide) {
    leftToRight.erase(leftHandSide);
}


void InputHandler::setRightToTokens(string RightHandSide, vector<string> Tokens) {
    rightToTokens[RightHandSide] = Tokens;
}

map<string, vector<string>> InputHandler::getRightToTokens() {
    return rightToTokens;
}

void InputHandler::deleteFromRightToTokens(string RightHandSide) {
    rightToTokens.erase(RightHandSide);
}

void InputHandler::checkIfTerminal(string token) {
    if (!token.empty() && token != "\\L") {
        if (!isupper(token.at(0))) {
            if (std::find(Terminals.begin(), Terminals.end(), token) != Terminals.end()) {
                return;
            } else {
                Terminals.insert(Terminals.end(), token);
            }
        }
    }
}

void InputHandler::print() {
    //std::cout << tmp << std::endl;
    /*for(auto elem : rightToTokens)
    {
        std::cout << elem.first << " \t\t\t\t";
        for (auto it = elem.second.begin(); it != elem.second.end(); ++it){
            cout << *it << "\t\t\t\t";
        }
        cout << "\n";
    }
     */
    /*//print the LHS vector which contains all LHS tokens
    for (auto it = LHSinputs.begin(); it != LHSinputs.end(); ++it){
        cout << *it << "\n";
    }

    //for each token in LHS print the corresponding RHS in the form of vector of string tokens
    for(auto elem : leftToRight)
    {
        std::cout << elem.first << " \t\t\t\t";
        for (auto it = elem.second.begin(); it != elem.second.end(); ++it){
            cout << *it << "\t\tOR\t\t";
        }
        cout << "\n";
    }

    //for each token group in the RHS print the corresponding vector of tokens
    for(auto elem : rightToTokens)
    {
        std::cout << elem.first << " \t\t\t\t";
        for (auto it = elem.second.begin(); it != elem.second.end(); ++it){
            cout << *it << "\t\t\t\t";
        }
        cout << "\n";
    }
*/
    for (auto it = Terminals.begin(); it != Terminals.end(); ++it) {
        cout << *it << "\n";
    }
}

vector<string> InputHandler::getLHSinputs() {
    return LHSinputs;
}

vector<string> InputHandler::getLeftToRight(string lhs) {
    return leftToRight[lhs];
}

vector<string> InputHandler::getRightToTokens(string rhs) {
    return rightToTokens[rhs];
}

int InputHandler::getLHSSize() {
    return LHSinputs.size();
}

int InputHandler::getRHSSize() {
    return rhsSize;
}

string InputHandler::getLHSByIndex(int index) {
    return LHSinputs.at(index);
}

vector<string> InputHandler::getRHSByIndex(int index) {
    string lhs = LHSinputs.at(index);
    return leftToRight[lhs];
}

string InputHandler::getStartingState() {
    return LHSinputs.at(0);
}

vector<string> InputHandler::getTerminals() {
    return Terminals;
}