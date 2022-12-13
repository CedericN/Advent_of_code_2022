#include "ListOfPackets.h"

using namespace std;

int main() {
    string day = DAY;
    day = day.at(0) == '0' ? day.substr(1) : day;
    cout << "One moment please i'm solving day " << day << endl;
    cout << (day.length() < 2 ? "..................................." : "....................................") << endl << endl;

    ListOfPackets packets("input.txt");

    cout << "part 1: " << packets.rightOrder() << endl;
    cout << "part 2: " << packets.distressSignal() << endl;

    return 0;
}
