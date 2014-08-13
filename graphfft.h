#ifndef GRAPHFFT_H
#define GRAPHFFT_H

#include <QtWidgets>
#include "qcustomplot.h"
#include "constans.h"
#include "fft.h"
#include "microphone_rec.h"

class GraphFFT : public QWidget
{
    Q_OBJECT
public:
    GraphFFT(QWidget *parent = 0);
    void setData(std::array<float, bufferSize> buffer);

    float baseFreq() { return base_freq; }

private:
     QCustomPlot *plot;


     QVector<double> x;
     QVector<double> y;

     int width, height;

     float base_freq;
};

#endif // GRAPHFFT_H
