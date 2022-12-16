//
// Created by icas on 12/16/22.
//

#ifndef ADVENT_OF_CODE_VALVES_H
#define ADVENT_OF_CODE_VALVES_H

#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Valves {
public:
    struct valve{
        string name;
        uint8_t flowRate;
        vector<string> leadToValves;
    };

    Valves(const string& inputFile);

private:
    valve getValve(string basicString);

    vector<valve> valves;

};


#endif //ADVENT_OF_CODE_VALVES_H
