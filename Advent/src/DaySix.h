//
// Created by capit on 12/7/2020.
//

#ifndef VCPKGSKELETON_DAYSIX_H
#define VCPKGSKELETON_DAYSIX_H

#include "Utilities.h"

void ExecuteDaySix();

std::vector<std::string> GetAnswers(const std::string& filename);
int GetGroupSum(const std::string& groupAnswers);
int GetSumOfAnswers(const std::string& filename);
std::vector<int> GetGroupSizes(const std::string& filename);
int GetCommonGroupSum(const std::string& groupAnswers, int countOfPeople);
int GetSumOfCommonAnswers(const std::string& filename);

#endif //VCPKGSKELETON_DAYSIX_H
