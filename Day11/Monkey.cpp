//
// Created by Cederic on 11/12/2022.
//

#include "Monkey.h"

Monkey::Monkey(vector<string> monkeyData): inspectedItems(0) {
    if(monkeyData.size() != 5){
        cout << (monkeyData.size() < 5 ? "Monkey does not have enough data" : "Monkey has to much data") << endl;
        return;
    }
    else {

//        cout << "hello there" << endl;

        monkeyData.at(0) = monkeyData.at(0).substr(18);
        monkeyData.at(1) = monkeyData.at(1).substr(23);
        monkeyData.at(2) = monkeyData.at(2).substr(21);
        monkeyData.at(3) = monkeyData.at(3).substr(29);
        monkeyData.at(4) = monkeyData.at(4).substr(30);

        uint64_t pos = monkeyData.at(0).find(',');
        while (pos != string::npos){
            items.push_back(stoi(monkeyData.at(0).substr(0, pos)));
            monkeyData.at(0) = monkeyData.at(0).substr(pos + 2);
            pos = monkeyData.at(0).find(',');
        }
        items.push_back(stoi(monkeyData.at(0).substr(0, pos)));

        operation = {(monkeyData.at(1).at(0) == '*'),(monkeyData.at(1).substr(2) == "old" ? 0 : stoi(monkeyData.at(1).substr(2)))};

        testCondition = stoi(monkeyData.at(2));

        test = {stoi(monkeyData.at(3)), stoi(monkeyData.at(4))};

//        printVar();
    }
}

void Monkey::turn(const uint8_t dropWorryLevel, vector<Monkey> &otherMonkeys) {
    for(auto &i: items){
        if(operation.first){
            i *= (operation.second == 0 ?(unsigned long long) i : (unsigned long long) operation.second);
        }
        else{
            i += (operation.second == 0 ? (unsigned long long) i : (unsigned long long) operation.second);
        }
//        cout << i << "\t";
        if(dropWorryLevel != 1){i /= dropWorryLevel;}
//        cout << i << endl;
        otherMonkeys.at((i % testCondition == 0) ? test.first : test.second).addItem((unsigned long long) i);
        inspectedItems ++;
    }
    items.clear();
}

void Monkey::lowerStress(const uint64_t superDivider) {
    for (auto &i: items) {
//        cout << superDivider << endl;
        i %= superDivider;
    }
}
