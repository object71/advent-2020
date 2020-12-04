//
// Created by capit on 12/4/2020.
//

#ifndef VCPKGSKELETON_DAYFOUR_H
#define VCPKGSKELETON_DAYFOUR_H

#include "Utilites.h"

void ExecuteDayFour();

std::vector<std::string> GetPassports(const std::string& filename);
bool IsPassportValid(const std::string& passportLine);
uint32_t CountOfValidPassports(const std::vector<std::string>& passports);
uint32_t CountOfComplexValidPassports(const std::vector<std::string>& passports);

#endif //VCPKGSKELETON_DAYFOUR_H
