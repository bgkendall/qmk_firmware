#include "bgk_encoder.h"

const uint16_t PROGMEM encodermaps[][1][2] =
{
    [KL_DEF]  = { { KC_PGDN, KC_PGUP } },
    [KL_NUM]  = { { KC_PGDN, KC_PGUP } },
    [KL_FN]   = { { KC_BRID, KC_BRIU } },
    [KL_FN1]  = { { KC_VOLD, KC_VOLU } },
    [KL_META] = { { RGB_VAD, RGB_VAI } }
};

void keymap_pre_init_user(void)
{
    // Set custom key handler for encoders
    bgkencoder_init(&process_custom_keycode);
}
