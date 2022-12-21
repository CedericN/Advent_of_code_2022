#include "MathMonkeys.h"

using namespace std;

int main() {
    string day = DAY;
    day = day.at(0) == '0' ? day.substr(1) : day;
    cout << "One moment please i'm solving day " << day << endl;
    cout << (day.length() < 2 ? "..................................." : "....................................") << endl << endl;

    MathMonkeys mathMonkeys("input.txt");

    cout << "part 1: " << mathMonkeys.calculateRoot() << endl;
    cout << "part 2: " << mathMonkeys.calculateHumn() << endl;

    return 0;
}
