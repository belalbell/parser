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

    vector<string> LHSinputs;
    vector<string> RHSinputs;
    vector<string> RHStokens;
    map<string,vector<string>> leftToRight;
    map<string,vector<string>> rightToTokens;
public:

    static InputHandler* getInstance();

    void readFile(string address);
    void LeftRightInputs(string line);
    void rightInputsSeparator(string rightHandSide);
    void rightTokensSeparator(string rightHandSideToken);
    void print();
};


#endif //PARSER_INPUTHANDLER_H
