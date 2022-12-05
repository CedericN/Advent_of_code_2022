//
// Created by Cederic on 03/12/2022.
//

#include "Rucksack.h"

Rucksack::Rucksack(string contains) {
    compartments.first.clear();
    compartments.first.clear();
    for(unsigned int i = 0; i < contains.size(); i ++){
        i < contains.size()/2 ? compartments.first.push_back(contains.at(i)) : compartments.second.push_back(contains.at(i));
    }

//    cout << "first compartment: " << compartments.first << endl;
//    cout << "second compartment: " << compartments.second << endl << endl;

}

string Rucksack::getCommonItems() {
    string returnValue;
    for(auto &i : compartments.first){
        for (auto &j : compartments.second){
            if(i == j && returnValue.find(i) == string::npos){returnValue.push_back(i);}
        }
    }
    return returnValue;
}
