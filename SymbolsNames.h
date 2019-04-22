//
// Created by Sara on 22/04/2019.
//

#ifndef PARSER_SYMBOLSNAMES_H
#define PARSER_SYMBOLSNAMES_H


#include "InputHandler.h"
using namespace std;
class SymbolsNames {
private:
    InputHandler *inputHandler = InputHandler::getInstance();

public:
    static SymbolsNames *getInstance();
    string getASymbolName(string originalSymbol);

};


#endif //PARSER_SYMBOLSNAMES_H
