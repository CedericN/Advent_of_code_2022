//
// Created by Cederic on 03/12/2022.
//

#include "Supplies.h"

Supplies::Supplies(string inputFile) {
    ifstream InputFileStream(inputFile);

    string line;

    while(getline(InputFileStream, line)){
        rucksacks.emplace_back(line);
    }
}

unsigned int Supplies::part1() {
    unsigned int returnValue = 0;
    for(auto &i : rucksacks){
        string commonItems = i.getCommonItems();
        for (auto &j : commonItems){
            returnValue += getPriority(j);
        }
    }

    return returnValue;
}

unsigned int Supplies::part2() {
    unsigned int returnValue = 0;
    for(unsigned int i = 0; i < rucksacks.size() - 2; i += 3){
        returnValue += getPriority(getBadge(rucksacks.at(i).getItems(), rucksacks.at(i + 1).getItems(), rucksacks.at(i + 2).getItems()));
    }
    return returnValue;
}

unsigned int Supplies::getPriority(char c) {
    if(c >= 'a' && c <= 'z'){
       return c - 'a' + 1;
    }
    else{
        return c - 'A' + 1 + 26;
    }
    return 0;
}

char Supplies::getBadge(const string& rucksack1, const string& rucksack2, const string& rucksack3) {
    string commonFirst = getCommonChar(rucksack1, rucksack2);
    return getCommonChar(commonFirst, rucksack3, true).front();

}

string Supplies::getCommonChar(const string& input1, const string& input2, bool onlyOne) {
    string returnValue;
    for(auto &i: input1){
        for(auto &j: input2){
            if(i == j){
                if(onlyOne){
                    return {j};
                }
                if(returnValue.find(i) == string::npos){
                    returnValue.push_back(j);
                }
            }
        }
    }

    return returnValue;
}
