//
// Created by icas on 12/1/22.
//

#include "Elf.h"

#include <utility>

Elf::Elf(std::vector<int> foot) : food(std::move(foot)) {
    total = 0;
    for(auto i : food){
        total += i;
    }
}

const std::vector<int> &Elf::getFood() const {
    return food;
}

int Elf::getTotal() const {
    return total;
}
