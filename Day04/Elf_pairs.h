//
// Created by Cederic on 04/12/2022.
//

#ifndef ADVENT_OF_CODE_ELF_PAIRS_H
#define ADVENT_OF_CODE_ELF_PAIRS_H

#include <iostream>
#include <string>

using namespace std;

class Elf_pairs {
public:
    explicit Elf_pairs (const string& pairs);
    bool isFullyContained() const;
    bool isPartlyContained() const;
private:
    pair<pair<unsigned char, unsigned char>, pair<unsigned char, unsigned char>> assignment;
};


#endif //ADVENT_OF_CODE_ELF_PAIRS_H
