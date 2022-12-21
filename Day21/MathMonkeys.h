//
// Created by icas on 12/21/22.
//

#ifndef ADVENT_OF_CODE_MONKEYS_H
#define ADVENT_OF_CODE_MONKEYS_H

#include <list>
#include <iostream>
#include <map>
#include <fstream>

using namespace std;

class MathMonkeys {
public:
    enum operators{
        add = '+',
        subtract = '-',
        multiply = '*',
        divide = '/',
    };

    struct DumbMonkey{
        string name;
        pair<string, string> operands;
        operators localOperator;
    };

    explicit MathMonkeys(const string &inputFile);

    int64_t calculateRoot();
    int64_t calculateHumn();

private:
    static void printMonkeys(const list<DumbMonkey>& dumbMonkeys, const map<string, int64_t>& smartMonkeys){
        if(!smartMonkeys.empty()){
            cout << endl << "smart monkeys: " << endl;
            for (auto &i: smartMonkeys) {
                cout << "\t name: " << i.first << "\t\tvalue: " << i.second << endl;
            }
        }
        else{cout << "I feel really dumb around only stupid monkeys" << endl;}

        if(!dumbMonkeys.empty()){
            cout << "dumb monkeys: " << endl;
            for (auto &i: dumbMonkeys) {
                cout << "\t" << i << endl;
            }
        } else{
            cout << "dammm only smart monkeys" << endl;
        }
    }

    static void printMonkeys(const map<string, DumbMonkey>& dumbMonkeys, const map<string, int64_t>& smartMonkeys){
        if(!smartMonkeys.empty()){
            cout << endl << "smart monkeys: " << endl;
            for (auto &i: smartMonkeys) {
                cout << "\t name: " << i.first << "\t\tvalue: " << i.second << endl;
            }
        }
        else{cout << "I feel really dumb around only stupid monkeys" << endl;}

        if(!dumbMonkeys.empty()){
            cout << "dumb monkeys: " << endl;
            for (auto &i: dumbMonkeys) {
                cout << "\t" << i.second << endl;
            }
        } else{
            cout << "dammm only smart monkeys" << endl;
        }
    }

    list<DumbMonkey> dumbMonkeysInitial;
    map<string, int64_t> smartMonkeysInitial;

    friend ostream& operator << (ostream &os, const MathMonkeys::DumbMonkey &monk);
};

ostream& operator << (ostream &os, const MathMonkeys::DumbMonkey &monk);

#endif //ADVENT_OF_CODE_MONKEYS_H
