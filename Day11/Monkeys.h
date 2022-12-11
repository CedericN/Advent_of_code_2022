//
// Created by Cederic on 11/12/2022.
//

#ifndef ADVENT_OF_CODE_MONKEYS_H
#define ADVENT_OF_CODE_MONKEYS_H

#include <fstream>
#include <algorithm>
#include "Monkey.h"

class Monkeys {
public:
    explicit Monkeys(const string& inputFile);
    void Round(uint8_t dropWorryLevel, bool print = false);

    uint64_t getLevelOfMonkeyBusiness(uint16_t rounds, uint8_t dropWorryLevel, bool print = false);

    void printMonkeyItems(){
        for (uint8_t i = 0; i < (uint8_t) monkeys.size(); ++i) {
            cout << "monkey " << (int)i << " has items: ";
            monkeys.at(i).printItems();
            cout << endl;
        }
    }

    void printMonkeyInspectedItems(){
        for (uint8_t i = 0; i < (uint8_t) monkeys.size(); ++i) {
            cout << "monkey " << (int)i << " has " << monkeys.at(i).getInspectedItems() << " items inspected" << endl;
        }
    }

private:
    vector<Monkey> monkeys;
    vector<Monkey> monkeys_start;
    uint64_t superDivider;
};


#endif //ADVENT_OF_CODE_MONKEYS_H
