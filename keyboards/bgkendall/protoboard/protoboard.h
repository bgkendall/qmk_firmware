#pragma once

#include "quantum.h"

#define LAYOUT( \
    K00, K01, \
    K10, K11, \
    K20, K21, \
              K33 \
) { \
    { K00,   K01,   KC_NO }, \
    { K10,   K11,   KC_NO }, \
    { K20,   K21,   KC_NO }, \
    { KC_NO, KC_NO, K33   }  \
}
