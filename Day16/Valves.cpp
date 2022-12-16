//
// Created by icas on 12/16/22.
//

#include "Valves.h"

Valves::Valves(const string& inputFile) {
    ifstream InputFileStream(inputFile);
    string line;

    vector<valve> valvesTmp;
    uint8_t numberOfUsefulValves = 0;


    while (getline(InputFileStream, line)) {
        valvesTmp.push_back(getValve(line));
    }

    map<string, uint8_t> indexing;

    for (auto &i : valvesTmp) {
        if(i.name == "AA"){
            indexing[i.name] = valves.size();
            numberOfUsefulValves ++;
            valves.push_back(i);
        }
    }

    for (auto &i : valvesTmp) {
        if(i.flowRate > 0){
            indexing[i.name] = valves.size();
            numberOfUsefulValves ++;
            valves.push_back(i);
        }
    }

    for (auto &i : valvesTmp) {
        if(i.flowRate == 0 && i.name != "AA"){
            indexing[i.name] = valves.size();
            valves.push_back(i);
        }
    }

    for (auto &i: valves) {
        for (auto &j: i.leadToValves) {
            i.leadToValvesIndex.push_back(indexing[j]);
        }
    }

    scores = vector<int64_t>((1L<<numberOfUsefulValves) * valves.size() * 31 * 2, -1);

    startTime = 0;

//    for (auto &i: valves) {
//        cout << "valve: " << i.name << "\tflow rate: " << (int) i.flowRate << "\tconnect to: ";
//        for (auto &j: i.leadToValves) {
//            cout << j << " ";
//        }
//        cout << "\t or index: ";
//        for (auto &j: i.leadToValvesIndex) {
//            cout << (int) j << " ";
//        }
//        cout << endl;
//    }
//    cout << "scores size: " << scores.size();
}

Valves::valve Valves::getValve(string basicString) {
    valve valveTmp;

    valveTmp.name = basicString.substr(6,2);

    basicString = basicString.substr(23);

    uint64_t pos = basicString.find(';');
    if(pos == string::npos){
        cout << "error with reading valve flow rate" << endl;
        return {};
    }

    valveTmp.flowRate = stoi(basicString.substr(0, pos));

    basicString = basicString.substr(pos + 1);

    pos = basicString.find("valve ");
    if(pos != string::npos){
        basicString = basicString.substr(pos + 6);
    }
    else {
        pos = basicString.find("valves ");
        if (pos != string::npos) {
            basicString = basicString.substr(pos + 7);
        } else {
            cout << "error with reading connected valves" << endl;
            return {};
        }
    }


    pos = basicString.find(", ");
    while(pos != string::npos){
        valveTmp.leadToValves.push_back(basicString.substr(0,2));
        basicString = basicString.substr(pos + 2);
        pos = basicString.find(", ");
    }
    valveTmp.leadToValves.push_back(basicString.substr(0,2));

    return valveTmp;
}

uint32_t Valves::searchPath(uint8_t currentValve, uint32_t openValves, uint8_t timeLeft, bool otherPersons) {
    if(timeLeft == 0){
        return otherPersons ? searchPath(0, openValves, startTime, false) : 0;
    }

    timeLeft --;

    auto key = openValves * valves.size() * 31 * 2 + currentValve * 31 * 2 + timeLeft * 2 + otherPersons;
    if(scores.at(key) >= 0){
        return scores.at(key);
    }

    uint32_t returnValue = 0;
    bool closed = (openValves & (1 << currentValve)) == 0;

    if(closed && valves[currentValve].flowRate){
        uint32_t nextOpenValves = openValves | (1 << currentValve);
        assert(nextOpenValves > openValves);
        returnValue = (timeLeft) * valves[currentValve].flowRate + searchPath(currentValve, nextOpenValves, timeLeft, otherPersons);
    }

    for(auto &i: valves[currentValve].leadToValvesIndex){
        returnValue = max(returnValue, searchPath(i, openValves, timeLeft, otherPersons));
    }

    scores[key] = returnValue;

    return returnValue;
}
