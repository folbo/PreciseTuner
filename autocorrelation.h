#ifndef AUTOCORRELATION_H
#define AUTOCORRELATION_H


#include <array>
#include "constans.h"


class AutoCorrelation
{
public:
    AutoCorrelation();

    float getFrequency() { return freq; };

    void analyse(std::array<float, bufferSize> wave, int max_samples);

private:
    float freq;
};

#endif // AUTOCORRELATION_H
