typedef void CSoundTouch;

#ifdef __cplusplus
extern "C" {
#endif
    CSoundTouch *st_new();
    void st_setChannels(CSoundTouch *st, int channels);
    void st_setSampleRate(CSoundTouch *st, uint samplerate);
    void st_setPitchSemiTones(CSoundTouch *st, int newPitch);
    void st_putSamples(CSoundTouch *st, int16_t *samples, uint nsamples);
    void st_setTempoChange(CSoundTouch *st, int newTempo);
    int16_t * st_receiveSamples(CSoundTouch *st);
#ifdef __cplusplus
} //extern "C"
#endif
