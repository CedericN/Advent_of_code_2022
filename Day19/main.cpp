#include "Robots.h"

using namespace std;

int main() {
    string day = DAY;
    day = day.at(0) == '0' ? day.substr(1) : day;
    cout << "One moment please i'm solving day " << day << endl;
    cout << (day.length() < 2 ? "..................................." : "....................................") << endl << endl;

    Robots robots("input.txt");

    cout << "part 1: " << robots.getOptimalBlueprint(24) << endl;
    cout << "part 2: " << robots.getOptimalBlueprint(32) << endl;

    return 0;
}
