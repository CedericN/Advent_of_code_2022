#include "Valves.h"

using namespace std;

int main() {
    string day = DAY;
    day = day.at(0) == '0' ? day.substr(1) : day;
    cout << "One moment please i'm solving day " << day << endl;
    cout << (day.length() < 2 ? "..................................." : "....................................") << endl << endl;

    Valves valves("input.txt");

    cout << "part 1: " << valves.getPressure(false, 30) << endl;
    cout << "part 2: " << valves.getPressure(true, 26) << endl;

    return 0;
}
