//
// Created by Sara on 22/04/2019.
//

#include "ImmediateLeftRecursion.h"

void ImmediateLeftRecursion::eliminateImmediateLeftRecursion(string symbol, vector <string> splittedGrammar) {}

bool ImmediateLeftRecursion::isImmediateLeftRecursion(string symbol, vector <string> splittedGrammar) {
    for (int nodeIndex = 0; nodeIndex < splittedGrammar.size(); ++nodeIndex) {
        if (splittedGrammar[nodeIndex].find(symbol) != string::npos) {
            return true;
        }
    }
    return false;
}