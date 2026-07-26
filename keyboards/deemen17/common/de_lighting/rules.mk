DE_LIGHTING_PATH = keyboards/deemen17/common/de_lighting

VPATH += $(DE_LIGHTING_PATH)
SRC += \
    $(DE_LIGHTING_PATH)/de_lighting.c \
    $(DE_LIGHTING_PATH)/de_lighting_channel.c \
    $(DE_LIGHTING_PATH)/de_lighting_eeprom.c \
    $(DE_LIGHTING_PATH)/de_lighting_keycode.c \
    $(DE_LIGHTING_PATH)/de_lighting_renderer.c \
    $(DE_LIGHTING_PATH)/de_lighting_state.c \
    $(DE_LIGHTING_PATH)/de_lighting_via.c

OPT_DEFS += -DDE_LIGHTING_ENABLE
