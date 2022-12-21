//
// Created by icas on 12/19/22.
//

#include "Robots.h"

Robots::Robots(const string &inputFile) {
    ifstream InputFileStream(inputFile);
    string line;

    while (getline(InputFileStream, line)) {
        blueprints.push_back(readBlueprint(line));
    }

//    cout << "\rpart 1: " << 0 << "/" << blueprints.size() << "   ";
//    for (auto i = 0; i < blueprints.size(); ++i) {
//        cout << "blueprint " << (int) i + 1 << ": " << blueprints[i] << endl;
//    }
}

uint8_t Robots::step(const blueprint &blueprint, Robots::RobotInventory robots, Robots::Resources resources, uint8_t timeLeft, robotTypes waitingFor) {

    if(timeLeft == 0){return resources.geodes;}

    if(waitingFor == none){
        uint8_t geodes = step(blueprint, robots, resources, timeLeft, oreBot);
        uint8_t geodesTmp = step(blueprint, robots, resources, timeLeft, clayBot);
        if(geodesTmp > geodes){geodes = geodesTmp;}
        geodesTmp = step(blueprint, robots, resources, timeLeft, obsidianBot);
        if(geodesTmp > geodes){geodes = geodesTmp;}
        geodesTmp = step(blueprint, robots, resources, timeLeft, geodeBot);
        if(geodesTmp > geodes){geodes = geodesTmp;}
//        if(timeLeft % 10 == 0 && timeLeft != 0){
//            cout << (int) timeLeft << endl;
//        }
        return geodes;
    }
    timeLeft --;

    switch (waitingFor) {
        case oreBot:
            while (resources.ore < blueprint.oreBotCost){
                if(timeLeft == 0){
                    resources += robots;
                    return resources.geodes;
                }

                timeLeft --;
                resources += robots;
            }


            resources.ore -= blueprint.oreBotCost;
            resources += robots;
            robots.oreBot ++;

            return step(blueprint, robots, resources, timeLeft);
        case clayBot:
            while (resources.ore < blueprint.clayBotCost){
                if(timeLeft == 0){
                    resources += robots;
                    return resources.geodes;
                }

                timeLeft --;
                resources += robots;
            }


            resources.ore -= blueprint.clayBotCost;
            resources += robots;
            robots.clayBot ++;

            return step(blueprint, robots, resources, timeLeft);
        case obsidianBot:
            while (resources.ore < blueprint.obsidianBotCost.first || resources.clay < blueprint.obsidianBotCost.second){
                if(timeLeft == 0){
                    resources += robots;
                    return resources.geodes;
                }

                timeLeft --;
                resources += robots;
            }

            resources.ore -= blueprint.obsidianBotCost.first;
            resources.clay -= blueprint.obsidianBotCost.second;
            resources += robots;
            robots.obsidianBot ++;

            return step(blueprint, robots, resources, timeLeft);
        case geodeBot:
            while (resources.ore < blueprint.geodeBotCost.first || resources.obsidian < blueprint.geodeBotCost.second){
                if(timeLeft == 0){
                    resources += robots;
                    return resources.geodes;
                }

                timeLeft --;
                resources += robots;
            }

            resources.ore -= blueprint.geodeBotCost.first;
            resources.obsidian -= blueprint.geodeBotCost.second;
            resources += robots;
            robots.geodeBot ++;

            return step(blueprint, robots, resources, timeLeft);

        case none:
            break;
    }
    return 0;
}

Robots::blueprint Robots::readBlueprint(string &line) {
    blueprint blueprintTmp;
    uint64_t pos = line.find(':');
    if(pos == string::npos){
        cout << "error ':' not found" << endl;
        return {};
    }
    line = line.substr(pos + 22);

    pos = line.find(" ore.");
    if(pos == string::npos){
        cout << "error ore bot ' ore.' not found" << endl;
        return {};
    }
    blueprintTmp.oreBotCost = stoi(line.substr(0, pos));
    line = line.substr(pos + 28);

    pos = line.find(" ore.");
    if(pos == string::npos){
        cout << "error clay bot ' ore.' not found" << endl;
        return {};
    }
    blueprintTmp.clayBotCost = stoi(line.substr(0, pos));
    line = line.substr(pos + 32);

    pos = line.find(" ore");
    if(pos == string::npos){
        cout << "error obsidian bot ' ore' not found" << endl;
        return {};
    }
    blueprintTmp.obsidianBotCost.first = stoi(line.substr(0, pos));
    line = line.substr(pos + 9);

    pos = line.find(" clay.");
    if(pos == string::npos){
        cout << "error obsidian bot ' clay' not found" << endl;
        return {};
    }
    blueprintTmp.obsidianBotCost.second = stoi(line.substr(0, pos));
    line = line.substr(pos + 30);

    pos = line.find(" ore");
    if(pos == string::npos){
        cout << "error geode bot ' ore' not found" << endl;
        return {};
    }
    blueprintTmp.geodeBotCost.first = stoi(line.substr(0, pos));
    line = line.substr(pos + 9);

    pos = line.find(" obsidian");
    if(pos == string::npos){
        cout << "error geode bot ' obsidian' not found" << endl;
        return {};
    }
    blueprintTmp.geodeBotCost.second = stoi(line.substr(0, pos));
    return blueprintTmp;
}

ostream& operator << (ostream &os, const Robots::blueprint &blue){
    os << "\r\n\tore bot: " << (int) blue.oreBotCost << " ore\r\n\tclay bot: " << (int) blue.clayBotCost << " ore\r\n\tobsidian bot: " << (int) blue.obsidianBotCost.first << " ore and " << (int) blue.obsidianBotCost.second << " clay\r\n\tgeode bot: " << (int) blue.geodeBotCost.first << " ore and " << (int) blue.geodeBotCost.second << " obsidian";
    return os;
}
