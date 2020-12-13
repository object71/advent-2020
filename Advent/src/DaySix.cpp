//
// Created by capit on 12/7/2020.
//

#include "DaySix.h"

void ExecuteDaySix()
{
    spdlog::info("Day 6 Challenge");
    spdlog::info("---------------");
    
    unsigned int result = GetSumOfAnswers("./data/input_day_six.txt");
    unsigned int resultAlt = GetSumOfCommonAnswers("./data/input_day_six.txt");
    
    spdlog::info("Result one: {}", result);
    spdlog::info("Result two: {}", resultAlt);
    spdlog::info("---------------");
    spdlog::info("");
}

int GetSumOfAnswers(const std::string& filename)
{
    int sum = 0;
    for (const std::string& groupAnswers : GetAnswers(filename))
    {
        sum += GetGroupSum(groupAnswers);
    }
    
    return sum;
}

int GetGroupSum(const std::string& groupAnswers)
{
    std::string copyAnswers = groupAnswers;
    std::sort(copyAnswers.begin(), copyAnswers.end());
    auto it = std::unique(copyAnswers.begin(), copyAnswers.end());
    
    copyAnswers.erase(it, copyAnswers.end());
    
    return copyAnswers.size();
}

int GetSumOfCommonAnswers(const std::string& filename)
{
    int sum = 0;
    std::vector<std::string> answers = GetAnswers(filename);
    std::vector<int> sizes = GetGroupSizes(filename);
    
    for (int i = 0; i < answers.size(); i++)
    {
        sum += GetCommonGroupSum(answers[i], sizes[i]);
    }
    
    return sum;
}

int GetCommonGroupSum(const std::string& groupAnswers, int countOfPeople)
{
    std::string copyAnswers = groupAnswers;
    std::sort(copyAnswers.begin(), copyAnswers.end());
    
    char currentChar = copyAnswers[0];
    int counter = 0;
    
    int commonAnswers = 0;
    
    for (int i = 0; i < copyAnswers.size(); i++)
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

std::vector<int> GetGroupSizes(const std::string& filename)
{
    std::vector<int> result;
    
    int count = 0;
    
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