//
// Created by Sara on 22/04/2019.
//

#include "NotImmediateLeftRecursion.h"

static NotImmediateLeftRecursion *instance = nullptr;

NotImmediateLeftRecursion *NotImmediateLeftRecursion::getInstance() {
    if (instance == nullptr) {
        instance = new NotImmediateLeftRecursion();
    }
    return instance;
}

void NotImmediateLeftRecursion::eliminateNotImmediateLeftRecursion() {
    string currentSymbol;
    int firstSymbolExistenceIndex, secondSymbolExistenceIndex;
    vector<string> newFirstGrammmar;

    for (int lhsIndex = 0; lhsIndex < inputHandler->getLHSSize(); ++lhsIndex) {
        currentSymbol = inputHandler->getLHS()[lhsIndex];
        for (int rhsIndex = 0; rhsIndex < inputHandler->getRHSSize(); ++rhsIndex) {
            firstSymbolExistenceIndex = findSymbolExistenceIndex(inputHandler->getLHSByIndex(lhsIndex),
                                                                 inputHandler->getRHSByIndex(rhsIndex));
            if (firstSymbolExistenceIndex != -1) {
                secondSymbolExistenceIndex = findSymbolExistenceIndex(inputHandler->getLHSByIndex(rhsIndex),
                                                                      inputHandler->getRHSByIndex(lhsIndex));
                if (secondSymbolExistenceIndex != -1) {
                    newFirstGrammmar = substitute(inputHandler->getLHSByIndex(rhsIndex),
                                                  inputHandler->getRHSByIndex(rhsIndex),
                                                  inputHandler->getRHSByIndex(lhsIndex)));
                    immediateLeftRecursion->eliminateImmediateLeftRecursion(inputHandler->getLHSByIndex(lhsIndex),
                                                                            newFirstGrammmar);
                }
            }
        }
    }
}

vector<string> NotImmediateLeftRecursion::substitute(string firstSymbol, vector<string> firstGrammar,
                                                     vector<string> secondGrammar) {
    string temp, result = "";
    int size = secondGrammar.size();
    for (int secondGrammarNodeIndex = 0; secondGrammarNodeIndex < size; ++secondGrammarNodeIndex) {
        if (secondGrammar[secondGrammarNodeIndex].find(firstSymbol) == 0) {
            temp = secondGrammar[secondGrammarNodeIndex];
            result = temp;
            result = firstGrammar[0] + result.substr(1);
            secondGrammar[secondGrammarNodeIndex] = result;
            for (int firstGrammarNodeIndex = 0; firstGrammarNodeIndex < firstGrammar.size(); ++firstGrammarNodeIndex) {
                result = temp;
                result = firstGrammar[firstGrammarNodeIndex] + result.substr(1);
                secondGrammar.push_back(result);
            }
        }
    }
    return secondGrammar;
}

int NotImmediateLeftRecursion::findSymbolExistenceIndex(string symbol, vector<string> grammar) {
    for (int nodeIndex = 0; nodeIndex < grammar.size(); ++nodeIndex) {
        if (grammar[nodeIndex].find(symbol) == 0) {
            return nodeIndex;
        }
    }
    return -1;
}