//
// Created by capit on 12/4/2020.
//

#include "catch.hpp"
#include "DayFour.h"

SCENARIO("Day four test case", "[advent]")
{
    WHEN("First condition")
    {
        std::vector<std::string> passports = GetPassports("./data/input_day_four_test.txt");
        REQUIRE(passports.size() == 4);
        uint32_t count = CountOfValidPassports(passports);
        REQUIRE(count == 2);
    }
    
    WHEN("Second condition")
    {
        std::vector<std::string> passports = GetPassports("./data/input_day_four_test_alt.txt");
        REQUIRE(passports.size() == 8);
        uint32_t count = CountOfComplexValidPassports(passports);
        REQUIRE(count == 4);
    }
    
}