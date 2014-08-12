#ifndef ZEROCROSSING_H
#define ZEROCROSSING_H

#include <vector>
#include <array>
#include "constans.h"

class ZeroCrossing
{
public:
    ZeroCrossing();

    void detect(std::array<float, bufferSize> wave, int range);

private:
    std::vector<int> peaks;
};

#endif // ZEROCROSSING_H
