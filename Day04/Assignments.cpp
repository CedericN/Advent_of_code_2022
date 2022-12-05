//
// Created by Cederic on 04/12/2022.
//

#include "Assignments.h"

Assignments::Assignments(string inputFile) {
    ifstream InputFileStream(inputFile);

    string line;

    while(getline(InputFileStream, line)){
        elf_pairs.emplace_back(line);
    }

}

pair<unsigned int, unsigned int> Assignments::solve() {
    pair<unsigned int, unsigned int> count {0,0};

    for(auto &i : elf_pairs){
        count.first += i.isFullyContained();
        count.second += i.isPartlyContained();
    }
    return count;
}
