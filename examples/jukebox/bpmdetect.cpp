#include "SoundTouchWrapper.h"
#include "SoundTouch.h"
#include "BPMDetect.h"
#include "sndfile.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
using namespace soundtouch; 

int  main(int argc, char *argv[]) {
    int channels = 2;
    int samplerate = 44100;
    BPMDetect *bd = new BPMDetect(channels, samplerate);
    int i;
    int check;
    //long lsize;
    int *buffer;
    //FILE *fp = fopen("climax.bin", "r");
    SNDFILE* song;
    SF_INFO* songinfo = new SF_INFO();
    sf_count_t nframes;
    int nchannels;
    const char* filename = argv[1];

    //fseek(fp,0,SEEK_END);
    //lsize = ftell(fp);
    //rewind(fp);

    song = sf_open(filename, SFM_READ, songinfo);
    assert(song);
    nframes = songinfo->frames;
    nchannels = songinfo->channels;

    //buffer = (int16_t *) malloc(sizeof(int16_t)/sizeof(char) * lsize);
    //fread(buffer,1,lsize/sizeof(int16_t),fp);
    //printf("%i\n",lsize);

    buffer = (int*) malloc(sizeof(int) * nframes * nchannels);
    check = sf_readf_int(song, buffer, nframes);
    assert(check == nframes);

    bd->inputSamples((int16_t *)buffer, nframes);
    
    printf("%f\n",bd->getBpm());

    sf_close(song);
    return 0;
}
