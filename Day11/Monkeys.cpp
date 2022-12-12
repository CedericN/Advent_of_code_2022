//
// Created by Cederic on 11/12/2022.
//

#include "Monkeys.h"

Monkeys::Monkeys(const string &inputFile) {
    ifstream InputFileStream(inputFile);
    string line;

    vector<string>lines;

    while(getline(InputFileStream, line)){
        if(line.front() != ' '){
            if(line.front() != 'M'){
                monkeys_start.emplace_back(lines);
                lines.clear();
            }
        }
        else{
            lines.emplace_back(line);
        }
    }
    monkeys_start.emplace_back(lines);
    superDivider = 1;
    for (auto &i: monkeys_start) {
        superDivider *= i.getTestCondition();
    }
}

void Monkeys::Round(uint8_t dropWorryLevel, bool print) {
    for (auto &i: monkeys) {
        i.turn(dropWorryLevel, monkeys);
    }
    for (auto &i: monkeys) {
        i.lowerStress(superDivider);
    }
    if(print){printMonkeyItems();}
}

uint64_t Monkeys::getLevelOfMonkeyBusiness(uint16_t rounds, uint8_t dropWorryLevel, bool print) {
    monkeys = monkeys_start;
    for (int i = 0; i < rounds; ++i) {
        if(print){cout << "round " << i + 1 << ": " << endl;}
        Round(dropWorryLevel, print);
        if(print){cout << endl;}
//        if(rounds > 100){
//            if(i%1000 == 999 || i == 19 || i == 0){
//                cout << "============ round " << i + 1 << " ============" << endl;
//                printMonkeyInspectedItems();
//                cout << endl;
//            }
//        }
    }

    if(print){printMonkeyInspectedItems();}

    uint64_t mostActive = 0;
    uint64_t secondMostActive = 0;

    for(auto &i: monkeys){
        if(i.getInspectedItems() > mostActive){mostActive = i.getInspectedItems();}
    }
    for(auto &i: monkeys){
        if(i.getInspectedItems() != mostActive && i.getInspectedItems() > secondMostActive){secondMostActive = i.getInspectedItems();}
    }

    return mostActive * secondMostActive;
}
