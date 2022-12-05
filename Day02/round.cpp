//
// Created by Cederic on 03/12/2022.
//

#include "Round.h"

Round::Round(const pair<char, char> &data) : data(data) {}

unsigned char Round::getPoints1() {
    switch (data.first) {
        case 'A':
            switch (data.second) {
                case 'X':
                    return 4;
                case 'Y':
                    return 8;
                case 'Z':
                    return 3;
            }
        case 'B':
            switch (data.second) {
                case 'X':
                    return 1;
                case 'Y':
                    return 5;
                case 'Z':
                    return 9;
            }
        case 'C':
            switch (data.second) {
                case 'X':
                    return 7;
                case 'Y':
                    return 2;
                case 'Z':
                    return 6;
            }
    }

    return 0;
}

unsigned char Round::getPoints2() {
    switch (data.first) {
        case 'A':
            switch (data.second) {
                case 'X':
                    return 3;
                case 'Y':
                    return 4;
                case 'Z':
                    return 8;
            }
        case 'B':
            switch (data.second) {
                case 'X':
                    return 1;
                case 'Y':
                    return 5;
                case 'Z':
                    return 9;
            }
        case 'C':
            switch (data.second) {
                case 'X':
                    return 2;
                case 'Y':
                    return 6;
                case 'Z':
                    return 7;
            }
    }

    return 0;
}
