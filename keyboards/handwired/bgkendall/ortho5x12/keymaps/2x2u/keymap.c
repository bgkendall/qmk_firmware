#include QMK_KEYBOARD_H

#include "bgk_encoder.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
    [KL_DEF] = LAYOUT_2x2u
    (
        CK_TONL,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_BSPC,
        KC_GESC,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_MINS,
        KC_TAB,      KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,
        KC_LSFT,     KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_UP,      KC_RSSL,
        KC_LCTL,     KC_LALT,    KC_LGUI, MO(KL_FN),          KC_SPACE,                KC_ENT,        TT(KL_NP),     KC_LEFT,    KC_DOWN,    KC_RGHT
    ),
/*
    [KL_NUM] = LAYOUT_2x2u
    (
        KC_MUTE,     _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        KC_TILD,     KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,    KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,    KC_PLUS,
        KC_GRV,      KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_EQL,
        _______,     _______,    _______,    _______,    _______,    _______,    _______,  G(KC_0),    G(KC_MINS), G(KC_EQL),  G(KC_UP),     _______,
        _______,     _______,    _______, TT(KL_NP),           _______,                _______,          _______,  G(KC_LEFT), G(KC_DOWN), G(KC_RGHT)
    ),

    [KL_NP] = LAYOUT_2x2u
    (
        KC_NLCK,     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_NLCK,    KC_PEQL,    KC_PSLS,    KC_PAST,    XXXXXXX,    KC_BSPC,
        KC_ESC,      XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_P7,      KC_P8,      KC_P9,      KC_PMNS,    XXXXXXX,    KC_PMNS,
        KC_TAB,      KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_P4,      KC_P5,      KC_P6,      KC_PPLS,    KC_SCLN,    KC_QUOT,
        KC_LSFT,     KC_Z,       KC_X,       KC_C,       KC_V,       XXXXXXX,    KC_P1,      KC_P2,      KC_P3,      KC_PDOT,    KC_UP,      KC_PENT,
        _______,     _______,    _______, MO(KL_FN),           _______,                KC_P0,         TO(KL_DEF),    KC_LEFT,    KC_DOWN,    KC_RGHT
    ),
 */
    [KL_NP] = LAYOUT_2x2u
    (
        KC_NLCK,     KC_P1,      KC_P2,      KC_P3,      XXXXXXX,    XXXXXXX,    KC_NLCK,    KC_PEQL,    KC_PSLS,    KC_PAST,    XXXXXXX,    _______,
        KC_ESC,      KC_P4,      KC_P5,      KC_P6,      XXXXXXX,    XXXXXXX,    KC_P7,      KC_P8,      KC_P9,      KC_PMNS,    XXXXXXX,    _______,
        KC_TAB,      KC_P7,      KC_P8,      KC_P9,      XXXXXXX,    XXXXXXX,    KC_P4,      KC_P5,      KC_P6,      KC_PPLS,    _______,    _______,
        KC_LSFT,     KC_UP,      KC_P0,      KC_PDOT,    XXXXXXX,    XXXXXXX,    KC_P1,      KC_P2,      KC_P3,      KC_PDOT,    _______,    KC_PENT,
        KC_LEFT,     KC_DOWN,    KC_RGHT, MO(KL_DEF),    KC_SPACE,                     KC_P0,         TO(KL_DEF),    _______,    _______,    _______
    ),

    [KL_FN] = LAYOUT_2x2u
    (
        KC_END,      KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_NOEQ,    KC_PLMI,    KC_LCBR,    KC_RCBR,    KC_DEL,
        KC_ESC,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_F13,     KC_PIPE,    KC_LBRC,    KC_RBRC,    KC_PLUS,
        KC_CAPS,     BK_LDQUO,   BK_RDQUO,   BK_LSQUO,   BK_RSQUO,   SCMD(KC_4), KC_MPLY,    KC_MUTE,    KC_VOLD,    KC_VOLU,    KC_EQL,     KC_GRV,
        _______,     CK_M1,      CK_M2,   LCAG(KC_F10),  KC_BTN3,    KC_UNDS,    BK_NDASH,   BK_MDASH,   KC_BRID,    KC_BRIU,    KC_PGUP,    KC_BSLS,
        _______,     KC_RALT,    _______,    _______,        G(KC_SPACE),             KC_PENT,        TT(KL_META),   KC_HOME,    KC_PGDN,    KC_END
    ),

    [KL_META] = LAYOUT_2x2u
    (
        XXXXXXX,     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    RGB_VAD,    RGB_VAI,    XXXXXXX,
        XXXXXXX,     XXXXXXX,    XXXXXXX,    XXXXXXX,    RESET,      DEBUG,      XXXXXXX,    XXXXXXX,    XXXXXXX,    RGB_SPD,    RGB_SPI,    XXXXXXX,
        XXXXXXX,   G(C(KC_BSLS)),LCAG(KC_F2),LCAG(KC_F3),KC_F14,     KC_F15,     KC_F16,     KC_F17,     KC_F18,     KC_F19,     XXXXXXX,    XXXXXXX,
        RGB_M_P,     RGB_M_SN,   RGB_M_X,    RGB_M_SW,   RGB_M_R,    RGB_M_B,    RGB_M_K,    RGB_M_G,    RGB_RMOD,   RGB_MOD,    RGB_SAI,    RGB_M_T,
        XXXXXXX,     XXXXXXX,    XXXXXXX, TO(KL_DEF),          RGB_TOG,                RGB_TOG,       TO(KL_DEF),    RGB_HUD,    RGB_SAD,    RGB_HUI
    )
};

const uint16_t PROGMEM encodermaps[][1][2] =
{
    [KL_DEF]  = { { KC_PGDN, KC_PGUP } },
    [KL_DEF1] = { { G(KC_MINS), G(KC_EQL) } },
    [KL_DEF2] = { { KC_LBRC, KC_RBRC } },
    [KL_DEF3] = { { KC_WH_U, KC_WH_D } },
    [KL_DEF4] = { { KC_WH_R, KC_WH_L } },
    [KL_NUM]  = { { KC_VOLD, KC_VOLU } },
    [KL_NP]   = { { KC_PGDN, KC_PGUP } },
    [KL_FN]   = { { KC_BRID, KC_BRIU } },
    [KL_META] = { { RGB_VAD, RGB_VAI } }
};

//void keymap_pre_init_user(void)
//{
//    // Set custom key handler for encoders
//    bgkencoder_init(&process_custom_keycode);
//}
