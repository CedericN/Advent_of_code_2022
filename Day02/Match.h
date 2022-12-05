//
// Created by Cederic on 03/12/2022.
//

#ifndef ADVENT_OF_CODE_MATCH_H
#define ADVENT_OF_CODE_MATCH_H

#include <vector>
#include <fstream>

#include "Round.h"

using namespace std;

class Match {
public:
    explicit Match(const string& inputFile);
    pair<unsigned int, unsigned int> getScore();
private:
    std::vector<Round> rounds;
};


#endif //ADVENT_OF_CODE_MATCH_H
