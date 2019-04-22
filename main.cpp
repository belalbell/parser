#include <iostream>
#include "InputHandler.h"
#include "InputHandler.h"
#include "Save_Load.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include<bits/stdc++.h>
#include <map>
int main() {
//    InputHandler *nonFiniteAutomata = InputHandler::getInstance();
//    nonFiniteAutomata->readFile("/home/sami/CLionProjects/Parser/Parser.txt");
//    nonFiniteAutomata->print();

    Save_Load *sl  =Save_Load::getInstance();

    vector<string> lhs, terminals, tmp;
    vector<vector<string>> table;

//    lhs.emplace_back("lhs");
//    lhs.emplace_back("lhs");
//    lhs.emplace_back("lhs");
//    lhs.emplace_back("lhs");
//    lhs.emplace_back("lhs");
//
//    terminals.emplace_back("term");
//    terminals.emplace_back("term");
//    terminals.emplace_back("term");
//    terminals.emplace_back("term");
//    terminals.emplace_back("term");
//
//    tmp.emplace_back("val");
//    tmp.emplace_back("val");
//    tmp.emplace_back("val");
//    tmp.emplace_back("val");
//    tmp.emplace_back("val");
//
//
//    table.emplace_back(tmp);
//    table.emplace_back(tmp);
//    table.emplace_back(tmp);
//    table.emplace_back(tmp);
//    table.emplace_back(tmp);
//
//    sl->save(terminals, lhs, table);


    sl->Load(&table, &terminals, &lhs);

    for(string x : terminals) cout << x <<endl;

    cout<<"\n\n\n\n\n\n\n";

    for(string x : lhs) cout << x << endl;
    cout<<"\n\n\n\n\n\n\n";

    for(vector<string> y : table)
    {
        for(string x : y) cout << x << " ";
        cout<<"\n";


    }



    cout<< terminals.size() <<endl;
    cout<< lhs.size() <<endl;
    cout<< table.size() <<endl;


    return 0;
}