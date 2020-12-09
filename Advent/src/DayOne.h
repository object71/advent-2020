//
// Created by capit on 12/1/2020.
//

#ifndef VCPKGSKELETON_DAYONE_H
#define VCPKGSKELETON_DAYONE_H

#include "Utilities.h"

int32_t AdventDayOne(int32_t targetNumber);
int32_t AdventDayOneAlt(int32_t targetNumber);

bool FindTwoNumbersThatSumToTarget(
        int32_t targetNumber, std::vector<int32_t>& inputDayOne, int32_t& numberOne, int32_t& numberTwo
);

void ExecuteDayOne();

#endif //VCPKGSKELETON_DAYONE_H
