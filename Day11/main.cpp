#include "Monkeys.h"

using namespace std;

int main() {
    string day = DAY;
    day = day.at(0) == '0' ? day.substr(1) : day;
    cout << "One moment please i'm solving day " << day << endl;
    cout << (day.length() < 2 ? "..................................." : "....................................") << endl << endl;

    Monkeys monkeys("input.txt");

    cout << "part 1: " << monkeys.getLevelOfMonkeyBusiness(20, 3, false) << endl;
    cout << "part 2: " << monkeys.getLevelOfMonkeyBusiness(10000, 1, false) << endl;

    return 0;
}
