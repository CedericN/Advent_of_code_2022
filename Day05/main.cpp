#include "Cargo.h"

using namespace std;

int main() {
    string day = DAY;
    day = day.at(0) == '0' ? day.substr(1) : day;
    cout << "One moment please i'm solving day " << day << endl;
    cout << (day.length() < 2 ? "..................................." : "....................................") << endl << endl;

    Cargo cargo("input.txt");
    cargo.moveCrates9000();
    cargo.moveCrates9001();

    cout << "part 1: " << cargo.getTopCrates() << endl;
    cout << "part 2: " << cargo.getTopCrates(true) << endl;

    return 0;
}
