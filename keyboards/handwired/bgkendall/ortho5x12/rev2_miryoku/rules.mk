# Bootloader for Elite-C
BOOTLOADER = atmel-dfu

ENCODER_MAP_ENABLE = yes

LAYOUTS = ortho_5x12
USER_NAME := manna-harbour_miryoku

ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
	SRC += users/bgkendall/bgk_rgb.c
endif
