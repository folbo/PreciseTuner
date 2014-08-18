#include "precisetuner.h"
#include "fft.h"
#include <math.h>
PreciseTuner::PreciseTuner()
{
    recorder = new MicrophoneRec();
    recorder->create_sound();
    recorder->start_capturing();

    autocorel = new AutoCorrelation();

    QVBoxLayout *tunerLayout = new QVBoxLayout;

    graph = new GraphFFT(this);

    freqLabel = new QLabel("xD",this);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGraph()));

    timer->start(10); //rysuj co sekunde

    updateGraph();

    tunerLayout->addWidget(graph);
    tunerLayout->addWidget(freqLabel);
    setLayout(tunerLayout);
    setWindowTitle("Tuner");
    resize(800, 650);
}

void PreciseTuner::updateGraph()
{
    std::array<float, bufferSize> bufor = recorder->get_waveData();
    graph->setData(bufor);

    if(bufor[0] != 0 && bufor[2] != 0) //first loop makes array null o_O
        autocorel->analyse(bufor, bufferSize/*ceil(sampleRate/graph->baseFreq())*2 */); //TODO: ogranicznik FFT

    //freqLabel->setText(QString::number(graph->baseFreq()));
    freqLabel->setText(QString::number(autocorel->getFrequency()));
}

