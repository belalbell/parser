//
// Created by sami on 4/19/19.
//

#ifndef PARSER_INPUTHANDLER_H
#define PARSER_INPUTHANDLER_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

class InputHandler {
private:
    string startingState;
    vector<string> LHSinputs;
    vector<string> RHSinputs;
    vector<string> RHStokens;
    map<string,vector<string>> leftToRight;
    map<string,vector<string>> rightToTokens;
    int rhsSize = 0;
    vector<string> Terminals;
public:

    static InputHandler* getInstance();

    void readFile(string address);
    void LeftRightInputs(string line);
    void rightInputsSeparator(string rightHandSide);
    void rightTokensSeparator(string rightHandSideToken);
    void print();
    vector<string> getLHSinputs();
    vector<string> getTerminals();
    vector<string> getLeftToRight(string lhs);
    vector<string> getRightToTokens(string rhs);
    void setLHS(string leftHandSide);
    vector<string> getLHS();
    void deleteFromLHS(string leftHandSide);

    void setLeftToRight(string leftHandSide ,vector<string> rightHandSide);
    map<string,vector<string>> getLeftToRight();
    void deleteFromLeftToRight(string leftHandSide);

    void setRightToTokens(string RightHandSide ,vector<string> Tokens);
    map<string,vector<string>> getRightToTokens();
    void deleteFromRightToTokens(string RightHandSide);
    int getLHSSize();
    int getRHSSize();
    string getLHSByIndex(int index);
    vector<string> getRHSByIndex(int index);
    string getStartingState();
    void checkIfTerminal(string token);

};


#endif //PARSER_INPUTHANDLER_H