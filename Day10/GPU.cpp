//
// Created by Cederic on 10/12/2022.
//

#include "GPU.h"

GPU::GPU(const string &inputFile) {
    ifstream InputFileStream(inputFile);
    string line;

    cycles.emplace_back(1);

    while(getline(InputFileStream, line)){
        uint64_t pos = line.find(' ');
        if(pos != string::npos){
            commands.emplace_back(addX, (char) stoi(line.substr(pos + 1)));
        }
        else{
            commands.emplace_back(noop, 0);
        }
//        cout << commands.back().first << (commands.back().first == addX ? ": " : "") << (commands.back().first == addX ? to_string(commands.back().second) : "") << endl;
        updateCycles(commands.back().first, commands.back().second);
    }
}

int64_t GPU::getSignalStrengths() {
    int64_t returnValue = 0;
    vector<uint32_t> points {20,60,100,140,180,220};

//    printCycles();

    for(auto &i : points){
        returnValue += cycles.at(i - 1) * i;
//        cout << "at " << i << ": " << cycles.at(i) << endl;
    }

    return returnValue;
}

void GPU::drawScreen() {
    for (uint8_t i = 0; i < 240 ; ++i) {
        if(i%40 == 0){cout << endl;}
        cout << (abs(i%40 - cycles.at(i)) < 2 ? '#' : ' ');
    }
    cout << endl;
}

void GPU::updateCycles(GPU::List_of_Commands com, char value) {
    switch (com) {
        case noop:
            cycles.emplace_back(cycles.back());
            break;
        case addX:
            cycles.emplace_back(cycles.back());
            cycles.emplace_back(cycles.back() + value);
            break;
    }
}
