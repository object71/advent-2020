//
// Created by capit on 12/11/2020.
//

#include <DayEleven.h>
#include "catch.hpp"

SCENARIO("Day eleven test case", "[advent]")
{
    WHEN("First condition")
    {
        std::vector<char> matrix;
        unsigned int rows, columns;
        ReadFileAsMatrix("./data/input_day_eleven_test.txt", matrix, columns, rows);
        
        SimulateSeatSelection(matrix, rows, columns);
        
        int count = std::count(matrix.begin(), matrix.end(), '#');
        REQUIRE(count == 37);
    }
    
}
