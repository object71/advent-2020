//
// Created by capit on 12/10/2020.
//

#include "DayTen.h"

int depth = 0;

long Factorial(long count);

void ExecuteDayTen()
{
    spdlog::info("Day 10 Challenge");
    spdlog::info("---------------");
    
    std::vector<int> numbers;
    ReadFileAsNumbers("./data/input_day_ten.txt", numbers);
    unsigned int result = GetResult(numbers);
    
    long resultAlt = 0;
    CountArrangements(numbers, resultAlt);
    
    spdlog::info("Result one: {}", result);
    spdlog::info("Result two: {}", resultAlt);
    spdlog::info("---------------");
    spdlog::info("");
}

unsigned int GetResult(std::vector<int>& numbers)
{
    std::vector<int> counts;
    counts.push_back(0);
    counts.push_back(0);
    counts.push_back(0);
    
    CountDiffs(numbers, counts);
    
    unsigned int result = counts[0] * counts[2];
    return result;
}

void CountDiffs(std::vector<int>& numbers, std::vector<int>& counts)
{
    std::sort(numbers.begin(), numbers.end());
    
    counts[numbers[0] - 1]++;
    
    for (int i = 0; i < numbers.size() - 1; i++)
    {
        int diff = numbers[i + 1] - numbers[i];
        
        if (diff > 0)
        {
            counts[diff - 1]++;
        }
    }
    
    counts[2]++;
}

void CountArrangements(std::vector<int>& numbers, long& count)
{
    if (count == 0)
    {
        numbers.push_back(0);
        int maxValue = std::max_element(numbers.begin(), numbers.end())[0];
        numbers.push_back(maxValue + 3);
        std::sort(numbers.begin(), numbers.end());
    }
    
    for (int i = 0; i < numbers.size() - 2; i++)
    {
        int current = numbers[i];
        
        if (i + 2 < numbers.size())
        {
            int secondNext = numbers[i + 2];
            if (secondNext - current <= 3)
            {
                count++;
            }
            else
            {
                continue;
            }
        }
        
        if (i + 3 < numbers.size())
        {
            int secondNext = numbers[i + 3];
            if (secondNext - current <= 3)
            {
                count++;
            }
        }
    }
}

long Factorial(long count)
{
    long long result = 1;
    
    for (long i = 1; i <= count; i++)
    {
        result *= i;
    }
    
    return (long)result;
}
