//
// Created by icas on 12/8/22.
//

#ifndef ADVENT_OF_CODE_FOREST_H
#define ADVENT_OF_CODE_FOREST_H

#include <fstream>
#include <vector>

#include "Tree.h"

using namespace std;

class Forest {
public:
    explicit Forest(const string& inputFile);

    uint32_t getVisibleTrees();
    uint32_t getHighestScenicScore();

    void printVisibility();

private:
    void updateVisibility();
    bool checkTree(uint32_t row, uint32_t colm, uint32_t height);
    uint32_t updateScenicScore(uint32_t row, uint32_t colm, uint32_t height);
    vector<vector<Tree>> trees;
};


#endif //ADVENT_OF_CODE_FOREST_H
