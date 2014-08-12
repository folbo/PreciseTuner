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

private:
     QCustomPlot *plot;

     QVector<double> x;
     QVector<double> y;

     int width, height;

     MicrophoneRec  *ptr;
};

#endif // GRAPHFFT_H
