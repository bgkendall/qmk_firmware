ifneq (,$(findstring vial,$(CURDIR)))

    $(info Enabling Vial)

    # Current directory contains "vial", so enable Vial Settings
    VIA_ENABLE = yes
    VIAL_ENABLE = yes
    VIAL_INSECURE = yes

else

    COMBO_ENABLE = no

endif
