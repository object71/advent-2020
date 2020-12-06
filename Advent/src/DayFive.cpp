//
// Created by capit on 12/6/2020.
//

#include "DayFive.h"

const uint32_t MAX_COLUMNS = 7;

uint32_t GetFreeSeatID();

void ExecuteDayFive()
{
    spdlog::info("Day 5 Challenge");
    spdlog::info("---------------");
    
    uint32_t result = GetMaxSeatID("./data/input_day_five.txt");
    uint32_t resultAlt = GetFreeSeatID();
    
    spdlog::info("Result one: {}", result);
    spdlog::info("Result two: {}", resultAlt);
    spdlog::info("---------------");
    spdlog::info("");
}

uint32_t GetFreeSeatID()
{
    std::vector<int32_t> takenSeats;
    GetTakenSeatIDs("./data/input_day_five.txt", takenSeats);
    
    std::sort(takenSeats.begin(), takenSeats.end());
    
    for (int32_t i = 0; i < takenSeats.size() - 1; i++)
    {
        if (takenSeats[i + 1] - takenSeats[i] > 1)
        {
            return takenSeats[i] + 1;
        }
    }
    
    return -1;
}

int32_t GetMaxSeatID(const std::string& filename)
{
    int32_t max = 0;
    ReadFileLineByLine(
            filename, [&](const std::string& line) {
                int32_t currentID = GetSeatID(line);
                if (currentID > max)
                {
                    max = currentID;
                }
            }
    );
    
    return max;
}

void GetTakenSeatIDs(const std::string& filename, std::vector<int32_t>& seatIDs)
{
    ReadFileLineByLine(
            filename, [&](const std::string& line) {
                seatIDs.push_back(GetSeatID(line));
            }
    );
}

int32_t GetSeatID(const std::string& boardingPass)
{
    int32_t column = 0;
    int32_t row = 0;
    GetSeatColumnAndRow(boardingPass, column, row);
    
    return row * 8 + column;
}

void GetSeatColumnAndRow(const std::string& boardingPass, int32_t& column, int32_t& row)
{
    column = 0;
    row = 0;
    
    int32_t mask = 0b1000000;
    for (int32_t i = 0; i < 7; i++)
    {
        if (boardingPass[i] == 'B')
        {
            row |= mask;
        }
        
        mask = mask >> 1;
    }
    
    mask = 0b100;
    for (int32_t i = 7; i < 10; i++)
    {
        if (boardingPass[i] == 'R')
        {
            column |= mask;
        }
        
        mask = mask >> 1;
    }
}
