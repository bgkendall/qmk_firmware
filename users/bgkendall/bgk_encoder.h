//
//  bgk_encoder.h
//  qmk-keyboard
//
//  Created by Barnaby on 2020-10-10.
//  © 2020 Barnaby Kendall. All rights reserved.
//

#pragma once

#ifdef ENCODER_ENABLE

#include "quantum.h"

static pin_t bgkencoders_pad_a[] = ENCODERS_PAD_A;
extern const uint16_t encodermaps[][sizeof(bgkencoders_pad_a)/sizeof(pin_t)][2];

void bgkencoder_init(bool (*custom_keycode_handler)(uint16_t,bool));

void bgkencoder_update(uint8_t encoder_index, bool clockwise);

void encoder_update_user(uint8_t encoder_index, bool clockwise);

#endif /* encoder_enable */
