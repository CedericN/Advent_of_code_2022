#include "Filesystem.h"

using namespace std;

int main() {
    string day = DAY;
    day = day.at(0) == '0' ? day.substr(1) : day;
    cout << "One moment please i'm solving day " << day << endl;
    cout << (day.length() < 2 ? "..................................." : "....................................") << endl << endl;

    Filesystem filesystem("input.txt");

    cout << endl << "part 1: " << filesystem.part1(100000) << endl;
    cout << "part 2: " << filesystem.part2(70000000, 30000000);

    return 0;
}
