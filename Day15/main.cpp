#include "Sensors_and_Beacons.h"

using namespace std;

int main() {
    string day = DAY;
    day = day.at(0) == '0' ? day.substr(1) : day;
    cout << "One moment please i'm solving day " << day << endl;
    cout << (day.length() < 2 ? "..................................." : "....................................") << endl << endl;

    Sensors_and_Beacons sensorsAndBeacons("input.txt");

    cout << "part 1: " << sensorsAndBeacons.getBeaconNotPossible(2000000) << endl;
    cout << "part 1: " << sensorsAndBeacons.getDistressBeacon({0, 0}, {4000000, 4000000}, 4000000) << endl;

    return 0;
}
