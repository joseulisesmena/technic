#include "SoundTouchWrapper.h"
#include "SoundTouch.h"
#include "BPMDetect.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
using namespace soundtouch; 



extern "C" int st_new(int channels, uint samplerate, int newTempo, int16_t *samples, uint nsamples) {
    SoundTouch *st = new SoundTouch();
    BPMDetect *bd = new BPMDetect(channels, samplerate);
    int i;
    int16_t *newbuf;
    printf("new soundtouch!\n");
    st->setChannels(channels);
    st->setSampleRate(samplerate);
    st->putSamples((int16_t *)samples, nsamples);
    bd->inputSamples((int16_t *)samples, nsamples);
    
    // st->setTempo(1.0);
    //	st->setTempoChange(124);
    st->setPitchSemiTones(2);
    //    st->setRateChange(100);
    printf("%i\n",sizeof(int16_t));
    i = st->numSamples() * sizeof(int16_t) *channels;
    //i = 0;
    newbuf =(int16_t *) malloc(i);
    st->receiveSamples(newbuf,i);
    memcpy(samples,newbuf,i);
    return i;
}
