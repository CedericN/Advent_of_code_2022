//
// Created by icas on 12/14/22.
//

#ifndef ADVENT_OF_CODE_CAVE_H
#define ADVENT_OF_CODE_CAVE_H

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Cave {
public:
    enum Tile{
        air,
        rock,
        sand,
    };

    explicit Cave(const string &inputFile, pair<uint16_t,uint16_t> sandHole = {500, 0});

    uint64_t fillCave(bool endlessBottom = true);

    void printCave(){
        for (auto &i: cave) {
            for (auto &j: i) {
                switch (j) {
                    case air:
                        cout << '.';
                        break;
                    case rock:
                        cout << '#';
                        break;
                    case sand:
                        cout << 'o';
                        break;
                }
            }
            cout << endl;
        }
        cout << endl;
    }

private:
    vector<pair<uint16_t, uint16_t>> getRocks(string &rockPath);
    void makeCave(const vector<vector<pair<uint16_t, uint16_t>>>& rocks);
    bool sandStep(bool endlessBottom, pair<int32_t,int32_t> currentPos = {UINT16_MAX,UINT16_MAX});


    vector<vector<Tile>> cave;
    vector<vector<Tile>> caveCopy;
    uint16_t xOffset;
    pair<uint16_t,uint16_t> top;
    const pair<uint16_t,uint16_t> sandStart;

};


#endif //ADVENT_OF_CODE_CAVE_H
