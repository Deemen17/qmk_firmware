#include "de_lighting_via.h"
#include "de_lighting.h"
#ifdef VIA_ENABLE
#    include "via.h"
#endif

void de_lighting_via_custom_value_command(uint8_t *data, uint8_t length) {
    if (length < 3 || data[1] != DE_LIGHTING_VIA_CHANNEL_ID) {
#ifdef VIA_ENABLE
        data[0] = id_unhandled;
#endif
        return;
    }

    uint8_t channel = data[2];
    switch (data[0]) {
        case DE_LIGHTING_VIA_GET_CHANNEL:
            data[3] = de_lighting_channel_enabled(channel);
            break;
        case DE_LIGHTING_VIA_SET_CHANNEL:
            if (length < 4 || !de_lighting_channel_set_enabled(channel, data[3])) {
#ifdef VIA_ENABLE
                data[0] = id_unhandled;
#endif
                return;
            }
            de_lighting_dispatch_event(&(de_lighting_event_record_t){.type = DE_LIGHTING_EVENT_CHANNEL_CHANGED, .data = &(de_lighting_channel_event_t){.channel = channel, .enabled = data[3]}});
            break;
        case DE_LIGHTING_VIA_SAVE:
            de_lighting_save();
            break;
        default:
#ifdef VIA_ENABLE
            data[0] = id_unhandled;
#endif
            break;
    }
}
