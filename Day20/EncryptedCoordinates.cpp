//
// Created by icas on 12/20/22.
//

#include "EncryptedCoordinates.h"

EncryptedCoordinates::EncryptedCoordinates(const string &inputFile) {
    ifstream InputFileStream(inputFile);
    string line;

    while (getline(InputFileStream, line)) {
        locationDataInput.emplace_back(pair<bool, uint16_t>(false, locationDataInput.size()), stoi(line));
    }
}

int64_t EncryptedCoordinates::decryptLocation(uint8_t iterations, int32_t decryptionKey) {
    vector<pair<pair<bool, uint16_t>, int32_t>> locationData = locationDataInput;
    int32_t decryptionKeyMod = decryptionKey;
    while (decryptionKeyMod / (int) locationData.size() > 0) {
        decryptionKeyMod = (decryptionKeyMod % (int) locationData.size()) + (decryptionKeyMod / (int) locationData.size());
    }
    for (auto &i: locationData) {
        i.second *= decryptionKeyMod;

    }

//    printData(locationData, decryptionKey);
    for(uint8_t iterationsCounter = 0; iterationsCounter < iterations; ++iterationsCounter){
        for (auto &i: locationData) {
            i.first.first = false;
        }
        uint16_t stepCounter = 0;
        while (stepCounter < locationData.size()) {
            for (uint32_t i = 0; i < locationData.size(); ++i) {
                if (locationData.at(i).first.second == stepCounter && !locationData.at(i).first.first) {
                    locationData[i].first.first = true;
                    const pair<pair<bool, uint16_t>, int32_t> dataTmp = locationData[i];
                    int index = (int) i + locationData[i].second;
                    while (index < 0) {
                        index = ((int) locationData.size()) - abs(index) - 1;
                    }
                    if (index == 0) { index = (int) locationData.size() - 1; }
                    while (index / (int) locationData.size() > 0) {
                        index = (index % (int) locationData.size()) + (index / (int) locationData.size());
                    }
                    if (index >= locationData.size() || index < 0) { cout << "error index: " << index << endl; }
                    if (i != index) {
                        locationData.erase(locationData.begin() + i);
                        locationData.insert(locationData.begin() + index, dataTmp);
                    }

                    i--;
                    stepCounter++;
                }
            }
        }
//        printData(locationData, decryptionKey);
    }

    for (uint32_t i = 0; i < locationData.size(); ++i) {
        if(!locationData.at(i).first.first){cout << "helppp: "<< i << "is not done \t value: " << locationData.at(i).second << endl;}
    }

    vector<uint32_t> coordPos = {1000, 2000, 3000};

    for (int i = 0; i < locationData.size(); ++i) {
        if(locationData[i].second == 0){
            for(auto &j: coordPos){
                j += i;
            }
            break;
        }
    }

    for (auto &index: coordPos) {
        if(index/(int) locationData.size() > 0){
            index = (index % (int) locationData.size());
        }
/*
        int64_t dataTmp = 0;
        for(auto &j: locationDataInput){
            if(j.first.second == locationData[index].first.second){
                dataTmp = (int64_t) j.second * decryptionKey;
                break;
            }
        }
        cout << index << ": " << (int64_t) dataTmp << endl;
*/
    }

    int64_t returnValue = 0;

    for (auto &index: coordPos) {
        int64_t dataTmp = 0;
        for(auto &j: locationDataInput){
            if(j.first.second == locationData[index].first.second){
                dataTmp = (int64_t) j.second * decryptionKey;
                break;
            }
        }
        returnValue += dataTmp;
    }

    return returnValue;
}
