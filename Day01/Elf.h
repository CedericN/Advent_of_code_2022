//
// Created by icas on 12/1/22.
//

#ifndef DAY1_ELF_H
#define DAY1_ELF_H

#include <vector>

class Elf {
public:
    explicit Elf(std::vector<int> foot);

    const std::vector<int> &getFood() const;

    int getTotal() const;

private:
    std::vector<int> food;
    int total{};
};


#endif //DAY1_ELF_H
