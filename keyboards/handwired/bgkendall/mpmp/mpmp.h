#pragma once

#include "quantum.h"

#include "bgk_keycodes.h"


#define LAYOUT( \
    K00, K01, K02, K03, \
    K10, K11, K12, ECW, \
    K20, K21, K22, EAC, \
    K30, K31, K32, NUL  \
) { \
    { K03,   KC_NO, KC_NO, KC_NO }, \
    { ECW,   K00,   K01,   K02   }, \
    { EAC,   K10,   K11,   K12   }, \
    { KC_NO, K20,   K21,   K22   }, \
    { KC_NO, K30,   K31,   K32   }  \
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

void mpmp_rgb_init(void);
