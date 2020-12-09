//
// Created by capit on 12/9/2020.
//

#ifndef VCPKGSKELETON_DAYNINE_H
#define VCPKGSKELETON_DAYNINE_H

#include "Utilities.h"
#include "DayOne.h"

void ExecuteDayNine();

bool IsNumberValid(const std::vector<int32_t>& numbers, int32_t index, int32_t preamble);
int32_t FindInvalidXMASNumber(const std::vector<int32_t>& numbers, int32_t preamble);
int32_t GetAltResult(const std::vector<int32_t>& numbers, int32_t target);
void FindContinuousSetOfNumbersThatAddUpToTarget(
        const std::vector<int32_t>& numbers, int32_t target, int32_t& indexMin, int32_t& indexMax
);

#endif //VCPKGSKELETON_DAYNINE_H
