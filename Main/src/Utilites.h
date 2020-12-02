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

void ReadFileAsNumbers(std::string_view filename, std::vector<uint32_t>& outVector);
void ReadFileLineByLine(std::string_view filename, std::function<void(const std::string&)> callback);

#endif //VCPKGSKELETON_UTILITES_H
