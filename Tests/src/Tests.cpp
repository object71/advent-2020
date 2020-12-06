//
// Created by capit on 12/2/2020.
//

#define CATCH_CONFIG_MAIN

#include <Utilities.h>
#include <DayThree.h>
#include "catch.hpp"

TEST_CASE("Testing framework is working fine", "[Catch2]")
{
    REQUIRE(true);
}

TEST_CASE("Testing advent day three function", "[advent]")
{
    std::vector<int8_t> map;
    uint32_t width;
    uint32_t height;
    ReadFileAsMatrix("./data/input_day_three_test.txt", map, width, height);
    
    REQUIRE(width == 11);
    REQUIRE(height == 11);
    
    SECTION("Slope 1")
    {
        uint32_t result = CountNumberOfTrees(map, width, height, 1, 1);
        REQUIRE(result == 2);
    }
    
    SECTION("Slope 2")
    {
        uint32_t result = CountNumberOfTrees(map, width, height, 3, 1);
        REQUIRE(result == 7);
    }
    
    SECTION("Slope 3")
    {
        uint32_t result = CountNumberOfTrees(map, width, height, 5, 1);
        REQUIRE(result == 3);
    }
    
    SECTION("Slope 4")
    {
        uint32_t result = CountNumberOfTrees(map, width, height, 7, 1);
        REQUIRE(result == 4);
    }
    
    SECTION("Slope 5")
    {
        uint32_t result = CountNumberOfTrees(map, width, height, 1, 2);
        REQUIRE(result == 2);
    }
    
    SECTION("Result of all slopes")
    {
        uint32_t result = CalculateMultipleSlopeAnswer(map, width, height);
        REQUIRE(result == 336);
    }
}