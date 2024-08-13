#pragma once

#include "isound_player.hpp"
#include "driver/gpio.h"
#include "driver/i2s_pdm.h"

class PdmSoundPlayer : public ISoundPlayer{
public:
    explicit PdmSoundPlayer(const gpio_num_t clk_io, const gpio_num_t data_io);
    void play(const SoundFile* file) override;
private:
    static constexpr const char* const TAG{"PdmSoundPlayer"};
    void playMp3File(const SoundFile* file);
    void playWavFile(const SoundFile* file);
    void play(const SoundSample* samples, const size_t size);
    void play(const std::vector<int16_t>& samples);
    void initialize(const uint32_t freq);
    void deinitialize();
    uint32_t freq_{};
    const gpio_num_t clk_gpio_{};
    const gpio_num_t dout_gpio_{};
    i2s_pdm_tx_config_t pdm_tx_cfg_;
    i2s_chan_handle_t tx_chan_handler_;
};