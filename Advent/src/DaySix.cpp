//
// Created by capit on 12/7/2020.
//

#include "DaySix.h"

void ExecuteDaySix()
{
    spdlog::info("Day 6 Challenge");
    spdlog::info("---------------");
    
    uint32_t result = GetSumOfAnswers("./data/input_day_six.txt");
    uint32_t resultAlt = GetSumOfCommonAnswers("./data/input_day_six.txt");
    
    spdlog::info("Result one: {}", result);
    spdlog::info("Result two: {}", resultAlt);
    spdlog::info("---------------");
    spdlog::info("");
}

int32_t GetSumOfAnswers(const std::string& filename)
{
    int32_t sum = 0;
    for (const std::string& groupAnswers : GetAnswers(filename))
    {
        sum += GetGroupSum(groupAnswers);
    }
    
    return sum;
}

int32_t GetGroupSum(const std::string& groupAnswers)
{
    std::string copyAnswers = groupAnswers;
    std::sort(copyAnswers.begin(), copyAnswers.end());
    auto it = std::unique(copyAnswers.begin(), copyAnswers.end());
    
    copyAnswers.erase(it, copyAnswers.end());
    
    return copyAnswers.size();
}

int32_t GetSumOfCommonAnswers(const std::string& filename)
{
    int32_t sum = 0;
    std::vector<std::string> answers = GetAnswers(filename);
    std::vector<int32_t> sizes = GetGroupSizes(filename);
    
    for (int32_t i = 0; i < answers.size(); i++)
    {
        sum += GetCommonGroupSum(answers[i], sizes[i]);
    }
    
    return sum;
}

int32_t GetCommonGroupSum(const std::string& groupAnswers, int32_t countOfPeople)
{
    std::string copyAnswers = groupAnswers;
    std::sort(copyAnswers.begin(), copyAnswers.end());
    
    char currentChar = copyAnswers[0];
    int32_t counter = 0;
    
    int32_t commonAnswers = 0;
    
    for (int32_t i = 0; i < copyAnswers.size(); i++)
    {
        if (currentChar == copyAnswers[i])
        {
            counter++;
        }
        else
        {
            counter = 1;
            currentChar = copyAnswers[i];
        }
        
        if (counter == countOfPeople)
        {
            commonAnswers++;
        }
    }
    
    return commonAnswers;
}

std::vector<std::string> GetAnswers(const std::string& filename)
{
    std::vector<std::string> result;
    
    std::vector<std::string> stringBuffer;
    
    ReadFileLineByLine(
            filename, [&](const std::string& line) {
                if (line.empty())
                {
                    result.push_back(strutil::join(stringBuffer, ""));
                    stringBuffer.clear();
                    return;
                }
                
                stringBuffer.push_back(line);
            }
    );
    
    result.push_back(strutil::join(stringBuffer, ""));
    stringBuffer.clear();
    
    return result;
}

std::vector<int32_t> GetGroupSizes(const std::string& filename)
{
    std::vector<int32_t> result;
    
    int32_t count = 0;
    
    ReadFileLineByLine(
            filename, [&](const std::string& line) {
                if (line.empty())
                {
                    result.push_back(count);
                    count = 0;
                    return;
                }
                
                count++;
            }
    );
    
    result.push_back(count);
    
    return result;
}