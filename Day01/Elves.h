//
// Created by icas on 12/1/22.
//

#ifndef DAY1_ELVES_H
#define DAY1_ELVES_H

#include <string>
#include <fstream>
#include <algorithm>
#include "Elf.h"

using namespace std;

class Elves {
public:
    explicit Elves(const string& inputFile);

    int getPart1() const;
    int getPart2() const;
    static bool sortElves (const Elf& i, const Elf& j) {return (i.getTotal()<j.getTotal());}
private:

    vector<Elf> listOfElves;
};


#endif //DAY1_ELVES_H
