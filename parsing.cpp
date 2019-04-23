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
    cout << "first lhs done " << endl;
    for (int l = 0; l < lhsSize; ++l) {
        vector<string> rhs = inputHandler->getRHSByIndex(l);
        for (int i = 0; i < rhs.size(); ++i) {
            vector<string> *tmp = new vector<string>();
            string rhsElement = rhs.at(i);
            rhsElement.erase(remove_if(rhsElement.begin(), rhsElement.end(), ::isspace), rhsElement.end());
            vector<string> token = inputHandler->getRightToTokens(rhs.at(i));
            if (!(token.at(0)[0] >= 'A' && token.at(0)[0] <= 'Z')) {
                tmp->push_back(token.at(0));
                firstMap[rhsElement] = *tmp;
            } else {
                vector<string> takeFirst = firstMap[token.at(0)];
                for (int j = 0; j < takeFirst.size(); ++j) {
                    tmp->push_back(takeFirst.at(j));
                }
            }
            firstMap[rhsElement] = *tmp;
        }
    }
    cout << "first lhs done " << endl;
}

void parsing::follow() {
    int lhsSize = inputHandler->getLHSSize();
    for (int i = 0; i < lhsSize; ++i) {
        string lhs = inputHandler->getLHSByIndex(i);
        vector<string> *tmp = new vector<string>();
        if (i == 0) {
            tmp->push_back("$");
        }
        lhs.erase(remove_if(lhs.begin(), lhs.end(), ::isspace), lhs.end());
        for (int j = 0; j < lhsSize; ++j) {
            vector<string> rhs = inputHandler->getRHSByIndex(j);
            for (int k = 0; k < rhs.size(); ++k) {
                vector<string> token = inputHandler->getRightToTokens(rhs.at(k));
                for (int l = 0; l < token.size(); ++l) {
                    string element = token.at(l);
                    element.erase(remove_if(element.begin(), element.end(), ::isspace), element.end());
                    if (lhs == element) {
                        if (l == token.size() - 1) {
                            string str = inputHandler->getLHSByIndex(j);
                            str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());
                            vector<string> clone = followMap[str];
                            for (int m = 0; m < clone.size(); ++m) {
                                tmp->push_back(clone.at(m));
                            }
                        } else if (token.at(l + 1) != " ") {
                            if (token.at(l + 1)[0] >= 'A' && token.at(l + 1)[0] <= 'Z') {
                                string str = token.at(l + 1);
                                str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());
                                vector<string> clone = firstMap[str];
                                for (int m = 0; m < clone.size(); ++m) {
                                    if (clone.at(m) == "\\L") {
                                        vector<string> clonetmp = followMap[str];
                                        for (int n = 0; n < clonetmp.size(); ++n) {
                                            tmp->push_back(clonetmp.at(n));
                                        }
                                    } else {
                                        tmp->push_back(clone.at(m));
                                    }
                                }
                            } else if (token.at(l + 1) == "") {
                                string str = inputHandler->getLHSByIndex(j);
                                str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());
                                vector<string> clone = followMap[str];
                                for (int m = 0; m < clone.size(); ++m) {
                                    tmp->push_back(clone.at(m));
                                }
                            } else {
                                tmp->push_back(token.at(l + 1));
                            }
                        }
                    }
                }
            }
        }
        followMap[lhs] = *tmp;
    }
    cout << "follow done" << endl;
}

void parsing::initalizeTable() {
    vector<string> lhs = inputHandler->getLHSinputs();
    vector<string> terminals = inputHandler->getTerminals();
    bool flag = true;
    for (int i = 0; i <lhs.size(); ++i) {
        vector<string>*tmp =new vector<string>();
        lhsIndex[lhs.at(i)]=i;
        for (int j = 0; j < terminals.size(); ++j) {
            if (flag) {
                terminalIndex[terminals.at(j)] = j;
            }
            tmp->push_back("error");
        }
        flag=false;
        parsingTable.push_back(*tmp);
    }
    terminalIndex["$"]=terminals.size();
}

void parsing::constractTable() {
    vector<string> lhs = inputHandler->getLHSinputs();
    for (int i = 0; i < lhs.size(); ++i) {

    }
}
