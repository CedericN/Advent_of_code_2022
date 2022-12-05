//
// Created by Cederic on 04/12/2022.
//

#ifndef ADVENT_OF_CODE_ASSIGNMENTS_H
#define ADVENT_OF_CODE_ASSIGNMENTS_H

#include <vector>
#include <fstream>

#include "Elf_pairs.h"

class Assignments {
public:
    explicit Assignments(string inputFile);
    pair<unsigned int, unsigned int> solve();
private:
    vector<Elf_pairs> elf_pairs;
};


#endif //ADVENT_OF_CODE_ASSIGNMENTS_H
