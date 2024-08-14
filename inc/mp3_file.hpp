#pragma once

#include <vector>
#include <memory>
#include "sound_file.hpp"
#include "minimp3.h"

class Mp3File : public SoundFile {
public:
    Mp3File(const uint8_t* data, const size_t size);

    eSoundFileFormats soundFileType() const override {
        return eSoundFileFormats::SOUND_FILE_MP3;
    }

    SampleChunk nextSampleChunk() const override;

    void reset() const {
        data_offset_ = 0;
    }
private:
    static constexpr const char* const TAG{"Mp3File"};
    std::unique_ptr<SoundSample> samples_{nullptr};  
    const uint8_t *data_{nullptr};
    mutable mp3dec_t mp3d_{};
    mutable mp3dec_frame_info_t frame_info_{};
    mutable size_t data_offset_{};
    mutable SampleChunk curr_chunk_{};
    mutable size_t data_size_{};
};
