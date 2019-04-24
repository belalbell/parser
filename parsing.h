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
    map<string,int> terminalIndex;
    map<string,int> lhsIndex;
    map<string,vector<string>> firstMap;
    map<string,vector<string>> followMap;
    vector<vector<string>> parsingTable;
    vector<string> remainingFollow;
    vector<string> cloneFollow;

public:

    static parsing* getInstance();

    void first();
    void firstFirst(string lhs);
    void follow();
    void followFollow(string lhs);
    void initalizeTable();
    void constractTable();
    int getTerminalIndex(string terminal);
    int getLhsIndex(string lhs);
    map<string,int> getterminalIndex();
    map<string,int> getlhsIndex();
    vector<vector<string>> getParsingTable();

    map<string,vector<string>> getFollowMap();

};


#endif //PARSER_PARSING_H
