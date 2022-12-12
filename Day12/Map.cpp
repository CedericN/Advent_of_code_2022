//
// Created by icas on 12/12/22.
//

#include "Map.h"

Map::Map(const string &inputFile) {
    ifstream InputFileStream(inputFile);
    string line;

    steps = 0;

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

            row.push_back(i);
        }
        map.push_back(row);
    }
}

uint32_t Map::getSteps() {
//    cout << endl;
//    char height = 'a';

    step();

//    if(start.first != 0){ step({start.first - 1, start.second}, height, visited);}
//    if(start.first < map.at(start.second).size() - 1){ step({start.first + 1, start.second}, height, visited);}
//    if(start.second != 0){ step({start.first, start.second - 1}, height, visited);}
//    if(start.second < map.size() - 1){ step({start.first, start.second + 1}, height, visited);}
    return steps;
}

void Map::step() {
    vector<uint32_t> visited (map.size(), 0);

    vector<newStep> newSteps;

    newSteps.emplace_back(start, 0,0, map.at(start.second).at(start.first));

    vector<int8_t> mvX {1,0,-1,0};
    vector<int8_t> mvY {0,1,0,-1};

    while(!newSteps.empty()){
        pair<uint8_t, uint8_t> pos = newSteps.front().pos;
        setVisited(visited, pos);

        if(pos == end){steps = newSteps.front().distanceToStart; return;}

        cout << "pos x: " << (int) newSteps.front().pos.first << "\ty: " << (int) newSteps.front().pos.second << endl;
        cout << "dis to start " << newSteps.front().distanceToStart << "\tdis to end " << newSteps.front().distanceToFinish << endl;

        for (uint8_t i = 0; i < 4; ++i) {
            pair<int8_t, int8_t> posTmp = {pos.first + mvX.at(i), pos.second + mvY.at(i)};
            if (posTmp.first >= 0 && posTmp.first < map.front().size() && posTmp.second >= 0 && posTmp.second < map.size()) {

                cout << "pos TMP \tx: " << (int) posTmp.first << "\ty: " << (int) posTmp.second << endl;
                cout << "map Max \tx: " << (int) map.front().size() << "\ty: " << (int) map.size() << endl;
                cout << "height  \tc: " << newSteps.front().height << "\tn: " << map.at(posTmp.second).at(posTmp.first) << endl;
                cout << "already visited? " << getVisited(visited, posTmp) << endl;
                if(!getVisited(visited, posTmp) &&
                    map.at(posTmp.second).at(posTmp.first)  <= newSteps.front().height + 1) {

                    cout << "++++++++ if" << endl;
                    auto tmp = find_if(newSteps.begin(), newSteps.end(), find_pos(posTmp));
//                cout << "pos TMP \tx: " << (int) tmp->pos.first << "\ty: " << (int) tmp->pos.second << endl;
                    if (tmp->pos == newSteps.back().pos && tmp->pos != posTmp || newSteps.size() == 1) {
                        newSteps.emplace_back(posTmp, getDistance(posTmp, end), newSteps.front().distanceToStart + 1,map.at(posTmp.second).at(posTmp.first));
                        cout << "------ new step" << endl;
                    } else if (tmp->distanceToStart > newSteps.front().distanceToStart + 1) {
                        tmp->distanceToStart = newSteps.front().distanceToStart + 1;
                        tmp->totalDistance = tmp->distanceToStart + tmp->distanceToFinish;
                        cout << "------ better step" << endl;
                    }
                }
            }

            cout << endl;
        }

//        if(pos.first < map.at(pos.second).size() - 1 && !getVisited(visited, {pos.first + 1, pos.second}) && (map.at(pos.second).at(pos.first + 1) <= newSteps.front().height + 1)){
//            pair<uint8_t, uint8_t> posTmp = {pos.first + 1, pos.second};
//            newSteps.emplace_back(posTmp, getDistance(posTmp, end), newSteps.front().distanceToStart + 1, map.at(pos.second).at(pos.first - 1));
//        }
//
//        if(pos.second != 0 && !getVisited(visited, {pos.first, pos.second - 1}) && (map.at(pos.second - 1).at(pos.first) < newSteps.front().height + 1)){
//            pair<uint8_t, uint8_t> posTmp = {pos.first, pos.second - 1};
//            newSteps.emplace_back(posTmp, getDistance(posTmp, end), newSteps.front().distanceToStart + 1, map.at(pos.second).at(pos.first - 1));
//        }
//
//        if(pos.second < map.size() - 1 && !getVisited(visited, {pos.first, pos.second + 1}) && (map.at(pos.second + 1).at(pos.first) < newSteps.front().height + 1)){
//            pair<uint8_t, uint8_t> posTmp = {pos.first, pos.second + 1};
//            newSteps.emplace_back(posTmp, getDistance(posTmp, end), newSteps.front().distanceToStart + 1, map.at(pos.second).at(pos.first - 1));
//        }

        newSteps.erase(newSteps.begin());

        sort(newSteps.begin(), newSteps.end(), compareNewSteps);
        cout << "########### size new Step " << newSteps.size() << endl << endl;
    }

}

void Map::printMap(pair<uint8_t, uint8_t> pos) {
    system("cls");

    for (int i = 0; i < map.size(); ++i) {
        for (int j = 0; j < map.at(i).size(); ++j) {
            if(i == start.second && j == start.first){cout << 'S';}
            else if(i == end.second && j == end.first){cout << 'E';}
            else if(i == pos.second && j == pos.first){cout << '*';}
            else{cout << map.at(i).at(j);}
        }
        cout << endl;
    }
    cout << endl;


    string q;
    cin >> q;
}
