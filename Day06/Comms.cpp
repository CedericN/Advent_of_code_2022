//
// Created by Cederic on 06/12/2022.
//

#include "Comms.h"

uint32_t Comms::getStartOf(uint32_t size) {
    for(uint32_t i = size - 1; i < dataStream.size(); i ++){
        if(noDoubleCharacters(dataStream.substr(i - (size - 1), size))){return i + 1;}
    }
    return 0;
}

bool Comms::noDoubleCharacters(const string check) {
    for(uint32_t i = 0; i < check.length() - 1; i ++){
        for(uint32_t j = i + 1; j < check.length(); j ++){
            if(check.at(i) == check.at(j)){return false;}
        }
    }
    return true;
}
