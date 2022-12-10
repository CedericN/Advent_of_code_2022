//
// Created by Cederic on 10/12/2022.
//

#ifndef ADVENT_OF_CODE_GPU_H
#define ADVENT_OF_CODE_GPU_H

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class GPU {
public:
    enum List_of_Commands{
        addX=2,
        noop=1,
    };

    explicit GPU(const string& inputFile);
    int64_t getSignalStrengths();

    void drawScreen();

    void printCycles(){
        cout << endl << endl;
        for(uint32_t i = 0; i < cycles.size(); i++){
            cout << i << ": " << cycles.at(i) << endl;
        }
        cout << endl;
    }

private:
    void updateCycles(List_of_Commands com, char value);


    vector<pair<List_of_Commands, int8_t>> commands;
    vector<int64_t> cycles;
};


#endif //ADVENT_OF_CODE_GPU_H
