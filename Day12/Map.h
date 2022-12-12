//
// Created by icas on 12/12/22.
//

#ifndef ADVENT_OF_CODE_MAP_H
#define ADVENT_OF_CODE_MAP_H

#include <fstream>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <list>

using namespace std;

class Map {
public:
    Map(const string& inputFile);

    uint32_t getSteps();
    uint32_t getTrail();

private:
    struct newStep{
        uint32_t distanceToFinish;
        uint32_t distanceToStart;
        uint32_t totalDistance;
        pair<int8_t, int8_t> pos;
        char height;

        newStep(pair<uint8_t, uint8_t> posTmp, uint32_t disToFin, uint32_t disToStart, char curHeight){
            pos = posTmp;
            distanceToFinish = disToFin;
            distanceToStart = disToStart;
            totalDistance = disToStart + disToFin;
            height = curHeight;
        }
    };

    struct find_pos : std::unary_function<newStep, bool> {
        pair<int8_t, int8_t> pos;
        explicit find_pos(const pair<int8_t, int8_t> pos):pos(pos) { }
        bool operator()(newStep const& nS) const {
            return nS.pos == pos;
        }
    };

    void calculatePath();

    static uint32_t getDistance(pair<uint8_t, uint8_t> pos1, pair<uint8_t, uint8_t> pos2){return (uint32_t) pow(pos1.first - pos2.first, 2) + (uint32_t) pow(pos1.second - pos2.second, 2);}
    static bool compareNewSteps(const newStep &a, const newStep &b){return a.totalDistance > b.totalDistance;}

    uint32_t pathLenght;

    pair<uint8_t, uint8_t> start;
    pair<uint8_t, uint8_t> end;
    vector<vector<char>> map;
    vector<pair<uint8_t, uint8_t>> startHike;
};


#endif //ADVENT_OF_CODE_MAP_H
