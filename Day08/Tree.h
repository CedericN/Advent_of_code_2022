//
// Created by icas on 12/8/22.
//

#ifndef ADVENT_OF_CODE_TREE_H
#define ADVENT_OF_CODE_TREE_H

#include <iostream>

using namespace std;

class Tree {
public:
    explicit Tree(const uint8_t height):height(height),visible(false), scenicScore(0){}

    void setVisible(bool isVisible) {visible = isVisible;}
    void setScenicScore(uint32_t scenicScoreTmp) {scenicScore = scenicScoreTmp;}

    uint8_t getHeight() const {return height;}
    bool isVisible() const {return visible;}
    uint32_t getScenicScore() const {return scenicScore;}

private:
    const uint8_t height;
    bool visible;
    uint32_t scenicScore;
};


#endif //ADVENT_OF_CODE_TREE_H
