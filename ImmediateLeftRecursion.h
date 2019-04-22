//
// Created by Sara on 22/04/2019.
//

#ifndef PARSER_IMMEDIATELEFTRECURSION_H
#define PARSER_IMMEDIATELEFTRECURSION_H

#include <string>
#include <vector>
#include "InputHandler.h"

using namespace std;

class ImmediateLeftRecursion {
private:
    InputHandler* inputHandler = InputHandler::getInstance();
public:
    static ImmediateLeftRecursion* getInstance();

    void eliminateImmediateLeftRecursion(string symbol, vector <string> splittedGrammar);

    bool isImmediateLeftRecursion(string symbol, vector <string> splittedGrammar);
};


#endif //PARSER_IMMEDIATELEFTRECURSION_H
