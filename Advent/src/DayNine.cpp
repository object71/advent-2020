//
// Created by capit on 12/9/2020.
//

#include "DayNine.h"
#include <numeric>

void ExecuteDayNine()
{
    spdlog::info("Day 9 Challenge");
    spdlog::info("---------------");
    
    std::vector<int32_t> data;
    ReadFileAsNumbers("./data/input_day_nine.txt", data);
    
    int32_t result = FindInvalidXMASNumber(data, 25);
    int32_t resultAlt = GetAltResult(data, result);
    
    spdlog::info("Result one: {}", result);
    spdlog::info("Result two: {}", resultAlt);
    spdlog::info("---------------");
    spdlog::info("");
}

int32_t FindInvalidXMASNumber(const std::vector<int32_t>& numbers, int32_t preamble)
{
    for (int32_t i = preamble; i < numbers.size(); i++)
    {
        if (!IsNumberValid(numbers, i, preamble))
        {
            return numbers[i];
        }
    }
    
    return -1;
}

bool IsNumberValid(const std::vector<int32_t>& numbers, int32_t index, int32_t preamble)
{
    std::vector<int32_t> subset(preamble);
    std::copy(numbers.begin() + index - preamble, numbers.begin() + index, subset.begin());
    
    int32_t numberOne;
    int32_t numberTwo;
    
    bool valid = FindTwoNumbersThatSumToTarget(numbers[index], subset, numberOne, numberTwo);
    return valid && numberOne != numberTwo;
}

void FindContinuousSetOfNumbersThatAddUpToTarget(
        const std::vector<int32_t>& numbers, int32_t target, int32_t& indexMin, int32_t& indexMax
)
{
    for (int32_t i = 0; i < numbers.size() - 1; i++)
    {
        if (numbers[i] >= target)
        {
            continue;
        }
        
        for (int32_t k = i + 1; k < numbers.size(); k++)
        {
            if (numbers[k] >= target)
            {
                continue;
            }
            
            int32_t sum = std::accumulate(numbers.begin() + i, numbers.begin() + k + 1, 0);
            
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

int32_t GetAltResult(const std::vector<int32_t>& numbers, int32_t target)
{
    int32_t minIndex = 0;
    int32_t maxIndex = 0;
    FindContinuousSetOfNumbersThatAddUpToTarget(numbers, target, minIndex, maxIndex);
    
    int32_t min = std::min_element(numbers.begin() + minIndex, numbers.begin() + maxIndex + 1)[0];
    int32_t max = std::max_element(numbers.begin() + minIndex, numbers.begin() + maxIndex + 1)[0];
    
    return min + max;
}
