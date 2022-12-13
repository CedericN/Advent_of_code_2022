//
// Created by icas on 12/13/22.
//

#include "ListOfPackets.h"

ListOfPackets::ListOfPackets(const string &inputFile) {
    ifstream InputFileStream(inputFile);
    string line;

    PacketList *firstPacket = nullptr;
    PacketList *secondPacket = nullptr;

    bool first = true;

    while(getline(InputFileStream, line)){
        if(!line.empty()){
            if(first){
                first = false;
                string tmp = line.substr(1, line.size() - 2);
                firstPacket = new PacketList(tmp);
                packetsDistress.push_back(*firstPacket);
            }
            else{
                string tmp = line.substr(1, line.size() - 2);
                secondPacket = new PacketList(tmp);
                packetsDistress.push_back(*secondPacket);
            }
        }
        else{
            if(firstPacket != nullptr && secondPacket != nullptr){
                packets.emplace_back(*firstPacket, *secondPacket);
            }
            else{
                cout << "yeah you did something wrong" << endl;
            }
            first = true;
            firstPacket = nullptr;
            secondPacket = nullptr;
        }
    }
    if(firstPacket != nullptr && secondPacket != nullptr){
        packets.emplace_back(*firstPacket, *secondPacket);
    }
    else{
        cout << "yeah you did something wrong" << endl;
    }
    string tmp = "[[2]]";
    packetsDistress.emplace_back(tmp, true);
    tmp = "[[6]]";
    packetsDistress.emplace_back(tmp, true);

//    printPackets();
}

uint32_t ListOfPackets::rightOrder() {
//    cout << endl;

     uint32_t counter = 0;
    for (uint32_t i = 0; i < packets.size(); ++i) {
        PacketList::returnOperator checkValue = packets.at(i).first == packets.at(i).second;
        if((checkValue) == PacketList::less){
            counter += i + 1;
        }
//        cout << (int) checkValue << endl << endl;
    }
    return counter;
}

uint32_t ListOfPackets::distressSignal() {
    sort(packetsDistress.begin(), packetsDistress.end(), less);
//    printPacketsDistress();
    uint32_t returnValue = 1;
    for (uint32_t i = 0; i < packetsDistress.size(); ++i) {
        if(packetsDistress.at(i).isDriverPackage()){
            returnValue *= (i + 1);
        }
    }
    return returnValue;
}
