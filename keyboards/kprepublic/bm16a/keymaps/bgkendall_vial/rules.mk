VIA_ENABLE = yes
VIAL_ENABLE = yes
# Reduce firmware size:
LTO_ENABLE = yes
MAGIC_ENABLE = no
QMK_SETTINGS = no
COMBO_ENABLE = no
KEY_OVERRIDE_ENABLE = no
GRAVE_ESC_ENABLE = no

ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
	SRC += users/bgkendall/bgk_rgb.c
endif
