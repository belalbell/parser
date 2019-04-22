//
// Created by Sara on 22/04/2019.
//

#include "SymbolsNames.h"

static SymbolsNames *instance = nullptr;

SymbolsNames *SymbolsNames::getInstance() {
    if (instance == nullptr) {
        instance = new SymbolsNames();
    }
    return instance;
}


string SymbolsNames::getASymbolName(string originalSymbol) {
    string newSymbol = originalSymbol + "'";
    for (int lhsIndex = 0; lhsIndex < inputHandler->getLHS().size(); ++lhsIndex) {
        if (newSymbol == inputHandler->getLHSByIndex(lhsIndex)) {
            newSymbol += "'";
        }
    }
    return newSymbol;
}