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

void NotImmediateLeftRecursion::elemenateNotImmediateLeftRecursion() {}

vector<string> NotImmediateLeftRecursion::subistitute(string firstSymbol, vector<string> firstGrammar,
                                                      vector<string> secondGrammar) {}

int NotImmediateLeftRecursion::findExistanceIndex(string symbol, vector<string> grammar) {}