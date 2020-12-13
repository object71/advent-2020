//
// Created by capit on 12/12/2020.
//

#include "DayTwelve.h"

void ExecuteDayTwelve()
{
    spdlog::info("Day 2 Challenge");
    spdlog::info("---------------");
    
    std::vector<std::string> commands;
    ReadFileAsLines("./data/input_day_twelve.txt", commands);
    
    int result = CalcualetManhatanDistance(commands);
    int resultAlt = CalcualetManhatanDistanceAlt(commands);
    
    spdlog::info("Result one: {}", result);
    spdlog::info("Result two: {}", resultAlt);
    spdlog::info("---------------");
    spdlog::info("");
}

int CalcualetManhatanDistance(const std::vector<std::string>& commands)
{
    
    Ship ship;
    ship.ExecuteNavigationCommands(commands);
    
    int result = abs(ship.X) + abs(ship.Y);
    return result;
}

int CalcualetManhatanDistanceAlt(const std::vector<std::string>& commands)
{
    Ship ship;
    ship.ExecuteNavigationCommandsAlt(commands);
    
    int result = abs(ship.X) + abs(ship.Y);
    return result;
}

void Ship::ExecuteNavigationCommands(const std::vector<std::string>& commands)
{
    std::regex commandParse();
    
    for (const std::string& command : commands)
    {
        std::vector<std::string> groups;
        if (!GetRegexMatches("([a-zA-Z]{1})(\\d*)", command, groups))
        {
            return;
        }
        
        int value = stoi(groups[2]);
        
        switch (groups[1][0])
        {
            case 'N':
                Y -= value;
                break;
            case 'S':
                Y += value;
                break;
            case 'W':
                X += value;
                break;
            case 'E':
                X -= value;
                break;
            case 'R':
                Direction += (value / 90);
                Direction %= 4;
                break;
            case 'L':
                Direction -= value / 90;
                if (Direction < 0)
                {
                    Direction = 4 + Direction;
                }
                break;
            case 'F':
                switch (Direction)
                {
                    case 0:
                        X -= value;
                        break;
                    case 1:
                        Y += value;
                        break;
                    case 2:
                        X += value;
                        break;
                    case 3:
                        Y -= value;
                        break;
                }
                break;
        }
    }
}

void Ship::ExecuteNavigationCommandsAlt(const std::vector<std::string>& commands)
{
    std::regex commandParse();
    
    int wX = -10;
    int wY = -1;
    
    for (const std::string& command : commands)
    {
        std::vector<std::string> groups;
        if (!GetRegexMatches("([a-zA-Z]{1})(\\d*)", command, groups))
        {
            return;
        }
        
        int value = stoi(groups[2]);
        
        switch (groups[1][0])
        {
            case 'N':
                wY -= value;
                break;
            case 'S':
                wY += value;
                break;
            case 'W':
                wX += value;
                break;
            case 'E':
                wX -= value;
                break;
            case 'R':
            {
                int times = value / 90;
                while (times > 0)
                {
                    int tempX = wX;
                    int tempY = wY;
                    wX = tempY;
                    wY = -tempX;
                    times--;
                }
                break;
            }
            case 'L':
            {
                int times = value / 90;
                while (times > 0)
                {
                    int tempX = wX;
                    int tempY = wY;
                    wX = -tempY;
                    wY = tempX;
                    times--;
                }
                break;
            }
            case 'F':
                X += wX * value;
                Y += wY * value;
                break;
        }
    }
}
