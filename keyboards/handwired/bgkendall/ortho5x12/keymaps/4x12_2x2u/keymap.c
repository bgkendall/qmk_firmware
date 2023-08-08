#include QMK_KEYBOARD_H

#include "bgk_encoder.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
    [KL_DEF] = LAYOUT_2x2u
    (
        XXXXXXX,     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
        KC_GESC,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPC,
        KC_TAB,      KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,
        KC_LSFT,     KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_UP,      KC_RSSL,
        KC_LCTL,     KC_LALT,    KC_LGUI, MO(KL_FN),          KC_SPACE,                KC_ENT,        MO(KL_NUM),    KC_LEFT,    KC_DOWN,    KC_RGHT
    ),

    [KL_NUM] = LAYOUT_2x2u
    (
        XXXXXXX,     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
        KC_GRV,      KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_BSPC,
        SCMD(KC_4),  KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_MINS,    KC_PLUS,    KC_LBRC,    KC_RBRC,    KC_GRV,
        _______,     KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,   G(KC_0),    G(KC_MINS), G(KC_EQL),  G(KC_UP),     KC_BSLS,
        _______,     _______,    _______, TT(KL_NP),          _______,                 _______,          _______,  G(KC_LEFT), G(KC_DOWN), G(KC_RGHT)
    ),

    [KL_NP] = LAYOUT_2x2u
    (
        XXXXXXX,     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
        KC_ESC,      XXXXXXX,    XXXXXXX,    KC_PEQL,    XXXXXXX,    XXXXXXX,    KC_P7,      KC_P8,      KC_P9,      KC_PAST,    KC_PSLS,    KC_BSPC,
        KC_TAB,      KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_P4,      KC_P5,      KC_P6,      KC_PPLS,    KC_PMNS,    KC_QUOT,
        KC_LSFT,     KC_Z,       KC_X,       KC_C,       KC_V,       XXXXXXX,    KC_P1,      KC_P2,      KC_P3,      KC_PDOT,    KC_UP,      KC_PENT,
        _______,     _______,    _______, MO(KL_FN),           _______,                KC_P0,         TO(KL_DEF),    KC_LEFT,    KC_DOWN,    KC_RGHT
    ),

    [KL_FN] = LAYOUT_2x2u
    (
        XXXXXXX,     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
        KC_NLCK,     KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,    KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,    KC_DEL,
        KC_CAPS,     BK_LDQUO,   BK_RDQUO,   BK_LSQUO,   BK_RSQUO,   KC_PLMI,    BK_MDASH,   KC_UNDS,    KC_EQL,     KC_LCBR,    KC_RCBR,    KC_TILD,
        _______,     CK_M1,      CK_M2,   LCAG(KC_F10),  KC_BTN3,    KC_NOEQ,    BK_NDASH,   KC_MUTE,    KC_VOLD,    KC_VOLU,    KC_PGUP,    KC_PIPE,
        _______,     KC_RALT,    _______,    _______,        G(KC_SPACE),              KC_PENT,       TT(KL_META),   KC_HOME,    KC_PGDN,    KC_END
    ),

    [KL_META] = LAYOUT_2x2u
    (
        XXXXXXX,     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
     TO(KL_DEF),     KC_BRID,    KC_BRIU,    XXXXXXX,    RESET,      DEBUG,      XXXXXXX,    XXXXXXX,    XXXXXXX,    RGB_VAD,    RGB_VAI,    XXXXXXX,
        KC_MPLY,   G(C(KC_BSLS)),LCAG(KC_F2),LCAG(KC_F3),KC_F14,     KC_F15,     KC_F16,     KC_F17,     KC_F18,     KC_F19,     RGB_SPD,    RGB_SPI,
        RGB_M_P,     RGB_M_SN,   RGB_M_X,    RGB_M_SW,   RGB_M_R,    RGB_M_B,    RGB_M_K,    RGB_M_G,    RGB_RMOD,   RGB_MOD,    RGB_SAI,    RGB_M_T,
        XXXXXXX,     XXXXXXX,    XXXXXXX, TO(KL_DEF),          RGB_TOG,                RGB_TOG,       TO(KL_DEF),    RGB_HUD,    RGB_SAD,    RGB_HUI
    )
};

const uint16_t PROGMEM encodermaps[][1][2] =
{
    [KL_DEF]  = { { KC_PGDN, KC_PGUP } },
    [KL_NUM]  = { { KC_BRID, KC_BRIU } },
    [KL_NP]   = { { KC_PGDN, KC_PGUP } },
    [KL_FN]   = { { KC_VOLD, KC_VOLU } },
    [KL_META] = { { RGB_VAD, RGB_VAI } }
};

//void keymap_pre_init_user(void)
//{
//    // Set custom key handler for encoders
//    bgkencoder_init(&process_custom_keycode);
//}
