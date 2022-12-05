#include "Match.h"

using namespace std;

int main() {
    string day = DAY;
    day = day.at(0) == '0' ? day.substr(1) : day;
    cout << "One moment please i'm solving day " << day << endl;
    cout << (day.length() < 2 ? "..................................." : "....................................") << endl << endl;
    
    Match match("input.txt");

    pair<unsigned int, unsigned int> result = match.getScore();
    cout << "part 1: " << result.first << endl;
    cout << "part 2: " << result.second << endl;
    return 0;
}
