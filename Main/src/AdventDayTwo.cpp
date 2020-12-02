//
// Created by capit on 12/2/2020.
//

#include "AdventDayTwo.h"
#include <regex>
#include <sstream>

uint32_t PartOne();
uint32_t PartTwo();

void ExecuteDayTwo()
{
    spdlog::info("Day 2 Challenge");
    spdlog::info("---------------");
    
    uint32_t result = PartOne();
    uint32_t resultAlt = PartTwo();
    
    spdlog::info("Result one: {}", result);
    spdlog::info("Result two: {}", resultAlt);
    spdlog::info("---------------");
    spdlog::info("");
}

uint32_t PartOne()
{
    uint32_t result = 0;
    
    std::regex reg("(\\d+)-(\\d+) (\\D): (.*)");
    
    ReadFileLineByLine(
            "./data/input_day_two.txt", [&](const std::string& v) {
                std::match_results<std::string::const_iterator> matches;
                if (!std::regex_search(v, matches, reg))
                {
                    spdlog::error("Search for regex failed");
                }
            
                uint32_t first;
                uint32_t second;
                char character;
                std::string password = matches[4].str();
                
                std::stringstream(matches[1].str()) >> first;
                std::stringstream(matches[2].str()) >> second;
                std::stringstream(matches[3].str()) >> character;
                
                if (second < first)
                {
                    spdlog::error("Lower bound is larger than upper: '{}'", v);
                    return;
                }
                
                uint32_t countOfCharactersMet = 0;
                for (uint32_t i = 0; i < password.size(); i++)
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

uint32_t PartTwo()
{
    uint32_t result = 0;
    
    std::regex reg("(\\d+)-(\\d+) (\\D): (.*)");
    
    ReadFileLineByLine(
            "./data/input_day_two.txt", [&](const std::string& v) {
                std::match_results<std::string::const_iterator> matches;
                if (!std::regex_search(v, matches, reg))
                {
                    spdlog::error("Search for regex failed");
                }
                
                uint32_t first;
                uint32_t second;
                char character;
                std::string password = matches[4].str();
                
                std::stringstream(matches[1].str()) >> first;
                std::stringstream(matches[2].str()) >> second;
                std::stringstream(matches[3].str()) >> character;
                
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
