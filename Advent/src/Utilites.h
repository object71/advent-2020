//
// Created by capit on 12/1/2020.
//

#ifndef VCPKGSKELETON_UTILITES_H
#define VCPKGSKELETON_UTILITES_H

#include <string>
#include <string_view>
#include <vector>
#include <fmt/format.h>
#include <iostream>
#include <functional>
#include <spdlog/spdlog.h>
#include "strutil.h"

void ReadFileAsNumbers(std::string_view filename, std::vector<uint32_t>& outVector);
void ReadFileAsMatrix(std::string_view filename, std::vector<int8_t>& outVector, uint32_t& width, uint32_t& height);
void ReadFileLineByLine(std::string_view filename, std::function<void(const std::string&)> callback);

template<typename T>
bool NumberWithinValues(T value, T min, T max) {
    return value >= min && value <= max;
}

#endif //VCPKGSKELETON_UTILITES_H
