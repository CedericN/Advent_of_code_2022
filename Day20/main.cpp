#include "EncryptedCoordinates.h"

using namespace std;

int main() {
    string day = DAY;
    day = day.at(0) == '0' ? day.substr(1) : day;
    cout << "One moment please i'm solving day " << day << endl;
    cout << (day.length() < 2 ? "..................................." : "....................................") << endl << endl;

    EncryptedCoordinates encryptedCoordinates("input.txt");

    cout << "part 1: " << encryptedCoordinates.decryptLocation() << endl;
    cout << "part 2: " << (int64_t) encryptedCoordinates.decryptLocation(10, 811589153) << endl;

    return 0;
}
