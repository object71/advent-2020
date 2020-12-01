#include "Main.h"

int main()
{
    std::cout << fmt::format("Advent 2020 Programming") << std::endl;
    
    std::vector<uint32_t> inputDayOne;
    ReadFileAsNumbers("./data/input_day_one.txt", inputDayOne);
    
    for(uint32_t n : inputDayOne) {
        std::cout << fmt::format("{}", n) << std::endl;
    }
    
    return 0;
}