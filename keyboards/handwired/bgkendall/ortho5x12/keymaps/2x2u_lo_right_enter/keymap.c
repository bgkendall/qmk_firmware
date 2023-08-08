#include QMK_KEYBOARD_H

#include "bgk_encoder.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
    [KL_DEF] = LAYOUT_2x2u_lo_right_enter
    (
        KC_1,        KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,
        KC_TAB,      KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPC,
        KC_GESC,     KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,RSFT_T(KC_SCLN),   KC_ENT,
        KC_LSBS,     KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_UP,
        KC_LCTL,LALT_T(KC_GRV),RALT_T(KC_QUOT),KC_LGUI,MO(KL_FN),      KC_SPACE,     TT(KL_NUM),RGUI(KC_SLASH),KC_LEFT,    KC_DOWN,    KC_RGHT
    ),

    [KL_NUM] = LAYOUT_2x2u_lo_right_enter
    (
        XXXXXXX,     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_CLR,     KC_PEQL,    KC_PSLS,    KC_PAST,    _______,    _______,
        KC_TAB,      XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_P7,      KC_P8,      KC_P9,      KC_PMNS,    XXXXXXX,    _______,
        KC_ESC,      KC_A,       KC_S,       KC_D,       KC_F,       XXXXXXX,    KC_P4,      KC_P5,      KC_P6,      KC_PPLS,    _______,    KC_PENT,
        KC_LSFT,     KC_Z,       KC_X,       KC_C,       KC_V,       KC_SPC,     KC_P1,      KC_P2,      KC_P3,      KC_PDOT,    _______,
        KC_LCTL,     KC_LALT,    _______,    _______,    MO(KL_FN),       KC_P0,           _______,    _______,    _______,    _______,    _______
    ),

    [KL_FN] = LAYOUT_2x2u_lo_right_enter
    (
        KC_F1,       KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,
        S(KC_TAB),   KC_BRID,    KC_BRIU,    C(KC_UP),   C(KC_DOWN), _______,    _______,    _______,    _______,    _______,    SCMD(KC_4), KC_DEL,
        KC_CAPS,     KC_QUOT,    BK_LSQUO,   BK_RSQUO,   KC_DQUO,    BK_LDQUO,   BK_RDQUO,   KC_LBRC,    KC_RBRC,    KC_LCBR,    KC_RCBR,    KC_PENT,
     MO(KL_FN1),     CK_M1,    LCAG(KC_F10), _______,    KC_BTN3,    KC_MPRV,    KC_MNXT,    KC_MUTE,    KC_VOLD,    KC_VOLU,    KC_PGUP,
        KC_LCTL,     KC_LALT,    KC_RALT,    _______,    _______,          KC_MPLY,        TT(KL_META),  KC_RGUI,    KC_HOME,    KC_PGDN,    KC_END
    ),

    [KL_FN1] = LAYOUT_2x2u_lo_right_enter
    (
        _______,     _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,     _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        KC_MUTE,     _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,     _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_BRID,    KC_BRIU,    _______,
        _______,     _______,    _______,    _______,    _______,          _______,          _______,    _______,    _______,    _______,    _______
    ),

    [KL_META] = LAYOUT_2x2u_lo_right_enter
    (
        XXXXXXX,     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    RGB_SPD,    RGB_SPI,    RGB_VAD,    RGB_VAI,
        XXXXXXX,     LAG_NRM,    LAG_SWP,    XXXXXXX,    RESET,      XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
        XXXXXXX,     XXXXXXX,    XXXXXXX,    DEBUG,      XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    RGB_TOG,
        RGB_M_P,     RGB_M_SN,   RGB_M_X,    RGB_M_SW,   RGB_M_R,    RGB_M_B,    RGB_M_K,    RGB_M_G,    RGB_RMOD,   RGB_MOD,    RGB_SAI,
        XXXXXXX,     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,          RGB_TOG,          XXXXXXX,    RGB_M_T,    RGB_HUD,    RGB_SAD,    RGB_HUI
    )
};

const uint16_t PROGMEM encodermaps[][1][2] =
{
    [KL_DEF]  = { { KC_PGDN, KC_PGUP } },
    [KL_NUM]  = { { KC_PGDN, KC_PGUP } },
    [KL_FN]   = { { KC_BRID, KC_BRIU } },
    [KL_FN1]  = { { KC_VOLD, KC_VOLU } },
    [KL_META] = { { RGB_VAD, RGB_VAI } }
};

//void keymap_pre_init_user(void)
//{
//    // Set custom key handler for encoders
//    bgkencoder_init(&process_custom_keycode);
//}
