//
// Created by capit on 12/1/2020.
//

#include "Utilites.h"
#include <fstream>

void ReadFileAsNumbers(std::string_view filename, std::vector<uint32_t>& outVector)
{
    std::ifstream file;
    file.open(filename.data());
    
    uint32_t number;
    while(file >> number) {
        outVector.push_back(number);
    }
    
}
