//
// Created by icas on 12/5/22.
//

#include "Procedure.h"

Procedure::Procedure(string& input) {
    input = input.substr(5);
    unsigned long pos = input.find(' ');
    if(pos != string::npos){
        amount = stoi(input.substr(0, pos));
        input = input.substr(pos + 6);
    }

    pos = input.find(' ');
    if(pos != string::npos){
        from = stoi(input.substr(0, pos)) - 1;
        input = input.substr(pos + 4);
    }

    if(!input.empty()){
        to = stoi(input) - 1;
    }

//    cout << "move " << (int) amount << " crates from " << (int) from + 1 << " to " << (int) to + 1 << endl;
}
