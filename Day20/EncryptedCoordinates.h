//
// Created by icas on 12/20/22.
//

#ifndef ADVENT_OF_CODE_ENCRYPTEDCOORDINATES_H
#define ADVENT_OF_CODE_ENCRYPTEDCOORDINATES_H

#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class EncryptedCoordinates {
public:
    EncryptedCoordinates(const string &inputFile);

    int64_t decryptLocation(uint8_t iterations = 1, int32_t decryptionKey = 1);
private:
    void printData(vector<pair<pair<bool, uint16_t>, int32_t>> locationData, int64_t decryptionKey){
        for (int i = 0; i < locationData.size(); ++i) {
            int64_t dataTmp = 0;
            for(auto &j: locationDataInput){
                if(j.first.second == locationData[i].first.second){
                    dataTmp = (int64_t) j.second * decryptionKey;
                    break;
                }
            }
            cout << dataTmp << (i == locationData.size() -1 ? "\r\n" : ", ");
        }
    }

    vector<pair<pair<bool, uint16_t>, int32_t>> locationDataInput;
};


#endif //ADVENT_OF_CODE_ENCRYPTEDCOORDINATES_H
