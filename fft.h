#ifndef FFT_H
#define FFT_H

#include <fftw3.h>
#include <array>
#include "constans.h"

class fft
{
public:
    fft();
    ~fft();

    void take_input(float *buffer, int buffer_size);
    void execute();
    void compute_powers();

    float find_base_freq();

    std::array<float, fftN/2> get_powers() { return powers; }

private:
    fftw_plan plan;
    fftw_complex *in;
    fftw_complex *out;

    std::array<float, fftN/2> powers;

};

#endif // FFT_H
