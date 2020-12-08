//
// Created by capit on 12/8/2020.
//

#include "DayEight.h"

void ExecuteDayEight()
{
    spdlog::info("Day 8 Challenge");
    spdlog::info("---------------");
    
    uint32_t result = GetAccumulatorValueBeforeLoop("./data/input_day_eight.txt");
    uint32_t resultAlt = GetAccumulatorValueWithoutError("./data/input_day_eight.txt");
    
    spdlog::info("Result one: {}", result);
    spdlog::info("Result two: {}", resultAlt);
    spdlog::info("---------------");
    spdlog::info("");
}

int32_t GetAccumulatorValueBeforeLoop(const std::string& filename)
{
    std::vector<std::string> code;
    ReadFileAsLines(filename, code);
    
    HandheldDevice hhd;
    hhd.ExecuteCode(code);
    
    return hhd.GetAccumulator();
}

int32_t GetAccumulatorValueWithoutError(const std::string& filename)
{
    std::vector<std::string> code;
    ReadFileAsLines(filename, code);
    
    HandheldDevice hhd;
    
    for (int32_t i = 0; i < code.size(); i++)
    {
        hhd.Restart();
        std::string line = code[i];
        std::string newLine = line;
        
        if (strutil::starts_with(line, "nop"))
        {
            strutil::replace_first(newLine, "nop", "jmp");
        }
        else if (strutil::starts_with(line, "jmp"))
        {
            strutil::replace_first(newLine, "jmp", "nop");
        }
        
        code[i] = newLine;
        hhd.ExecuteCode(code);
        
        if (!hhd.GetErrorFlag())
        {
            break;
        }
        
        code[i] = line;
    }
    
    return hhd.GetAccumulator();
}

void HandheldDevice::ExecuteCode(const std::vector<std::string>& code)
{
    std::vector<int32_t> executedLines;
    
    ErrorFlag = false;
    
    for (IndexPointer = 0; IndexPointer < code.size(); IndexPointer++)
    {
        if (std::count(executedLines.begin(), executedLines.end(), IndexPointer) > 0)
        {
            ErrorFlag = true;
            break;
        }
        
        executedLines.push_back(IndexPointer);
        
        std::vector<std::string> tokens = strutil::split(code[IndexPointer], " ");
        const std::string& operat = tokens[0];
        const int32_t value = stoi(tokens[1]);
        
        if (operat == "acc")
        {
            Accumulator += value;
        }
        else if (operat == "jmp")
        {
            IndexPointer += value - 1;
        }
    }
}

void HandheldDevice::Restart()
{
    ErrorFlag = false;
    Accumulator = 0;
    IndexPointer = 0;
}
