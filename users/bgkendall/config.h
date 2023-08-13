// © 2023 bgkendall (@bgkendall)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#ifdef RGB_STATUS_WS2812_ENABLE
#   ifdef RGB_MATRIX_LED_COUNT
#       if RGB_MATRIX_LED_COUNT != 1
#           pragma error("Only one status WS2812 supported")
#       endif
#   else
#       define RGB_MATRIX_LED_COUNT 1
#   endif
#endif
