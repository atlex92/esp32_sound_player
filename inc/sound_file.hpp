#pragma once

#include <stddef.h>
#include <stdint.h>

using SoundSample = int16_t;

enum eSoundFileFormats { SOUND_FILE_MP3 = 0, SOUND_FILE_WAV, SOUND_FILE_UNKNOWN };

struct SampleChunk {
  const SoundSample* samples;
  size_t length;
  uint32_t sample_rate;
};

class SoundFile {
public:
  virtual SampleChunk nextSampleChunk() const = 0;
  virtual eSoundFileFormats soundFileType() const = 0;
  virtual ~SoundFile() = default;
  virtual void reset() const = 0;
};
