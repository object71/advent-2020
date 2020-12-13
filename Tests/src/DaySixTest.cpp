//
// Created by capit on 12/7/2020.
//

#include "catch.hpp"
#include "DaySix.h"

SCENARIO("Day six test case", "[advent]")
{
    WHEN("First condition")
    {
        int sum = GetSumOfAnswers("./data/input_day_six_test.txt");
        REQUIRE(sum == 11);
    }
    
    WHEN("Second condition")
    {
        int sum = GetSumOfCommonAnswers("./data/input_day_six_test.txt");
        REQUIRE(sum == 6);
    }
}
