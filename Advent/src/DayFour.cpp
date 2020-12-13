//
// Created by capit on 12/4/2020.
//

#include <sstream>
#include "DayFour.h"

bool HeightIsValid(const std::string& value);

bool MatchesRegexAndSize(const std::string& value, const std::string& regex, unsigned int size);

void ExecuteDayFour()
{
    spdlog::info("Day 4 Challenge");
    spdlog::info("---------------");
    
    std::vector<std::string> passports = GetPassports("./data/input_day_four.txt");
    unsigned int result = CountOfValidPassports(passports);
    unsigned int resultAlt = CountOfComplexValidPassports(passports);
    
    spdlog::info("Result one: {}", result);
    spdlog::info("Result two: {}", resultAlt);
    spdlog::info("---------------");
    spdlog::info("");
}

std::vector<std::string> GetPassports(const std::string& filename)
{
    std::vector<std::string> result;
    
    std::vector<std::string> stringBuffer;
    
    ReadFileLineByLine(
            filename, [&](const std::string& line) {
                if (line.empty())
                {
                    result.push_back(strutil::join(stringBuffer, " "));
                    stringBuffer.clear();
                    return;
                }
                
                stringBuffer.push_back(line);
            }
    );
    
    result.push_back(strutil::join(stringBuffer, " "));
    stringBuffer.clear();
    
    return result;
}

bool IsPassportValid(const std::string& passportLine)
{
    
    std::vector<std::string> tokens = strutil::split(strutil::trim_copy(passportLine), ' ');
    if (tokens.size() < 8)
    {
        if (tokens.size() == 7)
        {
            for (const std::string& token : tokens)
            {
                std::vector<std::string> keyValuePair = strutil::split(strutil::trim_copy(token), ':');
                if (keyValuePair[0] == "cid")
                {
                    return false;
                }
            }
            
            return true;
        }
        
        return false;
    }
    
    return true;
}

bool IsPassportValidComplex(const std::string& passportLine)
{
    const std::vector<std::string> eyeColors = {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
    
    std::vector<std::string> tokens = strutil::split(strutil::trim_copy(passportLine), ' ');
    
    if (tokens.size() < 7)
    {
        return false;
    }
    
    bool valid = true;
    
    for (unsigned int i = 0; i < tokens.size() && valid; i++)
    {
        std::vector<std::string> keyValuePair = strutil::split(strutil::trim_copy(tokens[i]), ':');
        std::string& key = keyValuePair[0];
        std::string value = keyValuePair[1];
    
        if(key == "cid") valid = tokens.size() == 8;
        if(key == "byr") valid = NumberWithinValues(stoi(value), 1920, 2002);
        if(key == "iyr") valid = NumberWithinValues(stoi(value), 2010, 2020);
        if(key == "eyr") valid = NumberWithinValues(stoi(value), 2020, 2030);
        if(key == "hgt") valid = HeightIsValid(value);
        if(key == "hcl") valid = MatchesRegexAndSize(value, "#[0-9a-fA-F]{6}", 7);
        if(key == "pid") valid = MatchesRegexAndSize(value, "[0-9]{9}", 9);
        if(key == "ecl") valid = std::count(eyeColors.begin(), eyeColors.end(), value);
    }
    
    return valid;
}

bool MatchesRegexAndSize(const std::string& value, const std::string& regex, unsigned int size)
{
    std::regex reg(regex);
    return std::regex_match(value, reg) && value.size() == size;
}

bool HeightIsValid(const std::string& value)
{
    bool inCms = strutil::ends_with(value, "cm");
    bool inInch = strutil::ends_with(value, "in");
    
    if (!inCms && !inInch)
    {
        return false;
    }
    
    int size = stoi(value.substr(0, value.size() - 1));
    if (inCms) return NumberWithinValues(size, 150, 193);
    else return NumberWithinValues(size, 59, 76);
}

unsigned int CountOfValidPassports(const std::vector<std::string>& passports)
{
    unsigned int count = 0;
    for (const std::string& pass : passports)
    {
        count += IsPassportValid(pass);
    }
    return count;
}

unsigned int CountOfComplexValidPassports(const std::vector<std::string>& passports)
{
    unsigned int count = 0;
    for (const std::string& pass : passports)
    {
        count += IsPassportValidComplex(pass);
    }
    return count;
}



