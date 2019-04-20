#include <iostream>
#include "InputHandler.h"
#include "InputHandler.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include<bits/stdc++.h>
#include <map>
int main() {
    InputHandler *nonFiniteAutomata = InputHandler::getInstance();
    nonFiniteAutomata->readFile("/home/sami/CLionProjects/Parser/Parser.txt");
    nonFiniteAutomata->print();

    return 0;
}