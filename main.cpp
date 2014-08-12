#include <QtWidgets>
#include "microphone_rec.h"
#include "precisetuner.h"
#include "constans.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);


    PreciseTuner tuner;
    tuner.show();

    return app.exec();
}
