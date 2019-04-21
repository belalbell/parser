//
// Created by Sara on 22/04/2019.
//

#ifndef PARSER_IMMEDIATELEFTRECURSION_H
#define PARSER_IMMEDIATELEFTRECURSION_H

#include <string>
#include <vector>

using namespace std;

class ImmediateLeftRecursion {
public:
    void eliminateImmediateLeftRecursion(string symbol, vector <string> splittedGrammar);

    bool isImmediateLeftRecursion(string symbol, vector <string> splittedGrammar);
};


#endif //PARSER_IMMEDIATELEFTRECURSION_H
