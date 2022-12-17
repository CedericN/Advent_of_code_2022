//
// Created by Cederic on 17/12/2022.
//

#ifndef ADVENT_OF_CODE_TETRIS_ROCKS_H
#define ADVENT_OF_CODE_TETRIS_ROCKS_H

#include <string>
#include <vector>
#include <iostream>
#include <map>

using uSmall = uint32_t;
using sSmall = int32_t;
using namespace std;

class Tetris_rocks {
public:
    explicit Tetris_rocks(const string &inputString):movements(inputString), movementCounter(0), rockCounter(0){}

    uint64_t playTetris(uint64_t steps){
        cave.clear();
        for (uint64_t i = 0; i < steps; ++i) {
            if(i % 100000)
            step();
        }
//        printCave();
        return cave.size();
    }

    uint64_t playExtremeTetris(uint64_t steps){
        cave.clear();
        movementCounter = 0;
        rockCounter = 0;
        for (uint64_t i = 0; i < steps && !checkCash(steps, i); ++i) {
            step();
        }
//        printCave();
        return solutionPart2;
    }

private:
    void step(bool newRock = true);

    bool checkCash(uint64_t TotalSteps, uint64_t currentSteps);

    void printCave(){
        cout << cave.size() << endl;
        for (int32_t i = cave.size() - 1; i > -1; --i) {
            cout << '|';
            for (bool j: cave.at(i)) {
                cout << (j ? '#' : '.');
            }
            cout << '|' << endl;
        }
        cout << "+-------+" << endl;
    }

    uint64_t solutionPart2;
    uint32_t movementCounter;
    uSmall rockCounter;
    vector<vector<bool>> cave;
    pair<uint32_t , uSmall> currentPos;

    map<pair<sSmall, uint32_t>, pair<uint64_t, uint64_t>> cashe;

    const string movements;
    const uSmall maxWith = 7;
    const vector<vector<vector<bool>>> rocks = {
            {{true, true, true, true}},
            {{false, true, false}, {true, true, true}, {false, true, false}},
            {{true, true, true}, {false, false, true}, {false, false, true}},
            {{true}, {true}, {true}, {true}},
            {{true, true}, {true, true}}
    };
};


#endif //ADVENT_OF_CODE_TETRIS_ROCKS_H
