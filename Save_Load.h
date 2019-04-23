//
// Created by mazen on 22/04/19.
//
#include <bits/stdc++.h>
#ifndef PARSER_SAVE_LOAD_H
#define PARSER_SAVE_LOAD_H


class Save_Load {
public:

    void save(std::vector<std::string> Terminals, std::vector<std::string> LHSinputs, std::vector<std::vector<std::string>> parsingTable);
    void Load(std::vector<std::vector<std::string>>* parsingTable, std::vector<std::string> *Terminals, std::vector<std::string> *LHSinputs);
    static Save_Load* getInstance();
private:



};


#endif //PARSER_SAVE_LOAD_H
