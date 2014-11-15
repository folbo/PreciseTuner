#include "autocorrelation.h"
#include <vector>

AutoCorrelation::AutoCorrelation()
{
    freq = 0;
}

void AutoCorrelation::analyse(std::array<float, bufferSize> wave, int max_samples)
{
    float sum = 0;
    float norm = 0;

    /*
    int pd_state = 0;
    int thresh = 0;
    int period = 0;
    */

    std::vector<float> ac_data;

    for (int i = 0; i < bufferSize/2; i++)
    {
        sum = 0;

        for(int j = 0; j < bufferSize/2; j++)
        {
            //if(j+i > max_samples) break;

            sum += wave[j]*wave[j+i];


        }

        if(i == 0)
            norm = sum;
        sum /= norm;

        ac_data.push_back(sum);

        // Peak Detect

        /*
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

        */
    }


    float max = ac_data[0]*0.5;
    int max_i = 0;
    bool first_peak = true;
    for(int i = max_samples/2; i < ac_data.size(); i++)
    {
        if(ac_data[i] > max)
        {
            if(first_peak == false)
            {
                max = ac_data[i];
                max_i = i;
            }
            else first_peak = false;
        }

    }
    // Frequency identified in Hz
    if(max_i != 0)
        freq = (float)sampleRate/max_i;
    else
        freq = 0;

    }

