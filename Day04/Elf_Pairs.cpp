//
// Created by Cederic on 04/12/2022.
//

#include "Elf_pairs.h"

Elf_pairs::Elf_pairs(const string& inputPair) {
    unsigned int pos1;
    pair<string,string> input;

    pos1 = inputPair.find(',');

    input.first = inputPair.substr(0, pos1);
    input.second = inputPair.substr(pos1 + 1);

//    cout << "first: " << input.first << endl << "second: " << input.second << endl;

    pos1 = input.first.find('-');
    unsigned int pos2 = input.second.find('-');

    assignment = {{stoi(input.first.substr(0, pos1)), stoi(input.first.substr(pos1 + 1))},
                  {stoi(input.second.substr(0, pos2)), stoi(input.second.substr(pos2 + 1))}};

//    cout << "did assignment" << endl << endl;
}

bool Elf_pairs::isFullyContained() const {
    if(assignment.first.first <= assignment.second.first && assignment.first.second >= assignment.second.second){return true;}
    if(assignment.first.first >= assignment.second.first && assignment.first.second <= assignment.second.second){return true;}

    return false;
}

bool Elf_pairs::isPartlyContained() const {
    if(assignment.first.first == assignment.second.first || assignment.first.second == assignment.second.second){return true;}
    if(assignment.first.first == assignment.second.second || assignment.first.second == assignment.second.first){return true;}
    if(assignment.first.first < assignment.second.first && assignment.first.second > assignment.second.first){return true;}
    if(assignment.first.first > assignment.second.first && assignment.first.first < assignment.second.second){return true;}

    return false;
}
