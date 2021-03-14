#pragma once

#include "quantum.h"

#include "users/bgkendall/keycodes.h"

#define LAYOUT( \
    K00, K01, K02, K03, \
    K10, K11, K12, K13, \
    K20, K21, K22, K23, \
    K30, K31, K32, K33  \
) { \
    { K03,   KC_NO, KC_NO, KC_NO }, \
    { K13,   K00,   K01,   K02   }, \
    { K23,   K10,   K11,   K12   }, \
    { KC_NO, K20,   K21,   K22   }, \
    { KC_NO, K30,   K31,   K32   }  \
}

#define KEYMAP( \
    K00, \
    K11, K12, K13, \
    K21, K22, K23, \
    K31, K32, K33, \
    K41, K42, K43  \
) { \
    { K00,   KC_NO, KC_NO, KC_NO }, \
    { KC_NO, K11,   K12,   K13   }, \
    { KC_NO, K21,   K22,   K23   }, \
    { KC_NO, K31,   K32,   K33   }, \
    { KC_NO, K41,   K42,   K43   }  \
}

enum LAYERS
{
    KL_NUM = 0,
    KL_CALC,
    KL_APP,
    KL_FN,
    KL_LED,
    KL_SHIFT,
    RGBL_OK,
    RGBL_CAPS,
    RGBL_CMDTAB
};

enum CUSTOM_KEYCODES
{
    CK_CMDTAB_FORWARD = SAFE_RANGE,
    CK_CMDTAB_BACKWARD,
    CK_SPACEBACK
};

#define CK_CTFD CK_CMDTAB_FORWARD
#define CK_CTBK CK_CMDTAB_BACKWARD

void mpmp_rgb_init(void);
