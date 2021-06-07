ifeq ($(strip $(ENCODER_ENABLE)), yes)
    SRC += bgk_encoder.c bgk_cmd-tab.c
endif

ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
    SRC += bgk_rgb.c
endif
