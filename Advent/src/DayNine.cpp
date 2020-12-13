//
// Created by capit on 12/9/2020.
//

#include "DayNine.h"
#include <numeric>

void ExecuteDayNine()
{
    spdlog::info("Day 9 Challenge");
    spdlog::info("---------------");
    
    std::vector<int> data;
    ReadFileAsNumbers("./data/input_day_nine.txt", data);
    
    int result = FindInvalidXMASNumber(data, 25);
    int resultAlt = GetAltResult(data, result);
    
    spdlog::info("Result one: {}", result);
    spdlog::info("Result two: {}", resultAlt);
    spdlog::info("---------------");
    spdlog::info("");
}

int FindInvalidXMASNumber(const std::vector<int>& numbers, int preamble)
{
    for (int i = preamble; i < numbers.size(); i++)
    {
        if (!IsNumberValid(numbers, i, preamble))
        {
            return numbers[i];
        }
    }
    
    return -1;
}

bool IsNumberValid(const std::vector<int>& numbers, int index, int preamble)
{
    std::vector<int> subset(preamble);
    std::copy(numbers.begin() + index - preamble, numbers.begin() + index, subset.begin());
    
    int numberOne;
    int numberTwo;
    
    bool valid = FindTwoNumbersThatSumToTarget(numbers[index], subset, numberOne, numberTwo);
    return valid && numberOne != numberTwo;
}

void FindContinuousSetOfNumbersThatAddUpToTarget(
        const std::vector<int>& numbers, int target, int& indexMin, int& indexMax
)
{
    for (int i = 0; i < numbers.size() - 1; i++)
    {
        if (numbers[i] >= target)
        {
            continue;
        }
        
        for (int k = i + 1; k < numbers.size(); k++)
        {
            if (numbers[k] >= target)
            {
                continue;
            }
            
            int sum = std::accumulate(numbers.begin() + i, numbers.begin() + k + 1, 0);
            
            if (sum == target)
            {
                indexMin = i;
                indexMax = k;
                return;
            }
            
            if (sum > target)
            {
                break;
            }
        }
    }
}

int GetAltResult(const std::vector<int>& numbers, int target)
{
    int minIndex = 0;
    int maxIndex = 0;
    FindContinuousSetOfNumbersThatAddUpToTarget(numbers, target, minIndex, maxIndex);
    
    int min = std::min_element(numbers.begin() + minIndex, numbers.begin() + maxIndex + 1)[0];
    int max = std::max_element(numbers.begin() + minIndex, numbers.begin() + maxIndex + 1)[0];
    
    return min + max;
}
