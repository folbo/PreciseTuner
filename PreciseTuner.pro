#-------------------------------------------------
#
# Project created by QtCreator 2014-08-11T14:57:05
#
#-------------------------------------------------

QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PreciseTuner
TEMPLATE = app


SOURCES += main.cpp \
    precisetuner.cpp \
    qcustomplot.cpp \
    fft.cpp \
    microphone_rec.cpp \
    graphfft.cpp \
    zerocrossing.cpp \
    autocorrelation.cpp

HEADERS += \
    precisetuner.h \
    qcustomplot.h \
    fft.h \
    microphone_rec.h \
    constans.h \
    graphfft.h \
    zerocrossing.h \
    autocorrelation.h

LIBS += /usr/lib/libfftw3.so \
    /usr/lib/libfmodex.so

QMAKE_CXXFLAGS += -std=c++0x
