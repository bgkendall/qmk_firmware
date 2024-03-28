ifneq (,$(findstring vial,$(CURDIR)))

    $(info Enabling Vial)

    # Current directory contains "vial", so enable Vial Settings
    VIA_ENABLE = yes
    VIAL_ENABLE = yes
    VIAL_INSECURE = yes

    # Save space
    GRAVE_ESC_ENABLE = no
    QMK_SETTINGS = no
    CONSOLE_ENABLE = no
    SPACE_CADET_ENABLE = no
    MOUSEKEY_ENABLE = no

else

    COMBO_ENABLE = no

endif
