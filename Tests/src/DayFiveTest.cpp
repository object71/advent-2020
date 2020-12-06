//
// Created by capit on 12/6/2020.
//

#include "catch.hpp"
#include "DayFive.h"

SCENARIO("Day five test case", "[advent]")
{
    WHEN("First condition")
    {
        SECTION("Boarding Pass BFFFBBFRRR")
        {
            std::string boardingPass = "BFFFBBFRRR";
            REQUIRE(GetSeatID(boardingPass) == 567);
        }
    
        SECTION("Boarding Pass FFFBBBFRRR")
        {
            std::string boardingPass = "FFFBBBFRRR";
            REQUIRE(GetSeatID(boardingPass) == 119);
        }
    
        SECTION("Boarding Pass BBFFBBFRLL")
        {
            std::string boardingPass = "BBFFBBFRLL";
            REQUIRE(GetSeatID(boardingPass) == 820);
        }
    }
    
}