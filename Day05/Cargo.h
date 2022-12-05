//
// Created by icas on 12/5/22.
//

#ifndef ADVENT_OF_CODE_CARGO_H
#define ADVENT_OF_CODE_CARGO_H

#include <vector>
#include <string>
#include <fstream>
#include "Procedure.h"

using namespace std;

class Cargo {
public:
    explicit Cargo(const string& inputFile);
    void moveCrates9000();
    void moveCrates9001();
    string getTopCrates(bool copy = false){
        string returnValue;
        for(auto &i : (copy ? cargoArrangementCopy : cargoArrangement)){
            returnValue += i.back();
        }
        return returnValue;
    }
private:
    void parseCrateStart(vector<string>& cargoStart);
    void printCrates(bool copy = false);

    vector<Procedure> craneProcedure;
    vector<string> cargoArrangement;
    vector<string> cargoArrangementCopy;
};


#endif //ADVENT_OF_CODE_CARGO_H
