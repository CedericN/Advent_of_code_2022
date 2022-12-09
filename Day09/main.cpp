#include "Bridge.h"

using namespace std;

int main() {
    string day = DAY;
    day = day.at(0) == '0' ? day.substr(1) : day;
    cout << "One moment please i'm solving day " << day << endl;
    cout << (day.length() < 2 ? "..................................." : "....................................") << endl << endl;

    Bridge bridge("input.txt");

    cout << "part 1: " << bridge.getTailVisits() << endl;
    cout << "part 2: " << bridge.getTailVisits(9) << endl;
    return 0;
}
