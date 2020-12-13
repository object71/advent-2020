//
// Created by capit on 12/2/2020.
//

#include "DayTwo.h"
#include <regex>
#include <sstream>

unsigned int PartOne();
unsigned int PartTwo();

void ExecuteDayTwo()
{
    spdlog::info("Day 2 Challenge");
    spdlog::info("---------------");
    
    unsigned int result = PartOne();
    unsigned int resultAlt = PartTwo();
    
    spdlog::info("Result one: {}", result);
    spdlog::info("Result two: {}", resultAlt);
    spdlog::info("---------------");
    spdlog::info("");
}

unsigned int PartOne()
{
    unsigned int result = 0;
    
    std::regex reg("(\\d+)-(\\d+) (\\D): (.*)");
    
    ReadFileLineByLine(
            "./data/input_day_two.txt", [&](const std::string& v) {
                std::match_results<std::string::const_iterator> matches;
                if (!std::regex_search(v, matches, reg))
                {
                    spdlog::error("Search for regex failed");
                }
            
                unsigned int first = stoi(matches[1].str());
                unsigned int second = stoi(matches[2].str());
                char character = matches[3].str()[0];
                std::string password = matches[4].str();
                
                if (second < first)
                {
                    spdlog::error("Lower bound is larger than upper: '{}'", v);
                    return;
                }
                
                unsigned int countOfCharactersMet = 0;
                for (unsigned int i = 0; i < password.size(); i++)
                {
                    if (password[i] == character)
                    {
                        countOfCharactersMet++;
                    }
                    
                    if (countOfCharactersMet > second)
                    {
                        return;
                    }
                }
                
                if (countOfCharactersMet >= first)
                {
                    result++;
                }
            }
    );
    return result;
}

unsigned int PartTwo()
{
    unsigned int result = 0;
    
    std::regex reg("(\\d+)-(\\d+) (\\D): (.*)");
    
    ReadFileLineByLine(
            "./data/input_day_two.txt", [&](const std::string& v) {
                std::match_results<std::string::const_iterator> matches;
                if (!std::regex_search(v, matches, reg))
                {
                    spdlog::error("Search for regex failed");
                }
            
                unsigned int first = stoi(matches[1].str());
                unsigned int second = stoi(matches[2].str());
                char character = matches[3].str()[0];
                std::string password = matches[4].str();
                
                first--;
                second--;
                
                if(password[first] != password[second] && (password[first] == character || password[second] ==
                character)) {
                    result++;
                }
            }
    );
    return result;
}
