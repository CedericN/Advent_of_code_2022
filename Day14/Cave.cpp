//
// Created by icas on 12/14/22.
//

#include "Cave.h"

Cave::Cave(const string &inputFile, const pair<uint16_t,uint16_t> sandHole): sandStart(sandHole) {
    ifstream InputFileStream(inputFile);
    string line;

    xOffset = UINT16_MAX;
    top = {0, 0};

    vector<vector<pair<uint16_t, uint16_t>>> rocks;

    while (getline(InputFileStream, line)) {
        rocks.emplace_back(getRocks(line));
    }

    makeCave(rocks);
    caveCopy = cave;
//    cout << "input done" << endl;
}

uint64_t Cave::fillCave(bool endlessBottom) {
    cave = caveCopy;
    if(!endlessBottom){
        cave.emplace_back(top.first - xOffset + 1, air);
        cave.emplace_back(top.first - xOffset + 1, rock);
    }

    bool noVoid = true;

    uint64_t counter = 0;

    while(noVoid){
        noVoid = sandStep(endlessBottom);
//        printCave();
        counter += noVoid;
    }

    if(!endlessBottom){
        counter ++;
        cave.at(sandStart.second).at(sandStart.first - xOffset) = sand;
    }

//    printCave();
    return counter;
}

vector<pair<uint16_t, uint16_t>> Cave::getRocks(string &rockPath) {
    vector<pair<uint16_t, uint16_t>> returnVector;
    string rockLine;

    uint64_t pos = rockPath.find(" -> ");


    while(pos != string::npos){
        rockLine = rockPath.substr(0, pos);
//        cout << rockLine << endl;
        uint64_t pos1 = rockLine.find(',');
        if(pos1 == string::npos){cout << "something is not write you idiot" << endl; break;}
        returnVector.emplace_back(stoi(rockLine.substr(0, pos1)), stoi(rockLine.substr(pos1 + 1)));
        if(returnVector.back().first < xOffset){xOffset = returnVector.back().first;}
        else if(returnVector.back().first + 1 > top.first){top.first = returnVector.back().first;}
        else if(returnVector.back().second > top.second){top.second = returnVector.back().second;}
        rockPath = rockPath.substr(pos + 4);
        pos = rockPath.find(" -> ");
    }
    rockLine = rockPath.substr(0, pos);
    pos = rockLine.find(',');
    if(pos == string::npos){cout << "something is not write you idiot" << endl;}
    returnVector.emplace_back(stoi(rockLine.substr(0, pos)), stoi(rockLine.substr(pos + 1)));
    if(returnVector.back().first < xOffset){xOffset = returnVector.back().first;}
    else if(returnVector.back().first > top.first){top.first = returnVector.back().first;}
    else if(returnVector.back().second > top.second){top.second = returnVector.back().second;}

    return returnVector;
}

void Cave::makeCave(const vector<vector<pair<uint16_t, uint16_t>>>& rocks) {
    for (uint16_t i = 0; i < top.second + 1; ++i) {
        cave.emplace_back(top.first - xOffset + 1, air);
    }

    for(auto &i: rocks){
        for (uint32_t j = 0; j < i.size() - 1; ++j) {
            if(i.at(j).first == i.at(j + 1).first){
                uint16_t yMin = i.at(j).second < i.at(j + 1).second ? i.at(j).second : i.at(j + 1).second;
                uint16_t yMax = i.at(j).second < i.at(j + 1).second ? i.at(j + 1).second : i.at(j).second;
                uint16_t x = i.at(j).first - xOffset;
//                cout << "x: " << x << "\tmin y: " << yMin << "\tmax y: " << yMax << endl;
                for(uint16_t y = yMin; y <= yMax; ++y){
                    cave.at(y).at(x) = rock;
                }
            }
            else if(i.at(j).second == i.at(j + 1).second){
                uint16_t xMin = i.at(j).first < i.at(j + 1).first ? i.at(j).first : i.at(j + 1).first;
                uint16_t xMax = i.at(j).first < i.at(j + 1).first ? i.at(j + 1).first : i.at(j).first;

                xMin -= xOffset;
                xMax -= xOffset;

                uint16_t y = i.at(j).second;
//                cout << "x: " << y << "\tmin y: " << xMin << "\tmax y: " << xMax << endl;
                for(uint16_t x = xMin; x <= xMax; ++x){
                    cave.at(y).at(x) = rock;
                }
            }
        }
    }
}

bool Cave::sandStep(bool endlessBottom, pair<int32_t,int32_t> currentPos) {
    if(currentPos == pair<int32_t, int32_t>{UINT16_MAX, UINT16_MAX}){
        currentPos = sandStart;
        currentPos.first -= xOffset;
    }

//    cout << "i'm here: " << currentPos.first << "," << currentPos.second << endl;
    if(!endlessBottom){
        if (currentPos.first == 0){
            for (uint32_t i = 0; i < cave.size(); ++i) {
                cave.at(i).insert(cave.at(i).begin(), i == cave.size() - 1 ? rock : air);
            }
            xOffset --;
            currentPos.first ++;
        }
        if (currentPos.first == cave.at(currentPos.second).size() - 2){
            for (uint32_t i = 0; i < cave.size(); ++i) {
                cave.at(i).push_back(i == cave.size() - 1 ? rock : air);
            }
        }
    }

    bool returnValue = false;

    if(currentPos.second < cave.size() - 2 && cave.at(currentPos.second + 1).at(currentPos.first) == air){
        returnValue = sandStep(endlessBottom, {currentPos.first, currentPos.second + 1});
    }
    else if(currentPos.second < cave.size() - 1 && currentPos.first > 0 && cave.at(currentPos.second + 1).at(currentPos.first - 1) == air){
        returnValue = sandStep(endlessBottom, {currentPos.first - 1, currentPos.second + 1});
    }
    else if(currentPos.second < cave.size() - 1 && currentPos.first < cave.at(currentPos.second).size() - 2 && cave.at(currentPos.second + 1).at(currentPos.first + 1) == air){
        returnValue = sandStep(endlessBottom, {currentPos.first + 1, currentPos.second + 1});
    }
    else if(currentPos.second > 0 && currentPos.second < cave.size() - 1 && currentPos.first > 0 && currentPos.first < cave.at(currentPos.second).size() - 1){
        returnValue = true;
        cave.at(currentPos.second).at(currentPos.first) = sand;
    }

    return returnValue;
}
