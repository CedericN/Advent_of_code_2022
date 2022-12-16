//
// Created by icas on 12/16/22.
//

#include "Valves.h"

Valves::Valves(const string& inputFile) {
    ifstream InputFileStream(inputFile);
    string line;

    cout << "yess" << endl;

    while (getline(InputFileStream, line)) {
        valves.push_back(getValve(line));
    }

    for (auto &i: valves) {
        cout << "valve: " << i.name << "\tflow rate: " << (int) i.flowRate << "\tconnect to: ";
        for (auto &j: i.leadToValves) {
            cout << j << " ";
        }
        cout << endl;
    }
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
