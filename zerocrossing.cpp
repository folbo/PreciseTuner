#include "zerocrossing.h"

ZeroCrossing::ZeroCrossing()
{


}
struct pair
{
    int offset;
    float power;
};

void ZeroCrossing::detect(std::array<float, bufferSize> wave, int range)
{
    int i1 = 0;
    int i2 = 0;
    std::vector<pair> wek;

    for(int i = 0; i < bufferSize - 1; i++)
    {
        if(wave[i] > wave[i+1] && wave[i-1] < wave[i]) //if found a peak
        {
            pair tmp;
            tmp.offset = i;
            tmp.power = wave[i];
            wek.push_back(tmp);
        }
    }
}
