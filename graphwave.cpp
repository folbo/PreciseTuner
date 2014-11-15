#include "graphwave.h"

GraphWave::GraphWave(QWidget *parent) :
    QWidget(parent)
{
    width = 500;
    height = 100;

    range = 400;

    x.resize(range);
    y.resize(range);

    for(int i = 0; i <range; i++)
    {
        x[i] = i;
    }

    resize(width, height);

    plot = new QCustomPlot(this);
    plot->addGraph();
    plot->resize(width, height);
    plot->xAxis->setRange(0,range);
    plot->yAxis->setRange(-1,1); // power range? idk

    plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    plot->show();
}

void GraphWave::setData(std::array<float, bufferSize> buffer)
{
    int start_index = 0;
    for(int i = 0; i < bufferSize; i++)
    {
        if(buffer[i] == 0 && buffer[i+1] > 0)
        {
            start_index = i;
            break;
        }
    }

    for(int i = 0; i < range; i++)
    {
         y[i] = buffer[i + start_index];
    }


    plot->graph(0)->setData(x, y);
    plot->replot();
}
