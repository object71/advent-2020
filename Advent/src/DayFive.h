//
// Created by capit on 12/6/2020.
//

#ifndef VCPKGSKELETON_DAYFIVE_H
#define VCPKGSKELETON_DAYFIVE_H

#include "Utilities.h"

void ExecuteDayFive();

int32_t GetSeatID(const std::string& boardingPass);
int32_t GetMaxSeatID(const std::string& filename);
void GetSeatColumnAndRow(const std::string& boardingPass, int32_t& column, int32_t& row);
void GetTakenSeatIDs(const std::string& filename, std::vector<int32_t>& seatIDs);

#endif //VCPKGSKELETON_DAYFIVE_H
