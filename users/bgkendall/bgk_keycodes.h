//
//  bgk_keycodes.h
//  qmk-keyboard
//
//  Created by Barnaby on 2020-11-11.
//  © 2020 Barnaby Kendall. All rights reserved.
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
    BK_000 = SAFE_RANGE,
    BK_M1,
    BK_M2,
    BK_M3,
    BK_CMDTAB_BACKWARD,
    BK_CMDTAB_FORWARD,
    BK_COMMA_DOT,
    BK_GRAVE_DELETE,
    BK_TIMES,
    BK_PAREN,
    KB_SAFE_RANGE
};

#define BK_COMDOT BK_COMMA_DOT
#define BK_GDEL   BK_GRAVE_DELETE


// Command-Tab simulation
//
void bgkey_register_command_for_tab(void);

void bgkey_register_forward_command_tab(void);

void bgkey_register_backward_command_tab(void);

void bgkey_unregister_command_for_tab(void);
