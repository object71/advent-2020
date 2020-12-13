//
// Created by capit on 12/3/2020.
//

#ifndef VCPKGSKELETON_DAYTHREE_H
#define VCPKGSKELETON_DAYTHREE_H

#include "Utilities.h"

void ExecuteDayThree();

unsigned int CountNumberOfTrees(
        const std::vector<char>& map, const unsigned int& width, const unsigned int& height, int slopeX, int slopeY
);

unsigned int CalculateMultipleSlopeAnswer(const std::vector<char>& map, const unsigned int& width, const unsigned int& height);

#endif //VCPKGSKELETON_DAYTHREE_H
