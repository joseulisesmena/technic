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

    extern int st_new(int channels, uint samplerate, 
		       int newTempo, int16_t *samples, uint nsamples);

#ifdef __cplusplus
} //extern "C"
#endif
#endif //STW_H
