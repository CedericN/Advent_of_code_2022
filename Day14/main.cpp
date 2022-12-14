#include "Cave.h"

using namespace std;

int main() {
    string day = DAY;
    day = day.at(0) == '0' ? day.substr(1) : day;
    cout << "One moment please i'm solving day " << day << endl;
    cout << (day.length() < 2 ? "..................................." : "....................................") << endl << endl;

    Cave cave("input.txt");

//    cave.printCave();

    cout << "part 1: " << cave.fillCave() << endl;
    cout << "part 2: " << cave.fillCave(false) << endl;

    return 0;
}
