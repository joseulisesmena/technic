#include "SoundTouchWrapper.h"
#include "SoundTouch.h"
#include "BPMDetect.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
using namespace soundtouch; 



int  main() {
    int channels = 2;
    int samplerate = 44100;
    BPMDetect *bd = new BPMDetect(channels, samplerate);
    int i;
    long lsize;
    int16_t *buffer;
    FILE *fp = fopen("climax.bin", "r");
    
    fseek(fp,0,SEEK_END);
    lsize = ftell(fp);
    rewind(fp);

    buffer = (int16_t *) malloc(sizeof(int16_t)/sizeof(char) * lsize);
    fread(buffer,1,lsize/sizeof(int16_t),fp);
    printf("%i\n",lsize);


    bd->inputSamples(buffer, lsize/(sizeof(int16_t)*2));
    
    printf("%f\n",bd->getBpm());
    return 1;
}
