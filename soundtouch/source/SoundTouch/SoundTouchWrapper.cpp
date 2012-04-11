#include "SoundTouchWrapper.h"
extern "C" {

    CSoundTouch * st_new() {
	(SoundTouch *)st = new SoundTouch();
	return (CSoundTouch *)st;
    }
    void st_setChannels(CSoundTouch *st, int channels) {
	(SoundTouch *)st->setChannels(channels);
	return;
    }
    void st_setSampleRate(CSoundTouch *st, uint samplerate) {
	(SoundTouch *)st->setSampleRate(samplerate);
	return;
    }
    void st_setPitchSemiTones(CSoundTouch *st, int newPitch) {
	(SoundTouch *)st->setPitchSemiTones(newPitch);
	return;
    }
    void st_putSamples(CSoundTouch *st, int16_t *samples, uint nsamples){
	(SoundTouch *)st->putSamples(samples, nsamples);
	return;
    }
    void st_setTempoChange(CSoundTouch *st, int newTempo) {
	(SoundTouch *)st->setTempoChange(newTempo);
	return;
    }
    int16_t * st_receiveSamples(CSoundTouch *st) {
	return (SoundTouch *)st->recieveSamples();
    }

} //extern "C"
