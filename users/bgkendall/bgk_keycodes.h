//
//  bgk_keycodes.h
//
//  © 2020 Barnaby Kendall
//

#pragma once


#include "quantum.h"


// Typographical quotes
//
#define BK_LSQUO    RALT(KC_RBRACKET)           // ‘
#define BK_RSQUO    RALT(KC_RIGHT_CURLY_BRACE)  // ’
#define BK_LDQUO    RALT(KC_LBRACKET)           // “
#define BK_RDQUO    RALT(KC_LEFT_CURLY_BRACE)   // ”

// Common symbols
//
#define BK_NDASH    RALT(KC_MINUS)      // En-dash –
#define BK_MDASH    RALT(KC_UNDERSCORE) // Em-dash —
#define BK_NE       RALT(KC_EQUAL)      // Not equal ≠
#define BK_PLUSMN   RALT(KC_PLUS)       // Plus or minus ±
#define BK_HELLIP   RALT(KC_SCOLON)     // Ellipsis …

// Shift/slashes
//
#define BK_LSBS     LSFT_T(KC_BSLASH)
#define BK_RSSL     RSFT_T(KC_SLASH)

// Application shortcuts
//
#define BK_1PASS            LGUI(LCTL(KC_QUOT))
#define BK_TOGGL            LCAG(KC_F10)

// Custom keys requiring special processing
//
enum BGK_CUSTOM_KEYCODES
{
#ifdef VIA_ENABLE
    BK_000 = QK_KB_0,
#else
    BK_000 = SAFE_RANGE,
#endif
    BK_BGK,
    BK_APP_BACKWARD,
    BK_APP_FORWARD,
    BK_TIMES,
    BK_LOCK,
    BK_ELEFT,
    BK_ERIGHT,
    BK_EDOWN,
    BK_EUP,
    BK_EFLIP,
    KB_SAFE_RANGE
};

#define BK_BSDEL  BK_BACKSPACE_DELETE
#define BK_COMDOT BK_COMMA_DOT
#define BK_GRVDEL BK_GRAVE_DELETE
#define BK_GRVEQ  BK_GRAVE_EQUALS
#define BK_GRVQUO BK_GRAVE_QUOTE
