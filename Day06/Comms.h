//
// Created by Cederic on 06/12/2022.
//

#ifndef ADVENT_OF_CODE_COMMS_H
#define ADVENT_OF_CODE_COMMS_H

#include <iostream>
#include <string>

using namespace std;

class Comms {
public:
    explicit Comms(const string &input) : dataStream(input) {}
    uint32_t getStartOf(uint32_t size);
private:
    bool noDoubleCharacters(const string check);
    string dataStream;
};


#endif //ADVENT_OF_CODE_COMMS_H
