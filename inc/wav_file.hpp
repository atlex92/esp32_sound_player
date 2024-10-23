#pragma once

#include <string.h>
#include "format_wav.h"
#include "sound_file.hpp"

class WavFile : public SoundFile {
public:
  WavFile(const uint8_t* data, const size_t size) {
    if (size >= sizeof(wav_header_t)) {
      memcpy(&header_, data, sizeof(wav_header_t));
      data_size_ = (size - sizeof(wav_header_t)) / sizeof(SoundSample);
      data_ = reinterpret_cast<const SoundSample*>(data) + sizeof(wav_header_t);
    }
  }

  SampleChunk nextSampleChunk() const override {
    SampleChunk ret{.samples = data_, .length = data_size_, .sample_rate = header_.fmt_chunk.sample_rate};
    return ret;
  }

  eSoundFileFormats soundFileType() const override {
    return eSoundFileFormats::SOUND_FILE_WAV;
  }

  void reset() const override {
  }

private:
  static constexpr const char* const TAG{"WavFile"};
  wav_header_t header_{};
  const SoundSample* data_{};
  size_t data_size_{};
};
