#include "precisetuner.h"
#include "fft.h"

PreciseTuner::PreciseTuner()
{
    recorder = new MicrophoneRec();
    recorder->create_sound();
    recorder->start_capturing();

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

    freqLabel->setText(QString::number(graph->baseFreq()));
}

