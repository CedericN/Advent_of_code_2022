#include <iostream>

#include "Supplies.h"

using namespace std;

int main() {
    string day = DAY;
    day = day.at(0) == '0' ? day.substr(1) : day;
    cout << "One moment please i'm solving day " << day << endl;
    cout << (day.length() < 2 ? "..................................." : "....................................") << endl << endl;

    Supplies supplies("input.txt");

    cout << "part 1: " << supplies.part1() << endl;
    cout << "part 2: " << supplies.part2() << endl;

    return 0;
}
