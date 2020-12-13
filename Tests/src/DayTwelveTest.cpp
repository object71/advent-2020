//
// Created by capit on 12/11/2020.
//

#include <DayTwelve.h>
#include "catch.hpp"

SCENARIO("Day twelve test case", "[advent]")
{
    WHEN("First condition")
    {
        std::vector<std::string> commands;
        ReadFileAsLines("./data/input_day_twelve_test.txt", commands);
        
        REQUIRE(CalcualetManhatanDistance(commands) == 25);
    }
    
    WHEN("Second condition")
    {
        std::vector<std::string> commands;
        ReadFileAsLines("./data/input_day_twelve_test.txt", commands);
        
        REQUIRE(CalcualetManhatanDistanceAlt(commands) == 286);
    }
    
}
