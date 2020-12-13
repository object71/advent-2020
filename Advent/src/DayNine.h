//
// Created by capit on 12/9/2020.
//

#ifndef VCPKGSKELETON_DAYNINE_H
#define VCPKGSKELETON_DAYNINE_H

#include "Utilities.h"
#include "DayOne.h"

void ExecuteDayNine();

bool IsNumberValid(const std::vector<int>& numbers, int index, int preamble);
int FindInvalidXMASNumber(const std::vector<int>& numbers, int preamble);
int GetAltResult(const std::vector<int>& numbers, int target);
void FindContinuousSetOfNumbersThatAddUpToTarget(
        const std::vector<int>& numbers, int target, int& indexMin, int& indexMax
);

#endif //VCPKGSKELETON_DAYNINE_H
