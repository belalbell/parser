//
// Created by Sara on 22/04/2019.
//

#include "LeftFactoring.h"

static LeftFactoring *instance = nullptr;

LeftFactoring *LeftFactoring::getInstance() {
    if (instance == nullptr) {
        instance = new LeftFactoring();
    }
    return instance;
}

vector<string> LeftFactoring::createLeftFactoredGrammar(vector<string> comparedGrammar, int letterTokenIndex,
                                                        string symbol, vector<string> currentGrammar) {}

vector<string> LeftFactoring::eraseNonMatchNodes(string originalStr, vector<string> currentGrammar,
                                                 int startComparedIndex) {}

vector<string> LeftFactoring::findGrammarToCompare(int startIndex, vector<string> currentGrammar) {}

void LeftFactoring::perfomLeftFactoring() {}