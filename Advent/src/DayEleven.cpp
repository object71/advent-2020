//
// Created by capit on 12/11/2020.
//

#include "DayEleven.h"

int CountOccupiedSeats(const std::string& filename);

void ExecuteDayEleven()
{
    spdlog::info("Day 11 Challenge");
    spdlog::info("---------------");
    
    unsigned int result = CountOccupiedSeats("./data/input_day_eleven.txt");
    unsigned int resultAlt = 0;
    
    spdlog::info("Result one: {}", result);
    spdlog::info("Result two: {}", resultAlt);
    spdlog::info("---------------");
    spdlog::info("");
}

int CountOccupiedSeats(const std::string& filename)
{
    std::vector<char> matrix;
    unsigned int rows, columns;
    ReadFileAsMatrix(filename, matrix, columns, rows);
    
    SimulateSeatSelection(matrix, rows, columns);
    
    int count = std::count(matrix.begin(), matrix.end(), '#');
    
    return count;
}

void SimulateSeatSelection(std::vector<char>& vector, unsigned int rows, unsigned int columns)
{
    bool hasChanged = true;
    spdlog::info("x: {}, y: {}", columns, rows);
    
    
    std::vector<char> copyVector(vector.size());
    std::copy(vector.begin(), vector.end(), copyVector.begin());
    
    while (hasChanged)
    {
        for (int i = 0; i < vector.size(); i++)
        {
            if (vector[i] == '.')
            {
                continue;
            }
            
            int x = i % columns;
            int y = i / columns;
            
            int countTaken = 0;
            
            for (int n = -1; n < 2; n++)
            {
                for (int m = -1; m < 2; m++)
                {
                    if (x + n < 0 || y + m < 0 || (m == 0 && n == 0) || x + n >= columns || y + m >= rows)
                    {
                        continue;
                    }
                    
                    if (vector[(x + n) + columns * (y + m)] == '#')
                    {
                        countTaken++;
                    }
                }
            }
            
            if (vector[i] == 'L' && countTaken == 0)
            {
                copyVector[i] = '#';
            }
            else if (vector[i] == '#' && countTaken >= 4)
            {
                copyVector[i] = 'L';
            }
        }
    
        hasChanged = !std::equal(vector.begin(), vector.end(), copyVector.begin(), copyVector.end());
        
        if (hasChanged)
        {
            std::copy(copyVector.begin(), copyVector.end(), vector.begin());
        }
    }
}


