//
// Created by Cederic on 17/12/2022.
//

#include "Tetris_rocks.h"

void Tetris_rocks::step(bool newRock) {
    if(newRock){
        currentPos.first = cave.size() + 3;
        currentPos.second = 2;
    }

    switch (movements.at(movementCounter)) {
        case '<': {
            bool canMove = true;
            if (currentPos.second == 0) { canMove = false; }
            else if (currentPos.first < cave.size()) {
                for (uSmall i = 0; i < rocks.at(rockCounter).size() && canMove; ++i) {
                    if(i < cave.size()){
                        int offset = -1;
                        for (int j = 0; j < rocks.at(rockCounter).at(i).size() && offset == -1; ++j) {
                            offset = rocks.at(rockCounter).at(i).at(j) ? j: -1;
                        }
                        if(offset == -1){cout << "fack3" << endl;}
                        if(i + currentPos.first < cave.size()){canMove = !cave.at(i + currentPos.first).at(currentPos.second + offset - 1);}
                    }
                }
            }
            currentPos.second -= canMove;
            break;
        }
        case '>':{
            bool canMove = true;
            if (currentPos.second + rocks.at(rockCounter).front().size() >= maxWith) { canMove = false; }
            else if (currentPos.first < cave.size()){
                for (uSmall i = 0; i < rocks.at(rockCounter).size() && canMove; ++i) {
                    if(i < cave.size()){
                        int offset = -1;
                        for (int j = rocks.at(rockCounter).at(i).size() - 1; j >= 0 && offset == -1; --j) {
                            offset = rocks.at(rockCounter).at(i).at(j) ? j: -1;
                        }
                        if(offset == -1){cout << "fack2" << endl;}
                        if(i + currentPos.first < cave.size()){canMove = !cave.at(i + currentPos.first).at(currentPos.second + offset + 1);}
                    }
                }
            }
            currentPos.second += canMove;
            break;
        }
    }

    movementCounter = movementCounter < movements.size() - 1 ? movementCounter + 1: 0;

    bool canMove = true;
    if (currentPos.first == 0) { canMove = false; }
    if (currentPos.first <= cave.size()) {
        for (uSmall i = 0; i < rocks.at(rockCounter).front().size() && canMove; ++i) {
            int offset = -1;
            for (sSmall j = 0; j < rocks.at(rockCounter).size() && offset == -1; ++j) {
                offset = rocks.at(rockCounter).at(j).at(i) ? j: -1;
            }
            if(offset == -1){cout << "fack1" << endl;}
            if(offset + currentPos.first <= cave.size()){canMove = !cave.at(offset + currentPos.first - 1).at(currentPos.second + i);}
        }
    }

    if(canMove){
        currentPos.first --;
        step(false);
    }
    else{
        for (sSmall i = 0; i < rocks.at(rockCounter).size(); ++i) {
            if(i + currentPos.first == cave.size()){
                cave.emplace_back(maxWith, false);
            }

            for(sSmall j = 0; j < rocks.at(rockCounter).at(i).size(); ++j){
                if(rocks.at(rockCounter).at(i).at(j)){
                    cave.at(i + currentPos.first).at(j + currentPos.second) = rocks.at(rockCounter).at(i).at(j);
                }
            }
        }
        rockCounter = rockCounter < rocks.size() - 1 ? rockCounter + 1: 0;
    }
}

bool Tetris_rocks::checkCash(uint64_t TotalSteps, uint64_t currentSteps) {
    pair<sSmall, uint32_t> key{rockCounter, movementCounter};
    if(cashe.find(key) != cashe.end()){
        uint64_t oldSteps = cashe[key].first;
        uint32_t oldHeight = cashe[key].second;
        if((TotalSteps - currentSteps) % (currentSteps - oldSteps) == 0){
            solutionPart2 = cave.size() + (TotalSteps - currentSteps) / (currentSteps - oldSteps) * (cave.size() - oldHeight);
            return true;
        }
    }
    else{
        cashe[key] = {currentSteps, cave.size()};
    }
    return false;
}
