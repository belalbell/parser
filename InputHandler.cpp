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
    string tmp ,nextLine;

    getline(in, tmp);
    while (getline(in, nextLine)) {
        while (true){
            if (nextLine.at(0) != '#'){
                tmp.append(" ");
                tmp.append(nextLine);
                getline(in, nextLine);
            } else{
                tmp.erase(0 ,2);
                LeftRightInputs(tmp);
                tmp = nextLine;
                break;
            }
        }
    }
}
void InputHandler::LeftRightInputs(string line){
    size_t pos = 0;
    string LHS ,RHS ;
    string delimiter = "=";
    pos = line.find(delimiter) ;
    LHS = line.substr(0, pos) ;
    LHSinputs.insert(LHSinputs.end(),LHS);
    line.erase(0, pos + delimiter.length() + 1);
    RHS = line ;
    rightInputsSeparator(RHS);
    leftToRight[LHS] = RHSinputs ;

}
void InputHandler::rightInputsSeparator(string rightHandSide){
    size_t pos = 0;
    string delimiter = "|";
    string token ;
    RHSinputs.clear();
    while ((pos = rightHandSide.find(delimiter)) != std::string::npos) {
        token = rightHandSide.substr(0, pos);
        RHSinputs.insert(RHSinputs.end(),token);
        rightTokensSeparator(token);
        rightHandSide.erase(0, pos + delimiter.length() + 1);
    }
    RHSinputs.insert(RHSinputs.end(),rightHandSide);
    rightTokensSeparator(rightHandSide);
}
void InputHandler::rightTokensSeparator(string rightHandSideToken){
    size_t pos = 0;
    string delimiter = " ";
    string token ,tmp = rightHandSideToken;
    RHStokens.clear();
    while ((pos = tmp.find(delimiter)) != std::string::npos) {
        token = tmp.substr(0, pos);
        token.erase(std::remove(token.begin(), token.end(), '\''), token.end());
        RHStokens.insert(RHStokens.end(),token);
        tmp.erase(0, pos + delimiter.length());
    }
    tmp.erase(std::remove(tmp.begin(), tmp.end(), '\''), tmp.end());
    RHStokens.insert(RHStokens.end(),tmp);
    rightToTokens[rightHandSideToken] = RHStokens ;
}

void InputHandler::print(){
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
}