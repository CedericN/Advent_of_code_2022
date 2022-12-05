//
// Created by Cederic on 03/12/2022.
//

#ifndef ADVENT_OF_CODE_ROUND_H
#define ADVENT_OF_CODE_ROUND_H

#include <iostream>

using namespace std;

class Round {
public:
    explicit Round(const pair<char, char> &data);
    unsigned char getPoints1();
    unsigned char getPoints2();
private:
    pair<char, char> data;
};


#endif //ADVENT_OF_CODE_ROUND_H
