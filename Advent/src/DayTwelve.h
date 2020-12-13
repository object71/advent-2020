//
// Created by capit on 12/12/2020.
//

#ifndef VCPKGSKELETON_DAYTWELVE_H
#define VCPKGSKELETON_DAYTWELVE_H

#include "Utilities.h"

void ExecuteDayTwelve();

class Ship {
public:
    int Direction = 0;
    int X = 0;
    int Y = 0;
    void ExecuteNavigationCommands(const std::vector<std::string>& commands);
    void ExecuteNavigationCommandsAlt(const std::vector<std::string>& commands);
};

int CalcualetManhatanDistance(const std::vector<std::string>& commands);
int CalcualetManhatanDistanceAlt(const std::vector<std::string>& commands);

#endif //VCPKGSKELETON_DAYTWELVE_H
