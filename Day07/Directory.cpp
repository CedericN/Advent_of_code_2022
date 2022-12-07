//
// Created by icas on 12/7/22.
//

#include "Directory.h"

Directory::Directory(const string &name, void *parentDirectory) : name(name), parentDirectory(static_cast<Directory *>(parentDirectory)), size(0) {}

void Directory::addFile(const string& fileName, unsigned long fileSize) {
    files.emplace_back(fileName, fileSize);
    size += fileSize;
    if(getDirectoryName() != "/"){
        Directory *tmpDir = parentDirectory;
        bool inRootFolder = false;
        while(!inRootFolder){
            inRootFolder = (tmpDir->getDirectoryName() == "/");
            tmpDir->addToSize(fileSize);
            tmpDir = tmpDir->getParentDirectory();
        }
    }
}

uint64_t Directory::getDirLessThan(const uint64_t MaxSize) {
    uint64_t returnSize = 0;
    if(size <= MaxSize){returnSize += size;}
    for(auto &i : subDirectories){
        returnSize += i.getDirLessThan(MaxSize);
    }
    return returnSize;
}

uint64_t Directory::checkDir(const uint64_t minimumSize, uint64_t currentSize) {
    uint64_t returnSize = currentSize == 0 ? size : currentSize;
    if(size >= minimumSize && size < returnSize){returnSize = size;}
    for(auto &i : subDirectories){
        returnSize = i.checkDir(minimumSize, returnSize);
    }
    return returnSize;
}

void Directory::printDirectory(uint8_t level) {
    string indent;
    for(uint8_t i = 0; i < 2 * level; i ++){
        indent += ' ';
    }

    cout << indent << "\033[1;34m- " << name << " (" << size << ")\033[0m" << endl;

    for(auto &i : subDirectories){
        i.printDirectory(level + 1);
    }
    indent += "  ";
    for(auto &i : files){
        cout << indent << "- " << i.first << " (" << i.second << ")" << endl;
    }
}
