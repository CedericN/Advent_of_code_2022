//
// Created by icas on 12/1/22.
//

#include "Elves.h"

Elves::Elves(const string& inputFile) {
    ifstream InputFileStream(inputFile);

    string line;
    vector<int> foodTmp;


    while(getline(InputFileStream, line)){
        if(line.empty()){
            listOfElves.emplace_back(foodTmp);
            foodTmp.clear();
        }
        else{
            foodTmp.push_back(stoi(line));
        }
    }
    listOfElves.emplace_back(foodTmp);
    sort(listOfElves.begin(), listOfElves.end(), sortElves);
}

int Elves::getPart1() const {
//    int tmp = 0;
//    for(auto i : listOfElves){
//        if(i.getTotal() > tmp) {tmp = i.getTotal();}
//    }

    return listOfElves.back().getTotal();
}

int Elves::getPart2() const {
    if(listOfElves.size() < 3){
//        return 0;
    }
    return listOfElves.back().getTotal() + listOfElves.at(listOfElves.size()-2).getTotal() + listOfElves.at(listOfElves.size()-3).getTotal();
}

