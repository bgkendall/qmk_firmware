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
        KC_Q,    KC_W,    KC_D,    KC_P,    KC_F,    KC_J,    KC_L,    KC_O,    KC_Y,    KC_BSPC,
        KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_U,
 LSFT_T(KC_Z),   KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_ESC,
                                   KC_LGUI,     KC_SPACE,     KC_ENTER
    ),
    [1 ... (DYNAMIC_KEYMAP_LAYER_COUNT - 1)] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                   KC_TRNS,      KC_TRNS,     KC_TRNS
      )

};
