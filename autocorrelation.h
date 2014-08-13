#ifndef AUTOCORRELATION_H
#define AUTOCORRELATION_H


#include <array>
#include "constans.h"


class AutoCorrelation
{
public:
    AutoCorrelation();

    void analyse(std::array<float, bufferSize> wave);
};

#endif // AUTOCORRELATION_H
