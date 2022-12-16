//
// Created by icas on 12/16/22.
//

#ifndef ADVENT_OF_CODE_VALVES_H
#define ADVENT_OF_CODE_VALVES_H

#include <vector>
#include <iostream>
#include <fstream>
#include <map>
#include <cassert>

using namespace std;

class Valves {
public:
    struct valve{
        string name;
        uint8_t flowRate;
        vector<string> leadToValves;
        vector<uint8_t> leadToValvesIndex;
    };

    Valves(const string& inputFile);

    uint32_t getPressure(bool multiplePersons, uint8_t startTime_tmp){
        startTime = startTime_tmp;
        return searchPath(0,0,startTime, multiplePersons);
    }

private:
    static valve getValve(string basicString);

    uint32_t searchPath(uint8_t currentValve, uint32_t openValves, uint8_t timeLeft, bool otherPersons);

    vector<valve> valves;
    vector<int64_t> scores;
    uint8_t startTime;
};


#endif //ADVENT_OF_CODE_VALVES_H
