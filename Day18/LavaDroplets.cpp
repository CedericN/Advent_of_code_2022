//
// Created by Cederic on 18/12/2022.
//

#include "LavaDroplets.h"

LavaDroplets::LavaDroplets(const string &inputFile): xMax(0), yMax(0), zMax(0){
    ifstream InputFileStream(inputFile);
    string line;

    while (getline(InputFileStream, line)) {
        Coordinates coordinates;

        uint64_t pos = line.find(',');
        if(pos == string::npos){continue;}
        coordinates.x = stoi(line.substr(0,pos));
        line = line.substr(pos + 1);
        pos = line.find(',');
        if(pos == string::npos){continue;}
        coordinates.y = stoi(line.substr(0,pos));
        line = line.substr(pos + 1);
        coordinates.z = stoi(line.substr(0));

        if(xMax < coordinates.x){xMax = coordinates.x;}
        if(yMax < coordinates.y){yMax = coordinates.y;}
        if(zMax < coordinates.z){zMax = coordinates.z;}

        if(droplets.find(coordinates) == droplets.end()){
            droplets[coordinates] = checkSides(coordinates).first;
        }
    }
}

uint64_t LavaDroplets::surfaceArea(bool advanced) {
    if(advanced){
        map<Coordinates, bool> checked;
        for (int x = 0; x <= xMax; ++x) {
            cout << "\rpart 2: " << x + 1 << "/" << (int) xMax + 1 << " ";
            for (int y = 0; y <= yMax; ++y) {
                for (int z = 0; z <= zMax; ++z) {
                    Coordinates coordinates(x,y,z);
                    map<Coordinates, uSmall> dropletsCopy = droplets;
                    if(droplets.find(coordinates) == droplets.end() && checked.find(coordinates) == checked.end() && !checkCoordinates(coordinates)){
                        list<Coordinates> sides{coordinates};
                        while(!sides.empty()){
                            if(checkCoordinates(sides.front())){break;}
                            if(droplets.find(sides.front()) == droplets.end()) {
                                pair<uSmall, vector<LavaDroplets::Coordinates>> tmp = checkSides(sides.front());
                                droplets[sides.front()] = tmp.first;
                                for (auto &i: tmp.second) {
                                    sides.push_back(i);
                                }
                            }
                            checked[sides.front()] = true;
                            sides.pop_front();
                        }
                        if(!sides.empty()){
                            droplets = dropletsCopy;
                            for (auto &i: sides) {
                                checked[i] = true;
                            }
                        }
                    }
                    checked[coordinates] = true;
                }
            }
        }
        cout << "\rpart 2: " << "     ";
        cout << "\rpart 2: ";
    }

    uint64_t returnValue = 0;

    for (auto & droplet : droplets) {
        returnValue += droplet.second;
    }

    return returnValue;
}

pair<uSmall, vector<LavaDroplets::Coordinates>> LavaDroplets::checkSides(const LavaDroplets::Coordinates &coordinates) {
    if(droplets.empty()){return {6, {}};}
    uSmall numberOfOpenSides = 6;
    Coordinates coordinatesTmp = coordinates;

    bool checkSideB = false;
    vector<Coordinates> openSides;

    coordinatesTmp.x --;
    checkSideB = checkSide(coordinatesTmp);
    numberOfOpenSides -= checkSideB;
    if(!checkSideB){openSides.push_back(coordinatesTmp);}

    coordinatesTmp.x += 2;
    checkSideB = checkSide(coordinatesTmp);
    numberOfOpenSides -= checkSideB;
    if(!checkSideB){openSides.push_back(coordinatesTmp);}

    coordinatesTmp.x --;
    coordinatesTmp.y --;
    checkSideB = checkSide(coordinatesTmp);
    numberOfOpenSides -= checkSideB;
    if(!checkSideB){openSides.push_back(coordinatesTmp);}

    coordinatesTmp.y += 2;
    checkSideB = checkSide(coordinatesTmp);
    numberOfOpenSides -= checkSideB;
    if(!checkSideB){openSides.push_back(coordinatesTmp);}

    coordinatesTmp.y --;
    coordinatesTmp.z --;
    checkSideB = checkSide(coordinatesTmp);
    numberOfOpenSides -= checkSideB;
    if(!checkSideB){openSides.push_back(coordinatesTmp);}

    coordinatesTmp.z += 2;
    checkSideB = checkSide(coordinatesTmp);
    numberOfOpenSides -= checkSideB;
    if(!checkSideB){openSides.push_back(coordinatesTmp);}

    return {numberOfOpenSides, openSides};
}

ostream& operator << (ostream &os, const LavaDroplets::Coordinates &coord){
    os << "x: " << (int) coord.x << "\ty: " << (int) coord.y << "\tz: " << (int) coord.z;
    return os;
}
