/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#pragma once

#ifdef ENCODER_ENABLE
#ifndef VIAL_ENABLE

#include "quantum.h"

static pin_t bgkencoders_pad_a[] = ENCODERS_PAD_A;
#define BGK_NUM_ENCODERS sizeof(bgkencoders_pad_a)/sizeof(pin_t)
extern const uint16_t encodermaps[][BGK_NUM_ENCODERS][2];

void bgkencoder_init(bool (*custom_keycode_handler)(uint16_t, bool));

void bgkencoder_update(uint8_t encoder_index, bool clockwise);

#endif // VIAL_ENABLE
#endif // ENCODER_ENABLE
