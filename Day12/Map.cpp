//
// Created by icas on 12/12/22.
//

#include "Map.h"

Map::Map(const string &inputFile) {
    ifstream InputFileStream(inputFile);
    string line;

    pathLenght = UINT32_MAX;

    while(getline(InputFileStream, line)){
        vector<char>row;
        for (auto &i: line) {
            if(i == 'S'){
                start.first = row.size();
                start.second = map.size();
                i = 'a';
            }
            else if(i == 'E'){
                end.first = row.size();
                end.second = map.size();
                i = 'z';
            }
            else if(i == 'a'){
                startHike.emplace_back(row.size(), map.size());
            }

            row.push_back(i);
        }
        map.push_back(row);
    }
}

uint32_t Map::getSteps() {
    calculatePath();
    return pathLenght;
}

uint32_t Map::getTrail() {
    uint32_t returnValue = UINT32_MAX;
    cout << "calculating " << startHike.size() << " different paths";
    uint16_t counter = 1;
    for (auto &i: startHike) {
        start = i;
        pathLenght = UINT32_MAX;
        calculatePath();
        if(pathLenght < returnValue){ returnValue = pathLenght;}
        if(pathLenght != UINT32_MAX){
            cout << "\rpart 2: " << "path " << (int) counter << " has a length of " << pathLenght << "     ";
        }
        counter ++;
    }
    cout << "\rpart 2: " << returnValue << "                           " << endl;
    return returnValue;
}

void Map::calculatePath() {
    vector<uint32_t> visited (map.size(), 0);
    vector<vector<uint32_t>> distanceMap;

    for (int i = 0; i < map.size(); ++i) {
        distanceMap.emplace_back(map.front().size(), UINT32_MAX);
    }

    distanceMap.at(start.second).at(start.first) = 0;

    list<newStep> newSteps;

    newSteps.emplace_back(start, 0,0, map.at(start.second).at(start.first));

    vector<int8_t> mvX {1,0,-1,0};
    vector<int8_t> mvY {0,1,0,-1};

    while(!newSteps.empty()){
        pair<uint8_t, uint8_t> pos = newSteps.front().pos;

        for (uint8_t i = 0; i < 4; ++i) {
            pair<int8_t, int8_t> posTmp = {pos.first + mvX.at(i), pos.second + mvY.at(i)};
            if (posTmp.first >= 0 && posTmp.first < map.front().size() && posTmp.second >= 0 && posTmp.second < map.size()) {

                if(distanceMap.at(posTmp.second).at(posTmp.first) > newSteps.front().distanceToStart + 1 &&
                   map.at(posTmp.second).at(posTmp.first) <= newSteps.front().height + 1) {

                    distanceMap.at(posTmp.second).at(posTmp.first) = newSteps.front().distanceToStart + 1;
                    auto tmp = find_if(newSteps.begin(), newSteps.end(), find_pos(posTmp));
                    if (tmp == newSteps.end()) {
                        newSteps.emplace_back(posTmp, getDistance(posTmp, end), newSteps.front().distanceToStart + 1,map.at(posTmp.second).at(posTmp.first));

                    } else if (tmp->distanceToStart > newSteps.front().distanceToStart + 1) {
                        tmp->distanceToStart = newSteps.front().distanceToStart + 1;
                        tmp->totalDistance = tmp->distanceToStart + tmp->distanceToFinish;
                    }
                }
            }
        }

        newSteps.pop_front();
        newSteps.sort(compareNewSteps);
    }
    pathLenght = distanceMap.at(end.second).at(end.first);
}
