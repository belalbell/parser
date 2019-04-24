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
        auto search = firstMap.find(lhs);
        if (search != firstMap.end()) {
            continue;
        }
        vector<string> *tmp = new vector<string>();
        for (int j = 0; j < rhs.size(); ++j) {
            vector<string> token = inputHandler->getRightToTokens(rhs.at(j));
            if (rhs.at(j) == "\\L") {
                tmp->push_back("\\L");
            } else if (!(token.at(0)[0] >= 'A' && token.at(0)[0] <= 'Z')) {
                tmp->push_back(token.at(0));
            } else {
                string tmpStr = token.at(0);
                tmpStr.erase(remove_if(tmpStr.begin(), tmpStr.end(), ::isspace), tmpStr.end());
                auto search = firstMap.find(tmpStr);
                if (search == firstMap.end()) {
                    firstFirst(tmpStr);
                }
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

void parsing::firstFirst(string lhs) {
    int index = 0;
    int lhsSize = inputHandler->getLHSSize();
    for (int i = 0; i < lhsSize; ++i) {
        string tmp = inputHandler->getLHSByIndex(i);
        tmp.erase(remove_if(tmp.begin(), tmp.end(), ::isspace), tmp.end());
        if (lhs == tmp) {
            index = i;
            break;
        }

    }
    vector<string> rhs = inputHandler->getRHSByIndex(index);
    lhs.erase(remove_if(lhs.begin(), lhs.end(), ::isspace), lhs.end());
    vector<string> *tmp = new vector<string>();
    for (int j = 0; j < rhs.size(); ++j) {
        vector<string> token = inputHandler->getRightToTokens(rhs.at(j));
        if (rhs.at(j) == "\\L") {
            tmp->push_back("\\L");
        } else if (!(token.at(0)[0] >= 'A' && token.at(0)[0] <= 'Z')) {
            tmp->push_back(token.at(0));
        } else {
            string tmpStr = token.at(0);
            tmpStr.erase(remove_if(tmpStr.begin(), tmpStr.end(), ::isspace), tmpStr.end());
            auto search = firstMap.find(tmpStr);
            if (search == firstMap.end()) {
                firstFirst(tmpStr);
            }
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

bool findStr(vector<string> tmp, string str) {
    for (int i = 0; i < tmp.size(); ++i) {
        if (str == tmp.at(i))
            return true;
    }
    return false;
}


void parsing::follow() {
    int lhsSize = inputHandler->getLHSSize();
    for (int i = 0; i < lhsSize; ++i) {
        string lhs = inputHandler->getLHSByIndex(i);
        lhs.erase(remove_if(lhs.begin(), lhs.end(), ::isspace), lhs.end());
        vector<string> *tmp = new vector<string>();
        if (i == 0) {
            tmp->push_back("$");
        }
        for (int j = 0; j < lhsSize; ++j) {
//            if (lhs == "TERM'" && j == 10)
//                cout << "hhhhhhhhhhhhhh";
            vector<string> rhs = inputHandler->getRHSByIndex(j);
            for (int k = 0; k < rhs.size(); ++k) {
                vector<string> token = inputHandler->getRightToTokens(rhs.at(k));
                for (int l = 0; l < token.size(); ++l) {
                    string element = token.at(l);
                    element.erase(remove_if(element.begin(), element.end(), ::isspace), element.end());
                    if (element == "")
                        continue;
                    if (lhs == element) {
                        if (l == token.size() - 1) {
                            string str = inputHandler->getLHSByIndex(j);
                            str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());
                            vector<string> clone = followMap[str];
                            if (clone.size() == 0) {
                                remainingFollow.push_back(lhs);
                                cloneFollow.push_back(str);
                            }
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
                                        if (clonetmp.size() == 0) {
                                            remainingFollow.push_back(lhs);
                                            cloneFollow.push_back(str);
                                        }
                                        for (int n = 0; n < clonetmp.size(); ++n) {
                                            if (!findStr(*tmp, clonetmp.at(n)))
                                                tmp->push_back(clonetmp.at(n));
                                        }
                                    } else {
                                        if (!findStr(*tmp, clone.at(m)))
                                            tmp->push_back(clone.at(m));
                                    }
                                }
                            } else if (token.at(l + 1) == "") {
                                string str = inputHandler->getLHSByIndex(j);
                                str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());
                                vector<string> clone = followMap[str];
//                                if (clone.size() == 0) {
//                                    remainingFollow.push_back(lhs);
//                                    cloneFollow.push_back(str);
//                                }
                                for (int m = 0; m < clone.size(); ++m) {
                                    if (!findStr(*tmp, clone.at(m)))
                                        tmp->push_back(clone.at(m));
                                }
                            } else {
                                if (!findStr(*tmp, token.at(l + 1)))
                                    tmp->push_back(token.at(l + 1));
                            }
                        }
                    }
                }
            }
        }
        followMap[lhs] = *tmp;
    }
    for (int i1 = 0; i1 < remainingFollow.size(); ++i1) {
        vector<string> *receieve = &followMap[remainingFollow.at(i1)];
        string ss =cloneFollow.at(i1);
        if (ss[ss.size()-1]=='\''||ss[ss.size()-1]=='&'){
            ss=ss.substr(0,ss.size()-1);
        }
        vector<string> *sentter = &followMap[ss];
        for (int i = 0; i < sentter->size(); ++i) {
            receieve->push_back(sentter->at(i));
        }
    }
    cout << "follow done" << endl;
}

void parsing::followFollow(string lhs) {

}

void parsing::initalizeTable() {
    vector<string> lhs = inputHandler->getLHSinputs();
    vector<string> terminals = inputHandler->getTerminals();
    bool flag = true;
    for (int i = 0; i < lhs.size(); ++i) {
        vector<string> *tmp = new vector<string>();
        string str = lhs.at(i);
        str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());
        lhsIndex[str] = i;
        for (int j = 0; j <= terminals.size(); ++j) {
            if (flag && j < terminals.size()) {
                terminalIndex[terminals.at(j)] = j;
            }
            tmp->push_back("error");
        }
        flag = false;
        parsingTable.push_back(*tmp);
    }
    terminalIndex["$"] = terminals.size();
    cout << "init table done" << endl;
}

void parsing::constractTable() {
    vector<string> lhs = inputHandler->getLHSinputs();
    for (int i = 0; i < lhs.size(); ++i) {
        vector<string> rhs = inputHandler->getRHSByIndex(i);
        for (int j = 0; j < rhs.size(); ++j) {
            string key = rhs.at(j);
            key.erase(remove_if(key.begin(), key.end(), ::isspace), key.end());
            vector<string> first = firstMap[key];
            for (int k = 0; k < first.size(); ++k) {
//                if (first.at(k) != "error")
//                    continue;
                if (first.at(k) == "\\L") {
                    string tmp = lhs.at(i);
                    tmp.erase(remove_if(tmp.begin(), tmp.end(), ::isspace), tmp.end());
                    vector<string> follow = followMap[tmp];
                    for (int l = 0; l < follow.size(); ++l) {
                        int row = i;
                        int col = terminalIndex[follow.at(l)];
                        parsingTable.at(row).at(col) = "\\L";
                    }
                } else {
                    int row = i;
                    int col = terminalIndex[first.at(k)];
                    parsingTable.at(row).at(col) = rhs.at(j);
                }
            }
        }
    }
    cout << "table done" << endl;
}

int parsing::getLhsIndex(string lhs) {
    return lhsIndex[lhs];
}

int parsing::getTerminalIndex(string terminal) {
    return terminalIndex[terminal];
}

map<string, int> parsing::getterminalIndex() {
    return terminalIndex;
}

map<string, int> parsing::getlhsIndex() {
    return lhsIndex;
}

vector<vector<string>> parsing::getParsingTable() {
    return parsingTable;
}

map<string, vector<string>> parsing::getFollowMap() {
    return followMap;
}
