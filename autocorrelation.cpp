#include "autocorrelation.h"

AutoCorrelation::AutoCorrelation()
{
    freq = 0;
}

void AutoCorrelation::analyse(std::array<float, bufferSize> wave, int max_samples)
{
    float sum = 0, sum_old = 0, max = 0;
    float norm = 0;
    int pd_state = 0;
    int thresh = 0;
    int period = 0;
    for (int i = 0; i < max_samples; i++)
    {
        sum_old = sum;
        sum = 0;

        for(int j = 0; j < max_samples; j++)
        {
            sum += wave[j]*wave[j+i];
            if(i == 0)
                norm = sum;
            sum /= norm;

        }
        // Peak Detect

        if (pd_state == 2 && (sum-sum_old) <=0)
        {
            period = i;
            pd_state = 3;
        }
        if (pd_state == 1 && (sum > thresh) && (sum-sum_old) > 0)
            pd_state = 2;
        if (!i && pd_state == 0)
        {
            thresh = sum * 0.5;
            pd_state = 1;
        }

/*
        if(sum > max)
        {
            max = sum;
            period = i;
        }
        */
    }
    // Frequency identified in Hz
    freq = (float)sampleRate/period;

    }

