//
// Created by Sara on 22/04/2019.
//

#include "NotImmediateLeftRecursion.h"

static NotImmediateLeftRecursion *insatnce = nullptr;

NotImmediateLeftRecursion *NotImmediateLeftRecursion::getInstance() {
    if (insatnce == nullptr) {
        insatnce = new NotImmediateLeftRecursion();
    }
    return insatnce;
}

void NotImmediateLeftRecursion::elemenateNotImmediateLeftRecursion() {
    string currentSymbol;
    int firstSymbolExistanceIndex, secondSymbolExistanceIndex;
    vector<string> newFirstGrammmar;

    for (int lhsIndex = 0; lhsIndex < inputHandler->getLHSSize(); ++lhsIndex) {
        currentSymbol = inputHandler->getLHS()[lhsIndex];
        for (int rhsIndex = 0; rhsIndex < inputHandler->getRHSSize(); ++rhsIndex) {
            firstSymbolExistanceIndex = findSymbolExistanceIndex(inputHandler->getLHSByIndex(lhsIndex),
                                                                 inputHandler->getRHSByIndex(rhsIndex));
            if (firstSymbolExistanceIndex != -1) {
                secondSymbolExistanceIndex = findSymbolExistanceIndex(inputHandler->getLHSByIndex(rhsIndex),
                                                                      inputHandler->getRHSByIndex(lhsIndex));
                if (secondSymbolExistanceIndex != -1) {
                    newFirstGrammmar = subistitute(inputHandler->getLHSByIndex(rhsIndex),
                                                   inputHandler->getRHSByIndex(rhsIndex),
                                                   inputHandler->getRHSByIndex(lhsIndex)));
                    immediateLeftRecursion->eliminateImmediateLeftRecursion(inputHandler->getLHSByIndex(lhsIndex),
                                                                            newFirstGrammmar);
                }
            }
        }
    }
}

vector<string> NotImmediateLeftRecursion::subistitute(string firstSymbol, vector<string> firstGrammar,
                                                      vector<string> secondGrammar) {

}

int NotImmediateLeftRecursion::findSymbolExistanceIndex(string symbol, vector<string> grammar) {
    for (int nodeIndex = 0; nodeIndex < grammar.size(); ++nodeIndex) {
        if (grammar[nodeIndex].find(symbol) == 0) {
            return nodeIndex;
        }
    }
    return -1;
}