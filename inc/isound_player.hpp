#pragma once

#include <vector>
#include "sound_file.hpp"

class ISoundPlayer {
public:
  virtual ~ISoundPlayer() = default;
  virtual void play(const SoundFile* file) = 0;
};
