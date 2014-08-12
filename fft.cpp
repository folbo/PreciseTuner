#include "fft.h"
#include <math.h>

fft::fft()
{
    in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * fftN);
    out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * fftN);

    for(int i=0; i < fftN; i++)
    {
        in[i][0] = 0;
        in[i][1] = 0;
        out[i][0] = 0;
        out[i][1] = 0;
    }

    plan = fftw_plan_dft_1d(fftN, in, out, FFTW_FORWARD, FFTW_ESTIMATE);
}

fft::~fft()
{
    fftw_destroy_plan(plan);
    fftw_free(in);
    fftw_free(out);
}


//methods
void fft::take_input(float *buffer, int buffer_size)
{
    if(buffer_size > fftN)
        return;
    for(int i = 0; i < buffer_size; i++)
    {
        in[i][0] = buffer[i];
    }
}

void fft::execute()
{
    fftw_execute(plan);
}

void fft::compute_powers()
{
    for(int i = 0; i < fftN/2; i++)
    {
        powers[i] = sqrt(out[i][0]*out[i][0] + out[i][1]*out[i][1]);
    }
}
