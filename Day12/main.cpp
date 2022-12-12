#include "Map.h"

using namespace std;

int main() {
    string day = DAY;
    day = day.at(0) == '0' ? day.substr(1) : day;
    cout << "One moment please i'm solving day " << day << endl;
    cout << (day.length() < 2 ? "..................................." : "....................................") << endl << endl;

    Map map("input.txt");

    cout << "part 1: " << map.getSteps() << endl;
    cout << "part 2: ";
    map.getTrail();

    return 0;
}
