//
// Created by capit on 12/7/2020.
//

#include "catch.hpp"
#include "DaySeven.h"

SCENARIO("Day seven test case", "[advent]")
{
    WHEN("First condition")
    {
        SECTION("Raw rule parsing")
        {
            BagRule rule = ParseBagRule("light red bags contain 1 bright white bag, 2 muted yellow bags.");
            REQUIRE(rule.BagColor == "light red");
            REQUIRE(rule.BagTypes.size() == 2);
            
            REQUIRE(rule.BagTypes[0].first == 1);
            REQUIRE(rule.BagTypes[0].second == "bright white");
            
            REQUIRE(rule.BagTypes[1].first == 2);
            REQUIRE(rule.BagTypes[1].second == "muted yellow");
        }
        
        SECTION("Test file parsing")
        {
            std::vector<std::string> colorTypes;
            CountOfBagsThatContain(ProcessBagRules("./data/input_day_seven_test.txt"), "shiny gold", colorTypes);
            REQUIRE(colorTypes.size() == 4);
        }
    }
    
    WHEN("Second condition")
    {
        int count = CountOfBagsThatMustBeContained(
                ProcessBagRules("./data/input_day_seven_test_alt.txt"), "shiny gold"
        );
        REQUIRE(count == 126);
    }
}