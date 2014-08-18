#ifndef PRECISETUNER_H
#define PRECISETUNER_H

#include <QtWidgets>
#include "qcustomplot.h"
#include "graphfft.h"
#include "microphone_rec.h"
#include "autocorrelation.h"

class PreciseTuner : public QWidget
{
    Q_OBJECT
public:
    PreciseTuner();

public slots:
    void updateGraph();

private:
    GraphFFT    *graph;
    QLabel *freqLabel;

    MicrophoneRec *recorder;

    AutoCorrelation *autocorel;

};

#endif // PRECISETUNER_H
