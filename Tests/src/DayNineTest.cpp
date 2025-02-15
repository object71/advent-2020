//
// Created by capit on 12/9/2020.
//

#include "catch.hpp"
#include "DayNine.h"

SCENARIO("Day nine test case", "[advent]")
{
    WHEN("First condition")
    {
        std::vector<int> numbers;
        ReadFileAsNumbers("./data/input_day_nine_test.txt", numbers);
        
        int number = FindInvalidXMASNumber(numbers, 5);
        REQUIRE(number == 127);
    }
    
    WHEN("Second condition")
    {
        std::vector<int> numbers;
        ReadFileAsNumbers("./data/input_day_nine_test.txt", numbers);
        int number = FindInvalidXMASNumber(numbers, 5);
    
        int minIndex = 0;
        int maxIndex = 0;
        FindContinuousSetOfNumbersThatAddUpToTarget(numbers, number, minIndex, maxIndex);
    
        REQUIRE(minIndex == 2);
        REQUIRE(maxIndex == 5);
        
        int min = std::min_element(numbers.begin() + minIndex, numbers.begin() + maxIndex)[0];
        int max = std::max_element(numbers.begin() + minIndex, numbers.begin() + maxIndex)[0];
        
        REQUIRE(min == 15);
        REQUIRE(max == 47);
    }
}