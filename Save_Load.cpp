//
// Created by mazen on 22/04/19.
//

#include "Save_Load.h"
#include "InputHandler.h"
#include <bits/stdc++.h>
using namespace std;

static Save_Load *insatnce = nullptr;

Save_Load *Save_Load::getInstance() {
    if (insatnce == nullptr) {
        insatnce = new Save_Load();
    }
    return insatnce;
}

void Save_Load::save(std::vector<std::string> Terminals, std::vector<std::string> LHSinputs, std::vector<std::vector<std::string>> parsingTable)
{
    ofstream file;
    file.open("parsing_table.txt");

    // inserting the terminals row
    for(string s : Terminals)
    {
        file << "\t"<< s;
    }
    file << "\n\n";

    // inserting the rows
    for(int i = 0; i < LHSinputs.size(); i++)
        {
            file << LHSinputs.at(i) << "\t";
            for(string s : parsingTable.at(i))
            {
                file << s <<"\t";
            }
            file<<"\n";
        }

}



void Save_Load::Load(std::vector<std::vector<std::string>> *parsingTable, std::vector<std::string> *Terminals, std::vector<std::string> *LHSinputs)
{
    Terminals->clear();
    LHSinputs->clear();
    parsingTable->clear();

    ifstream file("parsing_table.txt");
    string line;
    bool  firstLine = true;

    while(!file.eof())
    {
        std::getline(file, line);

        istringstream iss(line);
        vector<string> entries((istream_iterator<string>(iss)), istream_iterator<string>());

        if(!entries.empty())
        {
            if(firstLine)
            {
                firstLine = false;
                for(string s : entries) Terminals->push_back(s);
                continue;
            }


            LHSinputs->push_back(entries.at(0));
            vector<string> tableRow;

            for(int i = 1; i < entries.size(); i++)
            {
                tableRow.push_back(entries.at(i));
            }

            parsingTable->push_back(tableRow);
        }

    }

}
