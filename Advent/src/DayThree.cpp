//
// Created by capit on 12/3/2020.
//

#include "DayThree.h"

void ExecuteDayThree()
{
    spdlog::info("Day 3 Challenge");
    spdlog::info("---------------");
    
    std::vector<int8_t> map;
    uint32_t width;
    uint32_t height;
    ReadFileAsMatrix("./data/input_day_three.txt", map, width, height);
    
    uint32_t result = CountNumberOfTrees(map, width, height, 3, 1);
    uint32_t resultAlt = CalculateMultipleSlopeAnswer(map, width, height);
    
    spdlog::info("Result one: {}", result);
    spdlog::info("Result two: {}", resultAlt);
    spdlog::info("---------------");
    spdlog::info("");
}

uint32_t CalculateMultipleSlopeAnswer(const std::vector<int8_t>& map, const uint32_t& width, const uint32_t& height)
{
    uint32_t result = 1;
    result *= CountNumberOfTrees(map, width, height, 1, 1);
    result *= CountNumberOfTrees(map, width, height, 3, 1);
    result *= CountNumberOfTrees(map, width, height, 5, 1);
    result *= CountNumberOfTrees(map, width, height, 7, 1);
    result *= CountNumberOfTrees(map, width, height, 1, 2);
    
    return result;
}

uint32_t CountNumberOfTrees(const std::vector<int8_t>& map, const uint32_t& width, const uint32_t& height, int32_t slopeX, int32_t slopeY)
{
    uint32_t positionX = 0;
    uint32_t positionY = 0;
    uint32_t count = 0;
    
    //    uint32_t wrapUpValue = width * height;
    
    for (uint32_t i = 0; i < height; i++)
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
