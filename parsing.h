//
// Created by belal.
//

#ifndef PARSER_PARSING_H
#define PARSER_PARSING_H

#include <string>
#include <map>
#include "InputHandler.h"

using namespace std;

class parsing {
private:
    InputHandler* inputHandler = InputHandler::getInstance();
    string** parsingTable =new string*();
    map<string,int> terminalIndex;
    map<string,int> lhsIndex;
    map<string,vector<string>> firstMap;

public:

    static parsing* getInstance();
    string** detParsingTable();
    int getColSize();
    int getRowSize();
    void first();
    void follow();
    int getTerminalIndex(string terminal);
    int getLhsIndex(string lhs);
    map<string,int> getterminalIndex();
    map<string,int> getlhsIndex();

};


#endif //PARSER_PARSING_H
