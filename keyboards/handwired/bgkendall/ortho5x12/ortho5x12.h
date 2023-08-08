#pragma once

#include "quantum.h"

#ifdef KEYBOARD_handwired_bgkendall_ortho5x12_rev1
  #include "rev1.h"
#endif
#ifdef KEYBOARD_handwired_bgkendall_ortho5x12_rev2
  #include "rev2.h"
#endif
#ifdef KEYBOARD_handwired_bgkendall_ortho5x12_rev2_miryoku
  #include "rev2_miryoku.h"
#endif
#ifdef KEYBOARD_handwired_bgkendall_ortho5x12_rev3
  #include "rev3.h"
#endif

#include "users/bgkendall/bgk_keycodes.h"

enum RGB_LAYERS
{
    RGBL_A = 0,
    RGBL_B,
    RGBL_C,
    RGBL_D,
    RGBL_E,
    RGBL_F,
    RGBL_G,
    RGBL_H,
    RGBL_I,
    RGBL_J,
    RGBL_K,
    RGBL_L,
    RGBL_M,
    RGBL_N,
    RGBL_O,
    RGBL_P,
    RGBL_Q,
    RGBL_R,
    RGBL_S,
    RGBL_OK,
    RGBL_CAPSWORD,
    RGBL_CAPSLOCK
};

#ifndef VIAL_ENABLE
#ifdef TAP_DANCE_ENABLE

enum TAP_DANCE_KEYCODES
{
    TD_CPCT = 0,
    TD_LRBR,
    TD_LRB2,
    TD_LRB3,
    TD_LRB4,
    TD_LRB5,
    TD_GESC,
    TD_QESC,
    TD_QUOT
};

#else

#define TD(k) KC_NO

#endif // TAP_DANCE_ENABLE

#endif // ¬VIAL_ENABLE
