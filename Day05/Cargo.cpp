//
// Created by icas on 12/5/22.
//

#include "Cargo.h"

Cargo::Cargo(const string& inputFile) {
    ifstream InputFileStream(inputFile);

    string line;
    vector<string> tmp;
    bool CrateStart = true;

    while(getline(InputFileStream, line)){
        if(line.size() < 3){
            CrateStart = false;
        }
        else if (CrateStart){
            tmp.push_back(line);
        }
        else{
            craneProcedure.emplace_back(line);
        }
    }

    parseCrateStart(tmp);
}

void Cargo::parseCrateStart(vector<string>& cargoStart){
    cargoStart.pop_back();
    int height = (int) cargoStart.size();
    int stacks = 0;
    for(int i = height - 1; i >= 0; i --){
        int currentStack = 0;
        string tmp = cargoStart.at(i);
        tmp = tmp.substr(1);
        unsigned long pos = tmp.find(']');
        while(pos != string::npos){
            if(i == height - 1){
                cargoArrangement.emplace_back(tmp.substr(0,1));
                stacks ++;
            }
            else{
                while(pos > 3 && pos != string::npos){
                    if(tmp.size() > 3){
                        tmp = tmp.substr(1 + 3);
                        pos = tmp.find(']');
                        currentStack ++;
                    }
                    else{
                        pos = string::npos;
                    }
                }
                cargoArrangement.at(currentStack).push_back(tmp.at(0));
            }

            if(tmp.size() > pos + 3){
                tmp = tmp.substr(pos + 3);
                pos = tmp.find(']');
                currentStack ++;
            }
            else{
                pos = string::npos;
            }
        }
    }
    cargoArrangementCopy = cargoArrangement;
//    printCrates();
}

void Cargo::moveCrates9000() {
    for(auto &i: craneProcedure){
        for(unsigned char j = 0; j < i.getAmount(); j++){
            cargoArrangement.at(i.getTo()).push_back(cargoArrangement.at(i.getFrom()).back());
            cargoArrangement.at(i.getFrom()).pop_back();
        }
    }
//    printCrates();

}

void Cargo::moveCrates9001() {
    for(auto &i: craneProcedure){
        for(unsigned char j = i.getAmount(); j > 0; j--){
            cargoArrangementCopy.at(i.getTo()).push_back(cargoArrangementCopy.at(i.getFrom()).at(cargoArrangementCopy.at(i.getFrom()).size() - j));
        }
        cargoArrangementCopy.at(i.getFrom()) = cargoArrangementCopy.at(i.getFrom()).substr(0, cargoArrangementCopy.at(i.getFrom()).size() - i.getAmount());

    }

//    printCrates(true);
}

void Cargo::printCrates(bool copy) {
    cout << "printing crates" << endl;
    vector<string> &cargoArrangementTmp = copy ? cargoArrangementCopy : cargoArrangement;
    int height = 0;
    for (auto &i : cargoArrangementTmp){
        if(height < i.size()){height = (int) i.size();}
    }

    for(int i = height - 1; i >= 0; i --){
        for (auto &j : cargoArrangementTmp){
            cout << (j.size() < (i + 1) ? ' ' : j.at(i)) << " ";
        }

        cout << endl;
    }

}
