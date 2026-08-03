#include "de_lighting_via.h"
#include "de_lighting.h"
#ifdef VIA_ENABLE
#    include "via.h"
#endif

static void de_lighting_via_unhandled(uint8_t *data) {
#ifdef VIA_ENABLE
    data[0] = id_unhandled;
#else
    (void)data;
#endif
}

void de_lighting_via_custom_value_command(uint8_t *data, uint8_t length) {
#ifdef VIA_ENABLE
    if (length < 3 || data[1] != id_custom_channel) {
        de_lighting_via_unhandled(data);
        return;
    }

    uint8_t value_id = data[2];
    if (value_id < DE_LIGHTING_VIA_CHANNEL_0 || value_id > DE_LIGHTING_VIA_CHANNEL_7) {
        de_lighting_via_unhandled(data);
        return;
    }

    uint8_t channel = value_id - DE_LIGHTING_VIA_CHANNEL_0;
    switch (data[0]) {
        case id_custom_get_value:
            if (length < 4) {
                de_lighting_via_unhandled(data);
                return;
            }
            data[3] = de_lighting_channel_enabled(channel);
            break;
        case id_custom_set_value:
            if (length < 4 || !de_lighting_channel_set_enabled(channel, data[3])) {
                de_lighting_via_unhandled(data);
                return;
            }
            de_lighting_dispatch_event(&(de_lighting_event_record_t){.type = DE_LIGHTING_EVENT_CHANNEL_CHANGED, .data = &(de_lighting_channel_event_t){.channel = channel, .enabled = data[3]}});
            break;
        case id_custom_save:
            de_lighting_save();
            break;
        default:
            de_lighting_via_unhandled(data);
            break;
    }
#else
    de_lighting_via_unhandled(data);
#endif
}
