//
// Created by Cederic on 11/12/2022.
//

#ifndef ADVENT_OF_CODE_MONKEY_H
#define ADVENT_OF_CODE_MONKEY_H

#include <vector>
#include <iostream>

using namespace std;

class Monkey {
public:
    explicit Monkey(vector<string> monkeyData);

    void turn(uint8_t dropWorryLevel, vector<Monkey> &otherMonkeys);
    void addItem(uint64_t item){items.push_back(item);}

    uint64_t getInspectedItems() const {return inspectedItems;}

    void printItems(){
        for (auto &i: items) {
            cout << i << " ";
        }
    }

    uint64_t getTestCondition() const {return testCondition;}

    void lowerStress(uint64_t superDivider);

private:
    void printVar(){
        cout << "items: ";
        for (auto &i: items) {
            cout << i << " ";
        }
        cout << endl << "operation: " << (operation.first ? "* " : "+ ") << (int) operation.second << endl;
        cout << "test: if divisible by " << (int) testCondition << " then throw to " << (int) test.first << " else throw to " << (int) test.second << endl;

        cout << endl;
    }

    vector<uint64_t> items;
    pair<bool, uint64_t> operation; //first: true: multiply, false: add, second: value with 0 is old value
    uint64_t testCondition;
    pair<uint8_t, uint8_t> test; //first: true, second: false

    uint64_t inspectedItems;

};


#endif //ADVENT_OF_CODE_MONKEY_H
