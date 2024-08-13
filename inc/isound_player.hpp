#pragma once

#include "sound_file.hpp"
#include <vector>

class ISoundPlayer {
public:
    virtual ~ISoundPlayer() = default;
    virtual void play(const SoundFile* file) = 0;
};
