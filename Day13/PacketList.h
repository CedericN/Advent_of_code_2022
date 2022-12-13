//
// Created by icas on 12/13/22.
//

#ifndef ADVENT_OF_CODE_PACKETLIST_H
#define ADVENT_OF_CODE_PACKETLIST_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class PacketList {
public:
    enum returnOperator{
        less = 1,
        equal = 112,
        greater = 0,
    };

    explicit PacketList(string &input, bool driverPack = false);
    explicit PacketList(uint8_t item);

    returnOperator operator == (PacketList &obj);

    bool isDriverPackage() const {return driverPackage;}

    void printPacket(bool first = true){
        if(!first){cout << ",";}
        if(list){
            cout << "[";
            for(uint32_t i = 0; i < containingLists.size(); ++i){
                containingLists.at(i).printPacket(i == 0);
            }
            cout << "]";
        }
        else{
            cout << (int) item;
        }
    }

private:
    bool driverPackage;
    bool list;
    vector<PacketList> containingLists;
    uint8_t item;
};


#endif //ADVENT_OF_CODE_PACKETLIST_H
