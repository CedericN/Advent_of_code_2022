//
// Created by icas on 12/7/22.
//

#include "Filesystem.h"

Filesystem::Filesystem(const string& inputFile): rootDirectory("/", nullptr) {
    ifstream InputFileStream(inputFile);

    string line;

    Directory *currentDir = nullptr;

    while(getline(InputFileStream, line)){
        if(line.front() == '$'){
            string command = line.substr(2, 2);
            if(command == "cd"){
                string directoryName = line.substr(5);
//                cout << "change directory to " << directoryName << endl;
                if(directoryName == "/"){
                    currentDir = &rootDirectory;
//                    cout << "go to root directory" << endl;
                }
                else if(directoryName == ".."){
                    currentDir = currentDir->getParentDirectory();
                }
                else{
                    currentDir = currentDir->getSubDirectory(directoryName);
                }
            }
//            else if(command == "ls"){
//                cout << "list directory content" << endl;
//            }
        }
        else{
            uint64_t pos = line.find(' ');
//            cout << "dir or file: " << line.substr(0, pos) << endl;
            if(pos != string::npos){
                if(line.substr(0, pos) == "dir"){
//                    cout << "adding subdirectory: " << line.substr(pos + 1) << endl;
                    currentDir->addDirectory(line.substr(pos + 1));
                }
                else{
//                    cout << "adding file: " << line.substr(pos + 1) << endl;
                    currentDir->addFile(line.substr(pos + 1), stoll(line.substr(0, pos)));
                }
            }
        }
    }

    rootDirectory.printDirectory();
}

uint64_t Filesystem::part2(uint64_t totalSizeFileSystem, uint64_t spaceNeeded) {
    uint64_t minimumSize = totalSizeFileSystem - rootDirectory.getSize();
    return rootDirectory.checkDir(spaceNeeded - minimumSize);
}
