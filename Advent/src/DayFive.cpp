//
// Created by capit on 12/6/2020.
//

#include "DayFive.h"

const unsigned int MAX_COLUMNS = 7;

unsigned int GetFreeSeatID();

void ExecuteDayFive()
{
    spdlog::info("Day 5 Challenge");
    spdlog::info("---------------");
    
    unsigned int result = GetMaxSeatID("./data/input_day_five.txt");
    unsigned int resultAlt = GetFreeSeatID();
    
    spdlog::info("Result one: {}", result);
    spdlog::info("Result two: {}", resultAlt);
    spdlog::info("---------------");
    spdlog::info("");
}

unsigned int GetFreeSeatID()
{
    std::vector<int> takenSeats;
    GetTakenSeatIDs("./data/input_day_five.txt", takenSeats);
    
    std::sort(takenSeats.begin(), takenSeats.end());
    
    for (int i = 0; i < takenSeats.size() - 1; i++)
    {
        if (takenSeats[i + 1] - takenSeats[i] > 1)
        {
            return takenSeats[i] + 1;
        }
    }
    
    return -1;
}

int GetMaxSeatID(const std::string& filename)
{
    int max = 0;
    ReadFileLineByLine(
            filename, [&](const std::string& line) {
                int currentID = GetSeatID(line);
                if (currentID > max)
                {
                    max = currentID;
                }
            }
    );
    
    return max;
}

void GetTakenSeatIDs(const std::string& filename, std::vector<int>& seatIDs)
{
    ReadFileLineByLine(
            filename, [&](const std::string& line) {
                seatIDs.push_back(GetSeatID(line));
            }
    );
}

int GetSeatID(const std::string& boardingPass)
{
    int column = 0;
    int row = 0;
    GetSeatColumnAndRow(boardingPass, column, row);
    
    return row * 8 + column;
}

void GetSeatColumnAndRow(const std::string& boardingPass, int& column, int& row)
{
    column = 0;
    row = 0;
    
    int mask = 0b1000000;
    for (int i = 0; i < 7; i++)
    {
        if (boardingPass[i] == 'B')
        {
            row |= mask;
        }
        
        mask = mask >> 1;
    }
    
    mask = 0b100;
    for (int i = 7; i < 10; i++)
    {
        if (boardingPass[i] == 'R')
        {
            column |= mask;
        }
        
        mask = mask >> 1;
    }
}
