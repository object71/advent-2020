//
// Created by capit on 12/1/2020.
//

#include "DayOne.h"

int AdventDayOne(int targetNumber)
{
    std::vector<int> inputDayOne;
    ReadFileAsNumbers("./data/input_day_one.txt", inputDayOne);
    
    int numberOne = 0;
    int numberTwo = 0;
    
    FindTwoNumbersThatSumToTarget(targetNumber, inputDayOne, numberOne, numberTwo);
    
    return numberOne * numberTwo;
}

bool FindTwoNumbersThatSumToTarget(
        int targetNumber, std::vector<int>& inputDayOne, int& numberOne, int& numberTwo
)
{
    std::sort(inputDayOne.begin(), inputDayOne.end());
    
    for (unsigned int k = inputDayOne.size() - 1; k > 0; k--)
    {
        unsigned int currentN = inputDayOne[k];
        
        for (unsigned int i = 0; k != i; i++)
        {
            unsigned int testedN = inputDayOne[i];
            
            if (currentN + testedN > targetNumber)
            {
                break;
            }
            
            if (currentN + testedN == targetNumber)
            {
                numberOne = currentN;
                numberTwo = testedN;
                return true;
            }
        }
    }
    
    return false;
}

int AdventDayOneAlt(int targetNumber)
{
    std::vector<int> inputDayOne;
    ReadFileAsNumbers("./data/input_day_one.txt", inputDayOne);
    
    std::sort(inputDayOne.begin(), inputDayOne.end());
    
    for (unsigned int x = inputDayOne.size() - 1; x > 0; x--)
    {
        int firstN = inputDayOne[x];
        
        for (unsigned int y = 0; y != x - 1; y++)
        {
            int secondN = inputDayOne[y];
            
            if (firstN + secondN > targetNumber)
            {
                break;
            }
            
            for (unsigned int z = y + 1; z != x; z++)
            {
                int thirdN = inputDayOne[z];
                
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
    
    unsigned int targetNumber = 2020;
    unsigned int result = AdventDayOne(targetNumber);
    unsigned int resultAlt = AdventDayOneAlt(targetNumber);;
    
    spdlog::info("Result one: {}", result);
    spdlog::info("Result two: {}", resultAlt);
    spdlog::info("---------------");
    spdlog::info("");
}
