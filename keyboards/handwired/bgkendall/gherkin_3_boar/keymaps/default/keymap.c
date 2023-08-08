// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ Q │ W │ D │ P │ F │ J │ L │ O │ Y │ ⇤ │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ A │ R │ S │ T │ G │ M │ N │ E │ I │ U │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ Z │ X │ C │ V │ B │ K │ H │ , │ . │Esc│
     * └───┴───┴───┼───┼───┴───┼───┼───┴───┴───┘
     *             │ ⌘ │       │ ↩︎ │
     *             └───┴───────┴───┘
     */
    [0] = LAYOUT(
        BL_TOGG,    KC_W,    KC_D,    KC_P,    KC_F,    KC_J,    KC_L,    KC_O,    KC_Y,    KC_BSPC,
        KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_U,
 LSFT_T(KC_Z),   KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_H,    KC_COMM, KC_DOT,  QK_BOOT,
                                   KC_LGUI,     KC_SPACE,     KC_ENTER
    ),
    [1 ... 2] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                   KC_TRNS,      KC_TRNS,     KC_TRNS
      )
};

#ifdef ENCODER_MAP_ENABLE

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0 ... 2] = { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT) }
};

#endif // ENCODER_MAP_ENABLE
