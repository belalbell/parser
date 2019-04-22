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

void LeftFactoring::perfomLeftFactoring() {
    vector<string> currentGrammar, comparedGrammar;
    string currentStrToCompare;
    int tokenLettersIndex;
    for (int grammarIndex = 0; grammarIndex < inputHandler.getRHSSize(); ++grammarIndex) {
        currentGrammar = inputHandler.getRHSByIndex(grammarIndex);
        for (int nodeIndex = 0; nodeIndex < currentGrammar.size(); ++nodeIndex) {
            currentStrToCompare = currentGrammar[nodeIndex];
            comparedGrammar = eraseNonMatchNodes(currentStrToCompare, currentGrammar, nodeIndex + 1);
            if (comparedGrammar.size() != 0) {
                tokenLettersIndex = stoi(comparedGrammar[comparedGrammar.size() - 1]);
                comparedGrammar.pop_back();
                currentGrammar = createLeftFactoredGrammar(comparedGrammar, tokenLettersIndex,
                                                           inputHandler.getLHSByIndex(grammarIndex), currentGrammar)
            }
        }
        if (currentGrammar.size() != 0) {
            inputHandler->setLeftToRight(inputHandler.getLHSByIndex(grammarIndex), currentGrammar);
        }
    }
}