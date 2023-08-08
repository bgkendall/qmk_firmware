#include QMK_KEYBOARD_H

#include "bgk_encoder.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
    [KL_DEF] = LAYOUT_ortho_5x12
    (
        XXXXXXX, XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
        XXXXXXX, KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,         KC_U,         KC_I,         KC_O,         KC_P,         KC_BSPC,
        XXXXXXX, KC_A,         KC_S,         KC_D,         KC_F,         KC_G,         KC_H,         KC_J,         KC_K,         KC_L,         KC_PDOT,      KC_ENT,
        XXXXXXX, LSFT_T(KC_Z), LCTL_T(KC_X), LALT_T(KC_C),LT(KL_NUM,KC_V),LGUI_T(KC_SPC),TT(KL_FN),RGUI_T(KC_SPC),LT(KL_NP,KC_B),RALT_T(KC_N), RCTL_T(KC_M), RSFT_T(KC_ESC),
        XXXXXXX, XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX
    ),

    [KL_NUM] = LAYOUT_ortho_5x12
    (
        XXXXXXX, XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
        XXXXXXX, KC_1,         KC_2,         KC_3,         KC_4,         KC_5,         KC_6,         KC_7,         KC_8,         KC_9,         KC_0,         KC_MINS,
        XXXXXXX, KC_TAB,       KC_COMM,      KC_DOT,       KC_SLSH,      KC_BSLS,      KC_GRV,       KC_QUOT,      KC_SCLN,      KC_LBRC,      KC_RBRC,      KC_EQL,
        XXXXXXX, KC_LSFT,      KC_LCTL,      KC_LALT,      _______,      _______,      XXXXXXX,      _______,      KC_RGUI,      KC_RALT,      KC_RCTL,      KC_RSFT,
        XXXXXXX, XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX
    ),

    [KL_NP] = LAYOUT_ortho_5x12
    (
        XXXXXXX, XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
        XXXXXXX, KC_EXLM,      KC_AT,        KC_HASH,      KC_DLR,       KC_PERC,      KC_CIRC,      KC_AMPR,      KC_ASTR,      KC_LPRN,      KC_RPRN,      KC_UNDS,
        XXXXXXX, KC_CAPS,      KC_LT,        KC_GT,        KC_QUES,      KC_PIPE,      KC_TILD,      KC_DQUO,      KC_COLN,      KC_LCBR,      KC_RCBR,      KC_PLUS,
        XXXXXXX, KC_LSFT,      KC_LCTL,      KC_LALT,      KC_LGUI,      _______,      XXXXXXX,      _______,      _______,      KC_RALT,      KC_RCTL,      KC_RSFT,
        XXXXXXX, XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX
    ),

    [KL_FN] = LAYOUT_ortho_5x12
    (
        XXXXXXX, XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
        XXXXXXX, KC_GRV,       XXXXXXX,      KC_UP,        XXXXXXX,      KC_PGUP,      KC_HOME,      XXXXXXX,      KC_UP,        XXXXXXX,      KC_PGUP,      KC_DEL,
        XXXXXXX, KC_TAB,       KC_LEFT,      KC_DOWN,      KC_RGHT,      KC_PGDN,      KC_END,       KC_LEFT,      KC_DOWN,      KC_RGHT,      KC_PGDN,      KC_PENT,
        XXXXXXX, KC_LSFT,      KC_LCTL,      KC_LALT,      KC_LGUI,      _______,      TO(KL_DEF),   MO(KL_META),  KC_RGUI,      KC_RALT,      KC_RCTL,      KC_RSFT,
        XXXXXXX, XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX
    ),

    [KL_META] = LAYOUT_ortho_5x12
    (
        XXXXXXX, XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
        XXXXXXX, G(C(KC_BSLS)),KC_BRID,      KC_BRIU,      RESET,        XXXXXXX,      KC_F1,        KC_F2,        KC_F3,        KC_F4,        KC_F5,        KC_F6,
        XXXXXXX, BK_LDQUO,     BK_RDQUO,     BK_LSQUO,     BK_RSQUO,     XXXXXXX,      KC_F7,        KC_F8,        KC_F9,        KC_F10,       KC_F11,       KC_F12,
        XXXXXXX, CK_M1,        CK_M2,        LCAG(KC_F10), KC_BTN3,      RGB_TOG,      _______,      _______,      CK_M3,        KC_RALT,      KC_RCTL,      KC_RSFT,
        XXXXXXX, XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX
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

void keymap_pre_init_user(void)
{
    // Set custom key handler for encoders
    bgkencoder_init(&process_custom_keycode);
}
