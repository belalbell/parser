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
                                                        string symbol, vector<string> currentGrammar) {
    string newSymbol = symbol + symbol, temp;
    vector<string> originalGrammar, newGrammar;
    inputHandler->setLHS(newSymbol);
    string currentToken = comparedGrammar[0].substr(0, letterTokenIndex);
    originalGrammar.push_back(currentToken + " " + newSymbol);
    for (int nodeIndex = 0; nodeIndex < currentGrammar.size(); ++nodeIndex) {
        if (currentGrammar[nodeIndex].find(currentToken) == string::npos ||
            currentGrammar[nodeIndex].find(currentToken) != 0) {
            originalGrammar.push_back(currentGrammar[nodeIndex]);
        } else if (currentGrammar[nodeIndex].find(currentToken) != string::npos ||
                   currentGrammar[nodeIndex].find(currentToken) == 0) {
            temp = currentGrammar[nodeIndex].substr(letterTokenIndex + 1);
            if (temp.size() == 0) {
                temp = "\\L";
            }
            newGrammar.push_back(temp);
        }
    }
    inputHandler->setLeftToRight(newSymbol, newGrammar);
    return originalGrammar;
}

vector<string> LeftFactoring::eraseNonMatchNodes(string originalStr, vector<string> currentGrammar,
                                                 int startComparedIndex) {}

vector<string> LeftFactoring::findGrammarToCompare(int startIndex, vector<string> currentGrammar) {
    vector<string> newGrammar;
    for (int nodeIndex = startIndex; nodeIndex < currentGrammar.size(); ++nodeIndex) {
        newGrammar.push_back(currentGrammar[nodeIndex]);
    }
    return newGrammar;
}

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