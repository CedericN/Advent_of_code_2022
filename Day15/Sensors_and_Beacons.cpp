//
// Created by icas on 12/15/22.
//

#include "Sensors_and_Beacons.h"

Sensors_and_Beacons::Sensors_and_Beacons(const string &inputFile) {
    ifstream InputFileStream(inputFile);
    string line;

    while (getline(InputFileStream, line)) {
        sensors.push_back(getSensorsAndBeacon(line));
    }
}

Sensors_and_Beacons::sensor Sensors_and_Beacons::getSensorsAndBeacon(string line) {
    sensor returnSensor;
    pair<int64_t, int64_t> beacon;

    uint64_t pos = line.find("x=");
    if(pos != string::npos){
        line = line.substr(pos + 2);
        pos = line.find(',');
        returnSensor.pos.first = stoi(line.substr(0, pos));
    }
    else{
        cout << "I can't add the sensor" << endl;
        return {};
    }

    pos = line.find("y=");
    if(pos != string::npos){
        line = line.substr(pos + 2);
        pos = line.find(':');
        returnSensor.pos.second = stoi(line.substr(0, pos));
    }
    else{
        cout << "I can't add the sensor" << endl;
        return {};
    }

    pos = line.find("x=");
    if(pos != string::npos){
        line = line.substr(pos + 2);
        pos = line.find(',');
        beacon.first = stoi(line.substr(0, pos));
    }
    else{
        cout << "I can't add the sensor" << endl;
        return {};
    }

    pos = line.find("y=");
    if(pos != string::npos){
        line = line.substr(pos + 2);
        beacon.second = stoi(line);
    }
    else{
        cout << "I can't add the sensor" << endl;
        return {};
    }

    returnSensor.distance = getDis(returnSensor.pos, beacon);
    return returnSensor;
}

uint64_t Sensors_and_Beacons::getBeaconNotPossible(int64_t row) {
    vector<pair<int64_t, int64_t>> beaconNotPossible;

    for (auto &i: sensors) {
        pair<int64_t, int64_t> tmp;
//        cout << (i.distance - abs(i.pos.second - row)) << endl;
        tmp.first = i.pos.first - (i.distance - abs(i.pos.second - row));
        tmp.second = i.pos.first + (i.distance - abs(i.pos.second - row));
        beaconNotPossible.push_back(tmp);
    }

    sort(beaconNotPossible.begin(), beaconNotPossible.end());

    vector<pair<int64_t, int64_t>> betterBeaconNotPossible;

    betterBeaconNotPossible.push_back(beaconNotPossible.front());

    for (auto &i: beaconNotPossible) {
//        cout << "x1: " << i.first << "\tx2: " << i.second << endl;
        if(betterBeaconNotPossible.back() == i){continue;}
        if(betterBeaconNotPossible.back().second >= i.second){ continue;}
        if(betterBeaconNotPossible.back().second >= i.first){
            betterBeaconNotPossible.back().second = i.second;
            continue;
        }
        betterBeaconNotPossible.push_back(i);
    }

    uint64_t counter = 0;

    for (auto &i: betterBeaconNotPossible){
//        cout << "x1: " << i.first << "\tx2: " << i.second << endl;
        counter += i.second - i.first;
    }

    return counter;
}

uint64_t Sensors_and_Beacons::getDistressBeacon(pair <int64_t, int64_t> min, pair <int64_t, int64_t> max, int64_t multiply) {
    vector<vector<pair<int64_t, int64_t>>> beaconNotPossible;

    for (int64_t i = min.second; i <= max.second; ++i) {
        if(i % 40000 == 0){cout << "\rpart 2: " << i / 40000 << "%   ";}
        vector<pair<int64_t, int64_t>> beaconNotPossibleTmp;
        for (auto &j: sensors) {
            pair<int64_t, int64_t> tmp;
            //        cout << (i.distance - abs(i.pos.second - row)) << endl;
            tmp.first = j.pos.first - (j.distance - abs(j.pos.second - i));
            tmp.second = j.pos.first + (j.distance - abs(j.pos.second - i));
            tmp.first = tmp.first < 0 ? min.first : tmp.first > max.first ? max.first : tmp.first;
            tmp.second = tmp.second < 0 ? min.second : tmp.second > max.second ? max.second : tmp.second;
            beaconNotPossibleTmp.push_back(tmp);
        }

        sort(beaconNotPossibleTmp.begin(), beaconNotPossibleTmp.end());

        vector<pair<int64_t, int64_t>> betterBeaconNotPossible;

        betterBeaconNotPossible.push_back(beaconNotPossibleTmp.front());

        for (auto &j: beaconNotPossibleTmp) {
    //        cout << "x1: " << i.first << "\tx2: " << i.second << endl;
            if(betterBeaconNotPossible.back() == j){continue;}
            if(betterBeaconNotPossible.back().second >= j.second){ continue;}
            if(betterBeaconNotPossible.back().second >= j.first - 1){
                betterBeaconNotPossible.back().second = j.second;
                continue;
            }
            betterBeaconNotPossible.push_back(j);
        }

        beaconNotPossible.push_back(betterBeaconNotPossible);
    }

    for(int64_t i = 0; i <= max.second - min.second; ++i){
        if(beaconNotPossible.at(i).size() == 2){
//            cout << i + min.second << endl;
            if (beaconNotPossible.at(i).back().first == min.first + 1){
                cout << "error" << endl;
            }
            else if(beaconNotPossible.at(i).back().second == max.first - 1){
                cout << "error" << endl;
            }
            else if(beaconNotPossible.at(i).front().second + 2 == beaconNotPossible.at(i).back().first){
                cout << "\rpart 2: ";
                return (beaconNotPossible.at(i).front().second + 1) * multiply + i + min.second;
            }
        }
        else if(beaconNotPossible.at(i).size() == 1){
            if (beaconNotPossible.at(i).back().first == min.first + 1){
                cout << "\rpart 2: ";
                return min.first * multiply + i + min.second;
            }
            else if(beaconNotPossible.at(i).back().second == max.first - 1){
                cout << "\rpart 2: ";
                return max.first * multiply + i + min.second;
            }
        }
    }

    return 0;
}
