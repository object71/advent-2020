//
// Created by capit on 12/7/2020.
//

#include "catch.hpp"
#include "DaySix.h"

SCENARIO("Day six test case", "[advent]")
{
    WHEN("First condition")
    {
        int32_t sum = GetSumOfAnswers("./data/input_day_six_test.txt");
        REQUIRE(sum == 11);
    }
    
    WHEN("Second condition")
    {
        int32_t sum = GetSumOfCommonAnswers("./data/input_day_six_test.txt");
        REQUIRE(sum == 6);
    }
}
