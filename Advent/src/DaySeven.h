//
// Created by capit on 12/7/2020.
//

#ifndef VCPKGSKELETON_DAYSEVEN_H
#define VCPKGSKELETON_DAYSEVEN_H

#include "Utilities.h"

void ExecuteDaySeven();

struct BagRule {
    std::string BagColor;
    std::vector<std::pair<int, std::string>> BagTypes;
};

BagRule ParseBagRule(const std::string& line);
std::vector<BagRule> ProcessBagRules(const std::string& filename);
int CountOfBagsThatMustBeContained(const std::vector<BagRule>& x, const std::string& bagColor);
void CountOfBagsThatContain(
        const std::vector<BagRule>& rules, const std::string& bagColor, std::vector<std::string>& colorTypes
);


#endif //VCPKGSKELETON_DAYSEVEN_H
