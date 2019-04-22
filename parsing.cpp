//
// Created by belal.
//

#include <algorithm>
#include "parsing.h"

using namespace std;

static parsing *insatnce = nullptr;

parsing *parsing::getInstance() {
    if (insatnce == nullptr) {
        insatnce = new parsing();
    }
    return insatnce;
}

void parsing::first() {
    int lhsSize = inputHandler->getLHSSize();
    ///first lhs
    for (int i = lhsSize - 1; i >= 0; --i) {
        vector<string> rhs = inputHandler->getRHSByIndex(i);
        string lhs = inputHandler->getLHSByIndex(i);
        lhs.erase(remove_if(lhs.begin(), lhs.end(), ::isspace), lhs.end());
        vector<string> *tmp = new vector<string>();
        for (int j = 0; j < rhs.size(); ++j) {
            vector<string> token = inputHandler->getRightToTokens(rhs.at(j));
            if (!(token.at(0)[0] >= 'A' && token.at(0)[0] <= 'Z')) {
                tmp->push_back(token.at(0));
            } else{
                string tmpStr = token.at(0);
                tmpStr.erase(remove_if(tmpStr.begin(), tmpStr.end(), ::isspace), tmpStr.end());
                if (lhs!=tmpStr) {
                    vector<string> nonTerminals = firstMap[tmpStr];
                    for (int k = 0; k < nonTerminals.size(); ++k) {
                        tmp->push_back(nonTerminals.at(k));
                    }
                }
            }
        }
        firstMap[lhs]=*tmp;
    }
    cout<<"first lhs done ";
}

