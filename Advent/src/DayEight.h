//
// Created by capit on 12/8/2020.
//

#ifndef VCPKGSKELETON_DAYEIGHT_H
#define VCPKGSKELETON_DAYEIGHT_H

#include "Utilities.h"

void ExecuteDayEight();

int GetAccumulatorValueBeforeLoop(const std::string& filename);
int GetAccumulatorValueWithoutError(const std::string& filename);

class HandheldDevice {
private:
    int Accumulator = 0;
    int IndexPointer = 0;
    bool ErrorFlag;
    
public:
    int GetAccumulator() const { return Accumulator; }
    bool GetErrorFlag() const { return ErrorFlag; }
    
    void Restart();
    void ExecuteCode(const std::vector<std::string>& code);
};

#endif //VCPKGSKELETON_DAYEIGHT_H
