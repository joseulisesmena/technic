#include "SoundTouchWrapper.h"
#include "SoundTouch.h"
#include <stdio.h>
using namespace soundtouch; 



extern "C" void st_new(int channels, uint samplerate, int newTempo, int16_t *samples, uint nsamples) {
    SoundTouch *st = new SoundTouch();
    printf("new soundtouch!\n");
    st->setChannels(channels);
    st->setSampleRate(samplerate);
    st->putSamples((const int16_t *)samples, nsamples);
    st->setTempo(1.0);
    st->setTempoChange(100);
    st->setPitchSemiTones(1);
    //st->setRateChange(100);
    while(st->numUnprocessedSamples() > 0) {};
    st->receiveSamples(samples,nsamples);
    return;
}
