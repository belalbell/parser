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
            } else {
                string tmpStr = token.at(0);
                tmpStr.erase(remove_if(tmpStr.begin(), tmpStr.end(), ::isspace), tmpStr.end());
                if (lhs != tmpStr) {
                    vector<string> nonTerminals = firstMap[tmpStr];
                    for (int k = 0; k < nonTerminals.size(); ++k) {
                        tmp->push_back(nonTerminals.at(k));
                    }
                }
            }
        }
        firstMap[lhs] = *tmp;
    }
    cout << "first lhs done ";
    for (int l = 0; l < lhsSize; ++l) {
        vector<string> rhs = inputHandler->getRHSByIndex(l);
        for (int i = 0; i < rhs.size(); ++i) {
            vector<string> *tmp = new vector<string>();
            string rhsElement = rhs.at(i);
            //rhsElement.erase(remove_if(rhsElement.begin(), rhsElement.end(), ::isspace), rhsElement.end());
            vector<string> token = inputHandler->getRightToTokens(rhs.at(i));
            if (!(token.at(0)[0] >= 'A' && token.at(0)[0] <= 'Z')) {
                tmp->push_back(token.at(0));
                firstMap[rhsElement]=*tmp;
            } else{
                vector<string> takeFirst = firstMap[token.at(0)];
                for (int j = 0; j < takeFirst.size(); ++j) {
                    tmp->push_back(takeFirst.at(j));
                }
            }
            firstMap[rhsElement]=*tmp;
        }
    }
    cout << "first lhs done ";
}



