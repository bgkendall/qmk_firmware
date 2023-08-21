// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_A,    KC_B,    KC_C,
        KC_X,    KC_Y,    KC_Z
    ),
    [1 ... (DYNAMIC_KEYMAP_LAYER_COUNT - 1)] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
      )

};

#ifdef ENCODER_MAP_ENABLE

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0 ... DYNAMIC_KEYMAP_LAYER_COUNT - 1] =
        {
            ENCODER_CCW_CW(KC_BRID, KC_BRIU),
            ENCODER_CCW_CW(KC_VOLD, KC_VOLU)
        }
};

#endif // ENCODER_MAP_ENABLE
