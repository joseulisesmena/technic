#ifndef STW_H
#define STW_H
#ifdef __cplusplus
#include "SoundTouch.h"
#else
typedef
    struct SoundTouch
        SoundTouch;

#endif

#ifdef __cplusplus
using namespace soundtouch;
extern "C" {
#endif
    extern void st_new(SoundTouch *st);
    extern void st_setChannels(SoundTouch *st, int channels);
    extern void st_setSampleRate(SoundTouch *st, uint samplerate);
    extern void st_setPitchSemiTones(SoundTouch *st, int newPitch);
    extern void st_putSamples(SoundTouch *st, int16_t *samples, uint nsamples);
    extern void st_setTempoChange(SoundTouch *st, int newTempo);
    extern int16_t * st_receiveSamples(SoundTouch *st);
#ifdef __cplusplus
} //extern "C"
#endif
#endif //STW_H
