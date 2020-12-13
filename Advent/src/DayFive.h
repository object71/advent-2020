//
// Created by capit on 12/6/2020.
//

#ifndef VCPKGSKELETON_DAYFIVE_H
#define VCPKGSKELETON_DAYFIVE_H

#include "Utilities.h"

void ExecuteDayFive();

int GetSeatID(const std::string& boardingPass);
int GetMaxSeatID(const std::string& filename);
void GetSeatColumnAndRow(const std::string& boardingPass, int& column, int& row);
void GetTakenSeatIDs(const std::string& filename, std::vector<int>& seatIDs);

#endif //VCPKGSKELETON_DAYFIVE_H
