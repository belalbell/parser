//
// Created by Sara on 22/04/2019.
//

#include "ImmediateLeftRecursion.h"

static ImmediateLeftRecursion *instance = nullptr;

ImmediateLeftRecursion *ImmediateLeftRecursion::getInstance() {
    if (instance == nullptr) {
        instance = new ImmediateLeftRecursion();
    }
    return instance;
}

void ImmediateLeftRecursion::eliminateImmediateLeftRecursion(string symbol, vector<string> splittedGrammar) {
    vector<string> firstGrammar, secondGrammar;
    string temp = "", symbolDash = symbolsNames->getASymbolName(symbol);
    int symbolSize = symbol.size();
    inputHandler->setLHS(symbolDash);
    for (int nodeIndex = 0; nodeIndex < splittedGrammar.size(); ++nodeIndex) {
        /*check if the current left hand side is the most left symbol in the right hand side  */
        if (splittedGrammar[nodeIndex].find(symbol) == 0) {
            temp = splittedGrammar[nodeIndex].substr(symbolSize, splittedGrammar[nodeIndex].size() - 1);
            temp += " " + symbolDash;
            secondGrammar.push_back(temp);
        } else if (splittedGrammar[nodeIndex].find(symbol) == string::npos) {
            temp = splittedGrammar[nodeIndex] + " " + symbolDash;
            firstGrammar.push_back(temp);
        }
    }
    secondGrammar.push_back("\\L");
    inputHandler->setLeftToRight(symbol, firstGrammar);
    inputHandler->setLeftToRight(symbolDash, secondGrammar);
}

bool ImmediateLeftRecursion::isImmediateLeftRecursion(string symbol, vector<string> splittedGrammar) {
    for (int nodeIndex = 0; nodeIndex < splittedGrammar.size(); ++nodeIndex) {
        if (splittedGrammar[nodeIndex].find(symbol) == 0) {
            return true;
        }
    }
    return false;
}