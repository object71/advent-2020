//
// Created by capit on 12/1/2020.
//

#include "DayOne.h"

uint32_t AdventDayOne(uint32_t targetNumber)
{
    std::vector<uint32_t> inputDayOne;
    ReadFileAsNumbers("./data/input_day_one.txt", inputDayOne);
    
    std::sort(inputDayOne.begin(), inputDayOne.end());
    
    for (uint32_t k = inputDayOne.size() - 1; k > 0; k--)
    {
        uint32_t currentN = inputDayOne[k];
        
        for (uint32_t i = 0; k != i; i++)
        {
            uint32_t testedN = inputDayOne[i];
            
            if (currentN + testedN > targetNumber)
            {
                break;
            }
            
            if (currentN + testedN == targetNumber)
            {
                return currentN * testedN;
            }
        }
    }
    return 0;
}

uint32_t AdventDayOneAlt(uint32_t targetNumber)
{
    std::vector<uint32_t> inputDayOne;
    ReadFileAsNumbers("./data/input_day_one.txt", inputDayOne);
    
    std::sort(inputDayOne.begin(), inputDayOne.end());
    
    for (uint32_t x = inputDayOne.size() - 1; x > 0; x--)
    {
        uint32_t firstN = inputDayOne[x];
        
        for (uint32_t y = 0; y != x - 1; y++)
        {
            uint32_t secondN = inputDayOne[y];
            
            if (firstN + secondN > targetNumber)
            {
                break;
            }
            
            for (uint32_t z = y + 1; z != x; z++)
            {
                uint32_t thirdN = inputDayOne[z];
                
                if (firstN + secondN + thirdN > targetNumber)
                {
                    break;
                }
                
                if (firstN + secondN + thirdN == targetNumber)
                {
                    return firstN * secondN * thirdN;
                }
            }
        }
    }
    return 0;
}

void ExecuteDayOne()
{
    spdlog::info("Day 1 Challenge");
    spdlog::info("---------------");
    
    uint32_t targetNumber = 2020;
    uint32_t result = AdventDayOne(targetNumber);
    uint32_t resultAlt = AdventDayOneAlt(targetNumber);;
    
    spdlog::info("Result one: {}", result);
    spdlog::info("Result two: {}", resultAlt);
    spdlog::info("---------------");
    spdlog::info("");
}
