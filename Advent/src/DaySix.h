//
// Created by capit on 12/7/2020.
//

#ifndef VCPKGSKELETON_DAYSIX_H
#define VCPKGSKELETON_DAYSIX_H

#include "Utilities.h"

void ExecuteDaySix();

std::vector<std::string> GetAnswers(const std::string& filename);
int32_t GetGroupSum(const std::string& groupAnswers);
int32_t GetSumOfAnswers(const std::string& filename);
std::vector<int32_t> GetGroupSizes(const std::string& filename);
int32_t GetCommonGroupSum(const std::string& groupAnswers, int32_t countOfPeople);
int32_t GetSumOfCommonAnswers(const std::string& filename);

#endif //VCPKGSKELETON_DAYSIX_H
