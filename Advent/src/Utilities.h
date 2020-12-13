//
// Created by capit on 12/1/2020.
//

#ifndef VCPKGSKELETON_UTILITIES_H
#define VCPKGSKELETON_UTILITIES_H

#include <string>
#include <string_view>
#include <vector>
#include <fmt/format.h>
#include <iostream>
#include <functional>
#include <spdlog/spdlog.h>
#include "strutil.h"

void ReadFileAsNumbers(std::string_view filename, std::vector<int>& outVector);
void ReadFileAsMatrix(std::string_view filename, std::vector<char>& outVector, unsigned int& width, unsigned int& height);
void ReadFileLineByLine(std::string_view filename, std::function<void(const std::string&)> callback);
void ReadFileAsLines(std::string_view filename, std::vector<std::string>& outVector);

template<typename T>
bool NumberWithinValues(T value, T min, T max) {
    return value >= min && value <= max;
}

bool GetRegexMatches(const std::string& regex, const std::string& input, std::vector<std::string>& groups);

#endif //VCPKGSKELETON_UTILITIES_H
