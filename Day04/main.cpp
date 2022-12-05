#include "Assignments.h"

using namespace std;

int main() {
    string day = DAY;
    day = day.at(0) == '0' ? day.substr(1) : day;
    cout << "One moment please i'm solving day " << day << endl;
    cout << (day.length() < 2 ? "..................................." : "....................................") << endl << endl;

    Assignments assignments("input.txt");

    pair<unsigned int, unsigned int> solution = assignments.solve();

    cout << "part 1: " << solution.first << endl;
    cout << "part 2: " << solution.second << endl;

    return 0;
}
