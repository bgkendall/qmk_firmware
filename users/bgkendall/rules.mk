ifeq ($(strip $(ENCODER_ENABLE)), yes)
    ifneq ($(strip $(VIAL_ENCODERS_ENABLE)), yes)
        SRC += bgk_encoder.c
    endif
endif

ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
    SRC += bgk_rgb.c
endif

SRC += bgk_keycommands.c bgk_keycodes.c
