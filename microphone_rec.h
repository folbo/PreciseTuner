#ifndef MICROPHONEREC_H
#define MICROPHONEREC_H

#include <fmodex/fmod.hpp>
#include <fmodex/fmodlinux.h>
#include <array>
#include "constans.h"


class MicrophoneRec
{
public:
    MicrophoneRec();
    ~MicrophoneRec();

    void create_sound();
    void start_capturing();
    void stop_capturing();

    std::array<float, bufferSize> get_waveData();


private:
    FMOD::System          *system;
    FMOD::Sound           *sound;
    FMOD::Channel         *channel;
    FMOD_RESULT            result;

    int record_driver;

    std::array<float, bufferSize> wave_data;
};

#endif // MICROPHONEREC_H
