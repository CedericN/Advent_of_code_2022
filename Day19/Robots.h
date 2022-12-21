//
// Created by icas on 12/19/22.
//

#ifndef ADVENT_OF_CODE_ROBOTS_H
#define ADVENT_OF_CODE_ROBOTS_H

#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Robots {
public:
    enum robotTypes{
        none,
        oreBot,
        clayBot,
        obsidianBot,
        geodeBot,
    };

    struct RobotInventory {
        uint8_t oreBot = 1;
        uint8_t clayBot = 0;
        uint8_t obsidianBot = 0;
        uint8_t geodeBot = 0;
    };

    struct Resources{
        uint8_t ore = 0;
        uint8_t clay = 0;
        uint8_t obsidian = 0;
        uint8_t geodes = 0;

        Resources& operator += (const RobotInventory &ri){
            ore += ri.oreBot;
            clay += ri.clayBot;
            obsidian += ri.obsidianBot;
            geodes += ri.geodeBot;
            return *this;
        }
    };

    struct blueprint{
        uint8_t oreBotCost = UINT8_MAX;
        uint8_t clayBotCost = UINT8_MAX;
        pair<uint8_t,uint8_t> obsidianBotCost = {UINT8_MAX, UINT8_MAX};
        pair<uint8_t,uint8_t> geodeBotCost = {UINT8_MAX, UINT8_MAX};
    };

//    struct CacheKey{
//        RobotInventory robots;
//
//        Resources resourceDelta;
//
//        bool operator < (const CacheKey &cache) const {
//            return (robots < cache.robots) || (robots == cache.robots && resourceDelta < cache.resourceDelta);
//        }
//
//        bool operator == (const CacheKey &cache) const {
//            return (robots == cache.robots && resourceDelta == cache.resourceDelta);
//        }
//
//    };

    Robots(const string &inputFile);

    uint64_t getOptimalBlueprint(uint8_t time){
        uint64_t returnValue = 0;
        switch(time){
            case 24:
                cout << "\rpart 1: " << 0 << "/" << blueprints.size() << "   ";
                for (int i = 1; i <= blueprints.size(); ++i) {
                    cout << "\rpart 1: " << i << "/" << blueprints.size() << "   " << flush;
                    uint8_t tmp = step(blueprints[i - 1], {}, {}, time);
    //            cout << (int) tmp << endl;
                    returnValue += tmp * (i);
                }
                cout << "\rpart 1: " << "        ";
                cout << "\rpart 1: ";
                break;
            case 32:
                returnValue = 1;
                cout << "\rpart 2: " << 0 << "/" << blueprints.size() << "   ";
                for (int i = 1; i <= blueprints.size() && i <= 3; ++i) {
                    cout << "\rpart 2: " << i << "/" << (blueprints.size() > 3 ? 3 : blueprints.size()) << "   " << flush;
                    uint8_t tmp = step(blueprints[i - 1], {}, {}, time);
                    cout << (int) tmp << endl;
                    returnValue *= tmp;
                }
                cout << "\rpart 2: " << "        ";
                cout << "\rpart 2: ";
                break;

            default:
                cout << "welll you asshole you dont have that much time" << endl;
        }
        
        return returnValue;

    }

private:
    uint8_t step(const blueprint &blueprint, RobotInventory robots, Resources resources, uint8_t timeLeft, robotTypes waitingFor = none);

    static blueprint readBlueprint (string &line);


    vector<blueprint> blueprints;

};

ostream& operator << (ostream &os, const Robots::blueprint &blue);

#endif //ADVENT_OF_CODE_ROBOTS_H
