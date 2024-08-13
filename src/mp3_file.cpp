#define MINIMP3_IMPLEMENTATION
#define MINIMP3_ONLY_MP3
#define MINIMP3_NO_STDIO

#include <stdio.h>
#include "mp3_file.hpp"
#include "esp_log.h"

#define FILE_CHUNK_SIZE 4096

Mp3File::Mp3File(const uint8_t *data, size_t size) : samples_{new SoundSample[MINIMP3_MAX_SAMPLES_PER_FRAME]} {
    data_ = data;
    mp3dec_init(&mp3d_);
}

SampleChunk Mp3File::nextSampleChunk() const {
    const int samples_decoded{mp3dec_decode_frame(&mp3d_, data_ + data_offset_, FILE_CHUNK_SIZE, samples_.get(), &frame_info_)};
    curr_chunk_.samples = samples_.get();
    data_offset_ += frame_info_.frame_bytes;
    curr_chunk_.length = samples_decoded;
    curr_chunk_.sample_rate = frame_info_.hz;
    return curr_chunk_;
}