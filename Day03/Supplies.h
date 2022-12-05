//
// Created by Cederic on 03/12/2022.
//

#ifndef ADVENT_OF_CODE_SUPPLIES_H
#define ADVENT_OF_CODE_SUPPLIES_H

#include <vector>
#include <fstream>

#include "Rucksack.h"


class Supplies {
public:
    explicit Supplies(string inputFile);

    unsigned int part1();
    unsigned int part2();
private:
    static unsigned int getPriority(char c);
    static char getBadge(const string& rucksack1, const string& rucksack2, const string& rucksack3);
    static string getCommonChar(const string& input1, const string& input2, bool onlyOne = false);

    vector<Rucksack> rucksacks;
};


#endif //ADVENT_OF_CODE_SUPPLIES_H
