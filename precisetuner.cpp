#include "precisetuner.h"
#include "fft.h"

PreciseTuner::PreciseTuner()
{
    recorder.create_sound();
    recorder.start_capturing();

    QVBoxLayout *tunerLayout = new QVBoxLayout;

    graph = new GraphFFT(this);


    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGraph()));

    timer->start(10); //rysuj co sekunde

    updateGraph();

    tunerLayout->addWidget(graph);
    setLayout(tunerLayout);
    setWindowTitle("Tuner");
    resize(800, 650);
}

void PreciseTuner::updateGraph()
{
    std::array<float, bufferSize> bufor = recorder.get_waveData();
    graph->setData(bufor);
}

