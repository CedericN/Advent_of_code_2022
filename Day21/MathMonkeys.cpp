//
// Created by icas on 12/21/22.
//

#include "MathMonkeys.h"

MathMonkeys::MathMonkeys(const string &inputFile) {
    ifstream InputFileStream(inputFile);
    string line;

    while (getline(InputFileStream, line)) {
        uint64_t pos = line.find(':');
        if(pos == string::npos){cout << ": not found" << endl; continue;}
        string name = line.substr(0,pos);
        line = line.substr(pos + 2);
        if(line.front() >= '0' && line.front() <= '9'){
            if(smartMonkeysInitial.find(name) == smartMonkeysInitial.end()){
                smartMonkeysInitial[name] = stoi(line);
            }
            else{
                cout << "i already have seen that monkey" << endl;
            }
        }
        else{
            DumbMonkey waitingMonkey;
            waitingMonkey.name = name;
            waitingMonkey.operands.first = line.substr(0, 4);
            waitingMonkey.operands.second = line.substr(7, 4);
            waitingMonkey.localOperator = operators(line.at(5));
            dumbMonkeysInitial.push_back(waitingMonkey);
        }
    }
}

int64_t MathMonkeys::calculateRoot() {
    list<DumbMonkey> dumbMonkeys = dumbMonkeysInitial;
    map<string, int64_t> smartMonkeys = smartMonkeysInitial;
    uint32_t prevSize = dumbMonkeys.size();
    while(!dumbMonkeys.empty()){
        for(uint32_t i = 0; i < dumbMonkeys.size(); ++i){
            DumbMonkey *localDumb = &dumbMonkeys.front();
            if (smartMonkeys.find(localDumb->operands.first) != smartMonkeys.end() && smartMonkeys.find(localDumb->operands.second) != smartMonkeys.end()) {
                int64_t value;
                pair<int64_t, int64_t> operands{smartMonkeys[localDumb->operands.first], smartMonkeys[localDumb->operands.second]};
                switch (localDumb->localOperator) {
                    case add:
                        value = operands.first + operands.second;
                        break;
                    case subtract:
                        value = operands.first - operands.second;
                        break;
                    case multiply:
                        value = operands.first * operands.second;
                        break;
                    case divide:
                        value = operands.first / operands.second;
                        break;
                }

                if (localDumb->name == "root") {
                    return value;
                }

                if (smartMonkeys.find(localDumb->name) == smartMonkeys.end()) {
                    smartMonkeys[localDumb->name] = value;
                } else {
                    cout << "why am I calculating I already have that monkey" << endl;
                }
                dumbMonkeys.pop_front();
            }
            else {
                dumbMonkeys.push_back(dumbMonkeys.front());
                dumbMonkeys.pop_front();
            }
        }

        if(prevSize == dumbMonkeys.size()){
//            printMonkeys(dumbMonkeys, smartMonkeys);
            dumbMonkeysInitial = dumbMonkeys;
            smartMonkeysInitial = smartMonkeys;
            return 0;
        }
        else{
            prevSize = dumbMonkeys.size();
        }
    }
    cout << "something is wrong" << endl;
    return 112;
}

int64_t MathMonkeys::calculateHumn() {

    if(smartMonkeysInitial.find("humn") != smartMonkeysInitial.end()){
        smartMonkeysInitial.erase("humn");
    }
    else{
        cout << "f***" << endl;
    }

    calculateRoot();

    map<string, DumbMonkey> dumbMonkey;

    for(auto &i: dumbMonkeysInitial){
        if(dumbMonkey.find(i.name) == dumbMonkey.end()){
            dumbMonkey[i.name] = i;
        }
        else{
            cout << "crapp I know that monkey already";
        }
    }

    int64_t value = 0;
    string currentName;

    if(smartMonkeysInitial.find(dumbMonkey["root"].operands.first) != smartMonkeysInitial.end()){
        value = smartMonkeysInitial[dumbMonkey["root"].operands.first];
        currentName = dumbMonkey["root"].operands.second;
    }
    else if(smartMonkeysInitial.find(dumbMonkey["root"].operands.second) != smartMonkeysInitial.end()){
        value = smartMonkeysInitial[dumbMonkey["root"].operands.second];
        currentName = dumbMonkey["root"].operands.first;
    }
    else{
        cout << "GVD i could not solve root" << endl;
    }


    while(currentName != "humn"){
        switch (dumbMonkey[currentName].localOperator) {
            case add:
                if(smartMonkeysInitial.find(dumbMonkey[currentName].operands.first) != smartMonkeysInitial.end()){
                    value -= smartMonkeysInitial[dumbMonkey[currentName].operands.first];
                    currentName = dumbMonkey[currentName].operands.second;
                }
                else if(smartMonkeysInitial.find(dumbMonkey[currentName].operands.second) != smartMonkeysInitial.end()){
                    value -= smartMonkeysInitial[dumbMonkey[currentName].operands.second];
                    currentName = dumbMonkey[currentName].operands.first;
                }
                else{
                    cout << "f*** cant solve subtract" << endl;
                }
                break;
            case subtract:
                if(smartMonkeysInitial.find(dumbMonkey[currentName].operands.first) != smartMonkeysInitial.end()){
                    value = smartMonkeysInitial[dumbMonkey[currentName].operands.first] - value;
                    currentName = dumbMonkey[currentName].operands.second;
                }
                else if(smartMonkeysInitial.find(dumbMonkey[currentName].operands.second) != smartMonkeysInitial.end()){
                    value += smartMonkeysInitial[dumbMonkey[currentName].operands.second];
                    currentName = dumbMonkey[currentName].operands.first;
                }
                else{
                    cout << "f*** cant solve subtract" << endl;
                }
                break;
            case multiply:
                if(smartMonkeysInitial.find(dumbMonkey[currentName].operands.first) != smartMonkeysInitial.end()){
                    value /= smartMonkeysInitial[dumbMonkey[currentName].operands.first];
                    currentName = dumbMonkey[currentName].operands.second;
                }
                else if(smartMonkeysInitial.find(dumbMonkey[currentName].operands.second) != smartMonkeysInitial.end()){
                    value /= smartMonkeysInitial[dumbMonkey[currentName].operands.second];
                    currentName = dumbMonkey[currentName].operands.first;
                }
                else{
                    cout << "f*** cant solve multiply" << endl;
                }
                break;
            case divide:
                if(smartMonkeysInitial.find(dumbMonkey[currentName].operands.first) != smartMonkeysInitial.end()){
                    value = smartMonkeysInitial[dumbMonkey[currentName].operands.first] / value;
                    currentName = dumbMonkey[currentName].operands.second;
                }
                else if(smartMonkeysInitial.find(dumbMonkey[currentName].operands.second) != smartMonkeysInitial.end()){
                    value *= smartMonkeysInitial[dumbMonkey[currentName].operands.second];
                    currentName = dumbMonkey[currentName].operands.first;
                }
                else{
                    cout << "f*** cant solve divide" << endl;
                }
                break;
        }
    }

//    printMonkeys(dumbMonkey, smartMonkeysInitial);
//    cout << "value: " << value << endl;

    return value;
}

ostream& operator << (ostream &os, const MathMonkeys::DumbMonkey &monk){
    os << "name: " << monk.name << "\toperation: " << monk.operands.first << " " << (char) monk.localOperator << " " << monk.operands.second;
    return os;
}
