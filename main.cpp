#include <iostream>
#include "InputHandler.h"
#include "InputHandler.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include<bits/stdc++.h>
#include <map>
#include "parsing.h"
int main() {
    InputHandler *nonFiniteAutomata = InputHandler::getInstance();
    nonFiniteAutomata->readFile("/home/belal/Downloads/Parser/Parser.txt");
    nonFiniteAutomata->print();
    parsing* parsing = parsing::getInstance();
    parsing->first();
    return 0;
}