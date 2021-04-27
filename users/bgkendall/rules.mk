ifeq ($(strip $(ENCODER_ENABLE)), yes)
    SRC += bgk_encoder.c
endif

ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
    SRC += bgk_rgb.c
endif
