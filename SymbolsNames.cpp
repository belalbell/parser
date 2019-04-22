//
// Created by Sara on 22/04/2019.
//

#include "SymbolsNames.h"

string SymbolsNames::getASymbolName(string originalSymbol) {
    string newSymbol = originalSymbol + "'";
    vector<string> lhs = inputHandler->getLHS();
    for (int lhsIndex = 0; lhsIndex < lhs.size(); ++lhsIndex) {
        if (newSymbol == lhs[lhsIndex]) {
            newSymbol += "'";
        }
    }
    return newSymbol;
}