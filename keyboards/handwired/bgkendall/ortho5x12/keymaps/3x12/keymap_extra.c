#include "bgk_encoder.h"

const uint16_t PROGMEM encodermaps[][1][2] =
{
    [KL_DEF]         = { { KC_PGDN, KC_PGUP } },
    [KL_DEF1]        = { { G(KC_MINS), G(KC_EQL) } },
    [KL_DEF2]        = { { KC_LBRC, KC_RBRC } },
    [KL_DEF3]        = { { KC_WH_U, KC_WH_D } },
    [KL_DEF4]        = { { KC_WH_R, KC_WH_L } },
    [KL_NUM]         = { { KC_VOLD, KC_VOLU } },
    [KL_NP]          = { { KC_PGDN, KC_PGUP } },
    [KL_FN...KL_FN1] = { { KC_BRID, KC_BRIU } },
    [KL_META]        = { { RGB_VAD, RGB_VAI } }
};

//void keymap_pre_init_user(void)
//{
//    // Set custom key handler for encoders
//    bgkencoder_init(&process_custom_keycode);
//}
