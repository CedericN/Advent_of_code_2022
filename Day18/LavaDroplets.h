//
// Created by Cederic on 18/12/2022.
//

#ifndef ADVENT_OF_CODE_LAVADROPLETS_H
#define ADVENT_OF_CODE_LAVADROPLETS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <list>

using namespace std;
using uSmall = uint8_t;

class LavaDroplets {
public:

    struct Coordinates{
        uSmall x = 0;
        uSmall y = 0;
        uSmall z = 0;

        Coordinates(uSmall nx, uSmall ny, uSmall nz): x(nx), y(ny), z(nz){}

        Coordinates(): x(0), y(0), z(0) {}

        bool operator < (const Coordinates &coord) const {
            return (x < coord.x) || (x == coord.x && y < coord.y) || (x == coord.x && y == coord.y && z < coord.z);
        }

        bool operator == (const Coordinates &coord) const {
            return x == coord.x && y == coord.y && z == coord.z;
        }

    };

    LavaDroplets(const string &inputFile);

    uint64_t surfaceArea(bool advanced = false);
private:

    pair<uSmall, vector<Coordinates>> checkSides(const LavaDroplets::Coordinates &coordinates);
    bool checkSide(const LavaDroplets::Coordinates &coordinates){
        if(droplets.find(coordinates) != droplets.end()){
            droplets[coordinates] = droplets[coordinates] > 0 ? droplets[coordinates] - 1 : 0;
            return true;
        }
        return false;
    }

    bool checkCoordinates(const Coordinates &coordinates){
        return coordinates.x == 0 ||coordinates.y == 0 || coordinates.z == 0 || coordinates.x >= xMax || coordinates.x >= yMax || coordinates.z >= zMax;
    }

    map<Coordinates, uSmall> droplets;
    uSmall xMax;
    uSmall yMax;
    uSmall zMax;
};

ostream& operator << (ostream &os, const LavaDroplets::Coordinates &coord);

#endif //ADVENT_OF_CODE_LAVADROPLETS_H
