//
// Created by icas on 12/5/22.
//

#ifndef ADVENT_OF_CODE_PROCEDURE_H
#define ADVENT_OF_CODE_PROCEDURE_H

#include <string>
#include <iostream>

using namespace std;

class Procedure {
public:
    explicit Procedure(string& input);

    unsigned char getAmount() const {
        return amount;
    }

    unsigned char getFrom() const {
        return from;
    }

    unsigned char getTo() const {
        return to;
    }

private:
    unsigned char amount;
    unsigned char from;
    unsigned char to;
};


#endif //ADVENT_OF_CODE_PROCEDURE_H
