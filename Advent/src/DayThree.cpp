//
// Created by capit on 12/3/2020.
//

#include "DayThree.h"

void ExecuteDayThree()
{
    spdlog::info("Day 3 Challenge");
    spdlog::info("---------------");
    
    std::vector<char> map;
    unsigned int width;
    unsigned int height;
    ReadFileAsMatrix("./data/input_day_three.txt", map, width, height);
    
    unsigned int result = CountNumberOfTrees(map, width, height, 3, 1);
    unsigned int resultAlt = CalculateMultipleSlopeAnswer(map, width, height);
    
    spdlog::info("Result one: {}", result);
    spdlog::info("Result two: {}", resultAlt);
    spdlog::info("---------------");
    spdlog::info("");
}

unsigned int CalculateMultipleSlopeAnswer(const std::vector<char>& map, const unsigned int& width, const unsigned int& height)
{
    unsigned int result = 1;
    result *= CountNumberOfTrees(map, width, height, 1, 1);
    result *= CountNumberOfTrees(map, width, height, 3, 1);
    result *= CountNumberOfTrees(map, width, height, 5, 1);
    result *= CountNumberOfTrees(map, width, height, 7, 1);
    result *= CountNumberOfTrees(map, width, height, 1, 2);
    
    return result;
}

unsigned int CountNumberOfTrees(const std::vector<char>& map, const unsigned int& width, const unsigned int& height, int slopeX, int slopeY)
{
    unsigned int positionX = 0;
    unsigned int positionY = 0;
    unsigned int count = 0;
    
    //    unsigned int wrapUpValue = width * height;
    
    for (unsigned int i = 0; i < height; i++)
    {
        if (map[positionX + positionY * width] == '#')
        {
            count++;
        }
        
        positionX += slopeX;
        positionY += slopeY;
        
        if (positionX >= width)
        {
            positionX -= width;
        }
        
        if (positionY >= height)
        {
            break;
        }
    }
    
    return count;
}
