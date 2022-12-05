//
// Created by Cederic on 03/12/2022.
//

#include "Match.h"

Match::Match(const string &inputFile) {
    ifstream InputFileStream(inputFile);

    string line;

    while(getline(InputFileStream, line)){
        rounds.emplace_back(pair<char,char> (line.at(0), line.at(2)));
    }

}

pair<unsigned int, unsigned int> Match::getScore() {
    unsigned int score1 = 0;
    unsigned int score2 = 0;



    for(auto &i : rounds){
        score1 += i.getPoints1();
        score2 += i.getPoints2();
    }

    return {score1 , score2};
}
