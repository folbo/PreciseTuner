#ifndef GRAPHWAVE_H
#define GRAPHWAVE_H

#include "qcustomplot.h"
#include "constans.h"

class GraphWave : public QWidget
{
    Q_OBJECT
public:
    GraphWave(QWidget *parent = 0);

    void setData(std::array<float, bufferSize> buffer);

private:
    QCustomPlot *plot;

    QVector<double> x;
    QVector<double> y;

    int range; //how many samples should it show?

    int width, height;
};

#endif // GRAPHWAVE_H
