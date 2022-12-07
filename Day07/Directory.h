//
// Created by icas on 12/7/22.
//

#ifndef ADVENT_OF_CODE_DIRECTORY_H
#define ADVENT_OF_CODE_DIRECTORY_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Directory {
public:
    Directory(const string &name, void *parentDirectory);

    string getDirectoryName(){return name;}

    void addDirectory(const string& dirName){subDirectories.emplace_back(dirName, this);}
    void addFile(const string& fileName, unsigned long fileSize);
    void addToSize(unsigned long fileSize){size += fileSize;}

    Directory *getParentDirectory() {return parentDirectory;}
    Directory *getSubDirectory(const string& directoryName){
        for(auto &i: subDirectories){
            if(i.getDirectoryName() == directoryName){return &i;}
        }
        return nullptr;
    }

    uint64_t getSize() const {return size;}

    uint64_t getDirLessThan(const uint64_t MaxSize);
    uint64_t checkDir(const uint64_t minimumSize, uint64_t currentSize = 0);
    void printDirectory(uint8_t level = 0);

private:
    const string name;
    Directory *parentDirectory;
    uint64_t size;

    vector<Directory> subDirectories;
    vector<pair<string, unsigned long>> files;

};


#endif //ADVENT_OF_CODE_DIRECTORY_H
