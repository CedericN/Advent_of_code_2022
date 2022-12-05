#include <iostream>

#include "Elves.h"

using namespace std;

int main() {
    string day = DAY;
    day = day.at(0) == '0' ? day.substr(1) : day;
    cout << "One moment please i'm solving day " << day << endl;
    cout << (day.length() < 2 ? "..................................." : "....................................") << endl << endl;

    Elves elves("input.txt");

    cout << "part 1: " << elves.getPart1() << endl;
    cout << "part 2: " << elves.getPart2() << endl;
    return 0;
}
