//
// Created by icas on 12/8/22.
//

#include "Forest.h"

Forest::Forest(const string& inputFile) {
    ifstream InputFileStream(inputFile);
    string line;

    while(getline(InputFileStream, line)){
        vector<Tree> rowTmp;
        while(!line.empty()){
            rowTmp.emplace_back(stoi(line.substr(0, 1)));
            line = !line.empty() ? line.substr(1) : "";
        }
        trees.push_back(rowTmp);
    }

    updateVisibility();
//    printVisibility();
}

uint32_t Forest::getVisibleTrees() {
    uint32_t returnValue = 0;
    for(auto &i: trees){
        for(auto &j:i){
            returnValue += j.isVisible();
        }
    }
    return returnValue;
}

void Forest::updateVisibility() {
    for(auto &i : trees.front()){
        i.setVisible(true);
    }

    for(auto &i : trees.back()){
        i.setVisible(true);
    }

    for(auto &i : trees){
        i.front().setVisible(true);
        i.back().setVisible(true);
    }

    for(uint32_t i = 1 ; i < trees.size() - 1; i ++){
        for (uint32_t j = 1; j < trees.at(i).size() - 1; j ++) {
            trees.at(i).at(j).setVisible(checkTree(i,j,trees.at(i).at(j).getHeight()));
            trees.at(i).at(j).setScenicScore(updateScenicScore(i,j,trees.at(i).at(j).getHeight()));
        }
    }
}

bool Forest::checkTree(uint32_t row, uint32_t colm, uint32_t height) {
    bool visible = true;
    for(uint32_t i = 0; i < colm && visible; i ++){
        if(trees.at(row).at(i).getHeight() >= height){
//            cout << "row: " << row << "\tcolm: " << colm << "\theight: " << (int) trees.at(row).at(i).getHeight() << "\tref: " << height << endl;
            visible = false;
        }
    }

    if(visible){return true;}
    visible = true;

    for(uint32_t i = colm + 1; i < trees.at(row).size() && visible; i ++){
        if(trees.at(row).at(i).getHeight() >= height){
//            cout << "row: " << row << "\tcolm: " << colm << "\theight: " << (int) trees.at(row).at(i).getHeight() << "\tref: " << height << endl;
            visible = false;
        }
    }

    if(visible){return true;}
    visible = true;

    for(uint32_t i = 0; i < row  && visible; i ++){
        if(trees.at(i).at(colm).getHeight() >= height){
//            cout << "row: " << row << "\tcolm: " << colm << "\theight: " << (int) trees.at(i).at(colm).getHeight() << "\tref: " << height << endl;
            visible = false;
        }
    }

    if(visible){return true;}
    visible = true;

    for(uint32_t i = row + 1; i < trees.size() && visible; i ++){
        if(trees.at(i).at(colm).getHeight() >= height){
//            cout << "row: " << row << "\tcolm: " << colm << "\theight: " << (int) trees.at(i).at(colm).getHeight() << "\tref: " << height << endl;
            visible = false;
        }
    }

    return visible;
}

void Forest::printVisibility() {
    for(auto &i: trees){
        for(auto &j:i){
            cout << (j.isVisible() ? "1 " : "0 ");
        }
        cout << endl;
    }
}

uint32_t Forest::updateScenicScore(uint32_t row, uint32_t colm, uint32_t height) {
    vector<uint32_t> points {0,0,0,0};

    for(int32_t i = (int) colm - 1; i >= 0; i --){
        points.at(0) ++;
        if(trees.at(row).at(i).getHeight() >= height){
            break;
        }
    }

    for(int32_t i = (int) colm + 1; i < trees.at(row).size(); i ++){
        points.at(1) ++;
        if(trees.at(row).at(i).getHeight() >= height){
            break;
        }
    }

    for(int32_t i = (int) row - 1; i >= 0; i --){
        points.at(2) ++;
        if(trees.at(i).at(colm).getHeight() >= height){
            break;
        }
    }

    for(int32_t i = (int) row + 1; i < trees.size(); i ++){
        points.at(3) ++;
        if(trees.at(i).at(colm).getHeight() >= height){
            break;
        }
    }

    uint32_t totalPoints = points.at(0) * points.at(1) * points.at(2) * points.at(3);

//    cout << points.at(0) << " * " << points.at(1) << " * " << points.at(2) << " * " << points.at(3) << " = " << totalPoints << endl;

    return totalPoints;
}

uint32_t Forest::getHighestScenicScore() {
    uint32_t returnValue = 0;
    for(auto &i: trees){
        for(auto &j:i){
            if(returnValue < j.getScenicScore()){returnValue = j.getScenicScore();}
        }
    }
    return returnValue;
}
