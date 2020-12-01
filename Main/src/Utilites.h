//
// Created by capit on 12/1/2020.
//

#ifndef VCPKGSKELETON_UTILITES_H
#define VCPKGSKELETON_UTILITES_H

#include <string>
#include <vector>
#include <fmt/format.h>
#include <iostream>

void ReadFileAsNumbers(std::string_view filename, std::vector<uint32_t>& outVector);

#endif //VCPKGSKELETON_UTILITES_H
