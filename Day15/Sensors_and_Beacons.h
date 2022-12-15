//
// Created by icas on 12/15/22.
//

#ifndef ADVENT_OF_CODE_SENSORS_AND_BEACONS_H
#define ADVENT_OF_CODE_SENSORS_AND_BEACONS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class Sensors_and_Beacons {
public:
    struct sensor{
        pair<int64_t, int64_t> pos;
        int64_t distance;
    };

    explicit Sensors_and_Beacons(const string &inputFile);
    uint64_t getBeaconNotPossible(int64_t row);
    uint64_t getDistressBeacon(pair <int64_t, int64_t> min, pair <int64_t, int64_t> max, int64_t multiply);

private:
    sensor getSensorsAndBeacon(string line);

    static int64_t getDis(pair<int64_t, int64_t> pos1, pair<int64_t, int64_t> pos2){
        return abs(pos2.first - pos1.first) + abs(pos2.second - pos1.second);
    }

    vector<sensor> sensors;

};


#endif //ADVENT_OF_CODE_SENSORS_AND_BEACONS_H
