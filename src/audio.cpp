#include <ao/ao.h>
#include <mpg123.h>
#include <bits/stdc++.h>

using namespace std;
#define BITS 8


mpg123_handle *mh;
unsigned char *buffer;
size_t buffer_size;
size_t done;
int err;

int driver;
ao_device *dev;

ao_sample_format format;
int channels, encoding;
long rate;

void audio_play() {
    /* initializations */
    ao_initialize();
    driver = ao_default_driver_id();
    mpg123_init();
    mh = mpg123_new(NULL, &err);
    buffer_size = 32;
    buffer = (unsigned char*) malloc(buffer_size * sizeof(unsigned char));

    /* open the file and get the decoding format */
    mpg123_open(mh, "assets/song.mp3");
    cout<<"open"<<endl;
    mpg123_getformat(mh, &rate, &channels, &encoding);

    /* set the output format and open the output device */
    format.bits = mpg123_encsize(encoding) * BITS;
    format.rate = rate;
    format.channels = channels;
    format.byte_format = AO_FMT_NATIVE;
    format.matrix = 0;
    dev = ao_open_live(driver, &format, NULL);
    /* decode and play */
    cout<<"playing"<<endl;
    while  (1) {
        while (mpg123_read(mh, buffer, buffer_size, &done) == MPG123_OK)
            ao_play(dev, (char*) buffer, done);
        mpg123_seek(mh, 0, SEEK_SET);
    }
    /* clean up */
    free(buffer);
    ao_close(dev);
    mpg123_close(mh);
    mpg123_delete(mh);
    mpg123_exit();
    ao_shutdown();
}