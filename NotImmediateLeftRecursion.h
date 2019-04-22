//
// Created by Sara on 22/04/2019.
//

#ifndef PARSER_NOTIMMEDIATELEFTRECURSION_H
#define PARSER_NOTIMMEDIATELEFTRECURSION_H

#include <string>
#include <vector>

using namespace std;

class NotImmediateLeftRecursion {
public :
    static NotImmediateLeftRecursion* getInstance();

    void elemenateNotImmediateLeftRecursion();

    vector<string> subistitute(string firstSymbol, vector<string> firstGrammar, vector<string> secondGrammar);

    int findExistanceIndex(string symbol, vector<string> grammar);

};


#endif //PARSER_NOTIMMEDIATELEFTRECURSION_H
