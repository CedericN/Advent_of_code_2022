//
// Created by icas on 12/9/22.
//

#ifndef ADVENT_OF_CODE_BRIDGE_H
#define ADVENT_OF_CODE_BRIDGE_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <set>

using namespace std;

class Bridge {
public:
    explicit Bridge(const string& inputFile);

    uint32_t getTailVisits(uint8_t knots = 1);
private:

    void updateTailPosition(char direction, uint8_t amount);

    vector<pair<char, uint8_t>> commands;
    pair<int32_t, int32_t> posH;
    vector<vector<pair<int32_t, int32_t>>> posT;
};


#endif //ADVENT_OF_CODE_BRIDGE_H
