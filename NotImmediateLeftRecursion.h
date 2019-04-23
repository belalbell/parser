//
// Created by Sara on 22/04/2019.
//

#ifndef PARSER_NOTIMMEDIATELEFTRECURSION_H
#define PARSER_NOTIMMEDIATELEFTRECURSION_H

#include <string>
#include <vector>
#include "InputHandler.h"
#include "ImmediateLeftRecursion.h"

using namespace std;

class NotImmediateLeftRecursion {
private:
    InputHandler *inputHandler = InputHandler::getInstance();
    ImmediateLeftRecursion *immediateLeftRecursion = ImmediateLeftRecursion::getInstance();
public :
    static NotImmediateLeftRecursion *getInstance();

    void eliminateNotImmediateLeftRecursion();

    vector<string> substitute(string firstSymbol, vector<string> firstGrammar, vector<string> secondGrammar);

    int findSymbolExistenceIndex(string symbol, vector<string> grammar);

};


#endif //PARSER_NOTIMMEDIATELEFTRECURSION_H
