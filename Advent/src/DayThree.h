//
// Created by capit on 12/3/2020.
//

#ifndef VCPKGSKELETON_DAYTHREE_H
#define VCPKGSKELETON_DAYTHREE_H

#include "Utilites.h"

void ExecuteDayThree();

uint32_t CountNumberOfTrees(
        const std::vector<int8_t>& map, const uint32_t& width, const uint32_t& height, int32_t slopeX, int32_t slopeY
);

uint32_t CalculateMultipleSlopeAnswer(const std::vector<int8_t>& map, const uint32_t& width, const uint32_t& height);

#endif //VCPKGSKELETON_DAYTHREE_H
