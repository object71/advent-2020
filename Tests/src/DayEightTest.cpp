//
// Created by capit on 12/8/2020.
//

#include <DayEight.h>
#include "catch.hpp"

SCENARIO("Day eight test case", "[advent]")
{
    WHEN("First condition")
    {
        std::vector<std::string> code;
        ReadFileAsLines("./data/input_day_eight_test.txt", code);
    
        HandheldDevice hhd;
        hhd.ExecuteCode(code);
        
        REQUIRE(hhd.GetAccumulator() == 5);
    }
    
}