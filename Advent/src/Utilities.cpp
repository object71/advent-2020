//
// Created by capit on 12/1/2020.
//

#include "Utilities.h"
#include <fstream>

void ReadFileAsNumbers(std::string_view filename, std::vector<int>& outVector)
{
    std::ifstream file;
    file.open(filename.data());
    
    int number;
    while (file >> number)
    {
        outVector.push_back(number);
    }
    
    file.close();
}

void ReadFileLineByLine(std::string_view filename, std::function<void(const std::string&)> callback)
{
    std::ifstream file;
    file.open(filename.data());
    
    if (!file.is_open())
    {
        spdlog::error("Couldn't open file");
    }
    
    std::string line;
    while (std::getline(file, line))
    {
        callback(line);
    }
    
    file.close();
}

void ReadFileAsMatrix(std::string_view filename, std::vector<char>& outVector, unsigned int& width, unsigned int& height)
{
    width = 0;
    height = 0;
    ReadFileLineByLine(
            filename, [&](const std::string& line) {
                width = line.size();
                height++;
                
                for (const char& character : line)
                {
                    outVector.push_back(character);
                }
            }
    );
}

void ReadFileAsLines(std::string_view filename, std::vector<std::string>& outVector)
{
    ReadFileLineByLine(
            filename, [&](const std::string& line) {
                outVector.push_back(line);
            }
    );
}

bool GetRegexMatches(const std::string& regex, const std::string& input, std::vector<std::string>& groups)
{
    const std::regex rule(regex);
    
    std::match_results<std::string::const_iterator> matches;
    if (!std::regex_search(input, matches, rule))
    {
        return false;
    }
    
    for(const std::string& str : matches) {
        groups.push_back(str);
    }
    
    return true;
}
