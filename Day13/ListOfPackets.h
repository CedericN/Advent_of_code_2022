//
// Created by icas on 12/13/22.
//

#ifndef ADVENT_OF_CODE_LISTOFPACKETS_H
#define ADVENT_OF_CODE_LISTOFPACKETS_H

#include <fstream>
#include <algorithm>
#include "PacketList.h"

using namespace std;

class ListOfPackets {
public:
    explicit ListOfPackets(const string &inputFile);

    uint32_t rightOrder();
    uint32_t distressSignal();


    static bool less(PacketList &obj1, PacketList &obj2){
        return (obj1 == obj2) == PacketList::less;
    }

    void printPackets(){
        for (auto &i : packets) {
            i.first.printPacket();
            cout << endl;
            i.second.printPacket();
            cout << endl << endl;
        }
    }

    void printPacketsDistress(){
        for (auto &i : packetsDistress) {
            i.printPacket();
            cout << endl;
        }
    }

private:
    vector<pair<PacketList,PacketList>> packets;
    vector<PacketList> packetsDistress;
};


#endif //ADVENT_OF_CODE_LISTOFPACKETS_H
