#include "graphfft.h"

GraphFFT::GraphFFT(QWidget *parent) :
    QWidget(parent)
{
    width = 500;
    height = 200;

    x.resize(fftN/2);
    y.resize(fftN/2);

    for(int i = 0; i <fftN/2; i++)
    {
        x[i] = i*sampleRate/fftN; //set freq table
    }

    resize(width, height);

    plot = new QCustomPlot(this);
    plot->addGraph();
    plot->resize(width, height);
    plot->xAxis->setRange(0,sampleRate/2); //0 to Nyquist freq
    plot->yAxis->setRange(0,11); // power range? idk

    plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    plot->show();
}


void GraphFFT::setData(std::array<float, bufferSize> buffer)
{
    fft fourier;
    fourier.take_input(buffer.data(), bufferSize);
    fourier.execute();
    fourier.compute_powers();
    std::array<float, fftN/2> fft_data = fourier.get_powers();

    for(int i = 0; i < fftN/2; i++)
    {
        y[i] = fft_data[i];
    }

    plot->graph(0)->setData(x, y);
    plot->replot();
}
