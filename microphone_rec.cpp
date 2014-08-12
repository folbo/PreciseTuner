#include "microphone_rec.h"
#include <cstring>
#include <chrono>
#include <thread>

MicrophoneRec::MicrophoneRec()
{
    //system initialization
    FMOD::System_Create(&system);
    system->setOutput(FMOD_OUTPUTTYPE_DSOUND);

    //playback devices
    system->setDriver(0);

    //record devices
    record_driver = 0;
    system->setSoftwareFormat(sampleRate, FMOD_SOUND_FORMAT_PCMFLOAT, 1, 0, FMOD_DSP_RESAMPLER_LINEAR);
    result = system->init(32, FMOD_INIT_NORMAL, 0);

    //create sound to record to
    create_sound();
}

MicrophoneRec::~MicrophoneRec()
{
    sound->release();
    system->release();

}

void MicrophoneRec::create_sound()
{
    if (sound != NULL)
        sound->release();

    FMOD_CREATESOUNDEXINFO sound_info;

    std::memset(&sound_info, 0, sizeof(FMOD_CREATESOUNDEXINFO));

    sound_info.cbsize = sizeof(FMOD_CREATESOUNDEXINFO);
    sound_info.length = sampleRate * sizeof(float) * 0.5;
    sound_info.numchannels = 1;
    sound_info.defaultfrequency = sampleRate;
    sound_info.format = FMOD_SOUND_FORMAT_PCMFLOAT;

    system->createSound(0, FMOD_2D | FMOD_SOFTWARE | FMOD_LOOP_NORMAL | FMOD_OPENUSER, &sound_info, &sound);
}


void MicrophoneRec::start_capturing()
{
    system->recordStart(record_driver, sound, true);

    std::this_thread::sleep_for(std::chrono::microseconds(100));

    system->playSound(FMOD_CHANNEL_REUSE, sound, false, &channel);

    //mute output
    channel->setVolume(0);
}

void MicrophoneRec::stop_capturing()
{
    channel->stop();

    // Stop recording
    system->recordStop(record_driver);

    // Free sound recording buffer
    sound->release();
    sound = NULL;
}


std::array<float, bufferSize> MicrophoneRec::get_waveData()
{
    channel->getWaveData(wave_data.data(), bufferSize, 0); //0 for mono
    return wave_data;
}
