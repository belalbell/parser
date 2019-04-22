//
// Created by Sara on 22/04/2019.
//

#ifndef PARSER_LEFTFACTORING_H
#define PARSER_LEFTFACTORING_H

#include <string>
#include <vector>
#include "InputHandler.h"
#include "SymbolsNames.h"

using namespace std;

class LeftFactoring {
private:
    InputHandler *inputHandler = InputHandler::getInstance();
    SymbolsNames * symbolsNames = SymbolsNames::getInstance();
public:
    static LeftFactoring *getInstance();

    void perfomLeftFactoring();

    vector<string> findGrammarToCompare(int startIndex, vector<string> currentGrammar);

    vector<string> createLeftFactoredGrammar(vector<string> comparedGrammar, int letterTokenIndex, string symbol,
                                             vector<string> currentGrammar);

    vector<string> eraseNonMatchedNodes(string originalStr, vector<string> currentGrammar, int startComparedIndex);
};


#endif //PARSER_LEFTFACTORING_H
