// © 2023 bgkendall (@bgkendall)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#if defined(RGB_MATRIX_LED_COUNT) && RGB_MATRIX_LED_COUNT != 1
#   pragma error("Only one status LED supported - RGB_MATRIX_LED_COUNT must be 1")
#endif
