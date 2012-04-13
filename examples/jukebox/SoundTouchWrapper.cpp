#include "SoundTouchWrapper.h"
using namespace soundtouch; 

void st_new(SoundTouch * st) {
    SoundTouch abc;
    *st = abc;
    return;
}
void st_setChannels(SoundTouch *st, int channels) {
    st->setChannels(channels);
    return;
}
void st_setSampleRate(SoundTouch *st, uint samplerate) {
    st->setSampleRate(samplerate);
    return;
}
void st_setPitchSemiTones(SoundTouch *st, int newPitch) {
    st->setPitchSemiTones(newPitch);
    return;
    }
void st_putSamples(SoundTouch *st, int16_t *samples, uint nsamples){
    st->putSamples((const int16_t*)samples, nsamples);
    return;
}
void st_setTempoChange(SoundTouch *st, int newTempo) {
    st->setTempoChange(newTempo);
    return;
}
void st_receiveSamples(SoundTouch *st, int16_t *output, uint maxsamples) {
     st->receiveSamples(output, maxsamples);
     return;
}
//hello
