#include "pdm_sound_player.hpp"
#include "mp3_file.hpp"
#include "wav_file.hpp"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <memory>

extern const uint8_t wav_file_start asm("_binary_test_wav_start");
extern const size_t wav_file_len asm("test_wav_length");
static const char* const wav_file_format{"wav"};

extern const uint8_t mp3_file_start asm("_binary_test_mp3_start");
extern const size_t mp3_file_len asm("test_mp3_length");
static const char* const mp3_file_format{"mp3"};

#define PDM_TX_CLK_IO GPIO_NUM_4  // I2S PDM TX clock io number
#define PDM_TX_DOUT_IO GPIO_NUM_6 // I2S PDM TX data out io number

extern "C" void app_main(void*) {

    std::unique_ptr<SoundFile> sound_file_wav{new WavFile(&wav_file_start, wav_file_len)};
    std::unique_ptr<SoundFile> sound_file_mp3{new Mp3File(&mp3_file_start, mp3_file_len)};

    std::unique_ptr<PdmSoundPlayer> pdm_player{new PdmSoundPlayer(PDM_TX_CLK_IO, PDM_TX_DOUT_IO)};

    printf("Start playing wav sound file!\r\n");
    pdm_player->play(sound_file_wav.get());
    printf("File is finished\r\n");

    vTaskDelay(pdMS_TO_TICKS(1000));
    
    printf("Start playing mp3 sound file!\r\n");
    pdm_player->play(sound_file_mp3.get());
    printf("File is finished\r\n");
}