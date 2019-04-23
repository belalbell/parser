#include <iostream>
#include "InputHandler.h"
#include "InputHandler.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include<bits/stdc++.h>
#include <map>
#include "parsing.h"

InputHandler *inputHandler = InputHandler::getInstance();


void print() {
    vector<string> temp;
    for (int i = 0; i < inputHandler->getLHSSize(); ++i) {
        temp = inputHandler->getRHSByIndex(i);
        cout << inputHandler->getLHSByIndex(i) << " -> ";
        for (int j = 0; j < temp.size(); ++j) {
            cout << temp[j] << " , ";
        }
        cout << endl;
    }
}
int main() {
    inputHandler->readFile("/home/belal/Downloads/Parser/Parser.txt");
    inputHandler->print();
    print();
    parsing* parsing = parsing::getInstance();
    parsing->first();
    parsing->follow();
    return 0;
}
