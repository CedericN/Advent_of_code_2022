//
// Created by Cederic on 03/12/2022.
//

#ifndef ADVENT_OF_CODE_RUCKSACK_H
#define ADVENT_OF_CODE_RUCKSACK_H

#include <iostream>

using namespace std;

class Rucksack {
public:
    explicit Rucksack(string contains);
    string getCommonItems();
    string getItems() const {return compartments.first + compartments.second;}
private:
    pair <string , string> compartments;
};


#endif //ADVENT_OF_CODE_RUCKSACK_H
