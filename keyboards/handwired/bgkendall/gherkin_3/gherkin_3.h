/*
Copyright 2022 bgkendall

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "quantum.h"

#define XXX KC_NO

#define LAYOUT_ortho_4x10(\
    K00, K01, K02, K03, K04, K05, K10, K11, K12, K13, \
    K14, K15, K20, K21, K22, K23, K24, K25, K30, K31, \
    K32, K33, K34, K35, K40, K41, K42, K43, K44, K45, \
    N00, N01, N02, K55, K50, N03, K52, N04, N05, N06  \
) { \
    { K00, K01, K02, K03, K04, K05 }, \
    { K10, K11, K12, K13, K14, K15 }, \
    { K20, K21, K22, K23, K24, K25 }, \
    { K30, K31, K32, K33, K34, K35 }, \
    { K40, K41, K42, K43, K44, K45 }, \
    { K50, XXX, K52, XXX, XXX, K55 }  \
}


// Bug fix for Tap Dance codes within mod-hold definitions in Miryoko generated code:
#define KC_TD(k) KC_##k

#ifdef TAP_DANCE_ENABLE

enum TAP_DANCE_KEYCODES
{
    QUOT = 0
};

#else

#define TD(k) KC_##k

#endif // TAP_DANCE_ENABLE
