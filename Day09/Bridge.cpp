//
// Created by icas on 12/9/22.
//

#include "Bridge.h"

Bridge::Bridge(const string &inputFile): posH(0,0){
    ifstream InputFileStream(inputFile);
    string line;

    for (int i = 0; i < 9; ++i) {
        posT.push_back({{0,0}});
    }
    
    while(getline(InputFileStream, line)){
        commands.emplace_back(line.at(0), stoi(line.substr(2)));
        updateTailPosition(commands.back().first, commands.back().second);
    }

}

uint32_t Bridge::getTailVisits(uint8_t knots) {
    set<pair<int32_t, int32_t>> posTTmp;
    for(auto &i: posT.at(knots - 1)){
        posTTmp.insert({i.first, i.second});
    }
    posT.at(knots - 1).assign(posTTmp.begin(), posTTmp.end());
    return posT.at(knots - 1).size();
}

void Bridge::updateTailPosition(char direction, uint8_t amount) {
    for (uint8_t i = 0; i < amount; i++) {
        switch (direction) {
            case 'R':
                posH.first = posH.first + 1;
                break;
            case 'L':
                posH.first = posH.first - 1;
                break;
            case 'U':
                posH.second = posH.second + 1;
                break;
            case 'D':
                posH.second = posH.second - 1;
                break;
            default:
                cout << "well asshole i cant move that way: " << direction << endl;
        }

        for (int j = 0; j < 9; j++) {
            if(abs(posT.at(j).back().first - (j == 0 ? posH.first : posT.at(j - 1).back().first)) <= 1 && abs(posT.at(j).back().second - (j == 0 ? posH.second : posT.at(j - 1).back().second)) <= 1 ){
                continue;
            }

            if (abs(posT.at(j).back().second - (j == 0 ? posH.second : posT.at(j - 1).back().second)) == 0){
                posT.at(j).emplace_back(posT.at(j).back().first > (j == 0 ? posH.first : posT.at(j - 1).back().first) ? posT.at(j).back().first - 1 : posT.at(j).back().first + 1, posT.at(j).back().second);
            }
            else if (abs(posT.at(j).back().first - (j == 0 ? posH.first : posT.at(j - 1).back().first)) == 0){
                posT.at(j).emplace_back(posT.at(j).back().first, posT.at(j).back().second > (j == 0 ? posH.second : posT.at(j - 1).back().second) ? posT.at(j).back().second - 1 : posT.at(j).back().second + 1);
            }
            else {
                posT.at(j).emplace_back(posT.at(j).back().first > (j == 0 ? posH.first : posT.at(j - 1).back().first) ? posT.at(j).back().first - 1 : posT.at(j).back().first + 1, posT.at(j).back().second > (j == 0 ? posH.second : posT.at(j - 1).back().second) ? posT.at(j).back().second - 1 : posT.at(j).back().second + 1);
            }
        }
    }
}
