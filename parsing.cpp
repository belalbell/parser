//
// Created by belal.
//

#include "parsing.h"
using namespace std;

static parsing *insatnce = nullptr;

parsing *parsing::getInstance() {
    if (insatnce == nullptr) {
        insatnce = new parsing();
    }
    return insatnce;
}

