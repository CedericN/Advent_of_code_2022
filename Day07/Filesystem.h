//
// Created by icas on 12/7/22.
//

#ifndef ADVENT_OF_CODE_FILESYSTEM_H
#define ADVENT_OF_CODE_FILESYSTEM_H

#include <fstream>

#include "Directory.h"

using namespace std;

class Filesystem {
public:
    explicit Filesystem(const string& inputFile);

    uint64_t part1(uint64_t maxSize){return rootDirectory.getDirLessThan(maxSize);}
    uint64_t part2(uint64_t totalSizeFileSystem, uint64_t spaceNeeded);
private:
    Directory rootDirectory;
};


#endif //ADVENT_OF_CODE_FILESYSTEM_H
