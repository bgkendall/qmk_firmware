#pragma once

#include "quantum_keycodes.h"
#include "bgk_keycodes.h"

enum LAYERS
{
    KL_COLEMAK = 0,
    KL_QWERTY,
    KL_NUMBER,
    KL_SYMBOL_CM,
    KL_SYMBOL_QW,
    KL_NAVIGATION,
    KL_FUNCTION,
    KL_META,
    RGBL_OK,
    RGBL_CAPS
};

enum
{
    CK_CRSVRT = SAFE_RANGE,
    CK_CRSHRZ,
    CK_CRSTOG,
    CK_LTDN,
    CK_RTUP
};
