#ifndef ZEROCROSSING_H
#define ZEROCROSSING_H

#include <vector>
#include <array>
#include "constans.h"

class ZeroCrossing
{
public:
    zerocrossing();

    void detect(std::array<float, bufferSize> wave);

private:
    std::vector<int> peaks;
};

#endif // ZEROCROSSING_H
