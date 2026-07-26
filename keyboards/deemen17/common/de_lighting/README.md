# DE Lighting

DE Lighting is the reusable lighting engine for DE keyboards. It owns lighting
state, channel configuration, persistence, events, and renderer coordination. RGB
Matrix remains the rendering backend and no RGB Matrix internals are modified.

## Architecture

Keyboard code registers channel descriptors and calls the public lifecycle hooks:

```c
keyboard_post_init_user() -> de_lighting_init()
process_record_user()    -> de_lighting_process_record()
housekeeping_task_user() -> de_lighting_task()
```

All updates are expressed as `de_lighting_event_t` records passed through
`de_lighting_dispatch_event()`. Keyboard, VIA, and keycode code do not call RGB
Matrix directly; the renderer translates active channels into RGB Matrix flags.

## Channels

A keyboard supplies any number of descriptors:

```c
static const de_lighting_channel_desc_t channels[] = {
    {.name = "BACKLIGHT", .led_flags = LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR, .default_enable = true},
    {.name = "UNDERGLOW", .led_flags = LED_FLAG_UNDERGLOW, .default_enable = true},
};
```

The engine stores enabled channels as descriptor-indexed state. Increase
`DE_LIGHTING_MAX_CHANNELS` before including the engine if a keyboard needs more
than the default build-time channel capacity.

## EEPROM

Configuration is versioned. Version 1 stores the config version, channel count,
and descriptor-indexed channel enablement in the user EEPROM datablock. Future migrations should be added in
`de_lighting_eeprom_load()` without exposing raw globals to keyboard code.

## VIA

VIA integration is an adapter. Route `via_custom_value_command_kb()` to
`de_lighting_via_custom_value_command()`. VIA command payloads use
`DE_LIGHTING_VIA_CHANNEL_ID` and operate on channel indexes.

## Extending

1. Add hardware-specific channel descriptors in the keyboard folder.
2. Register descriptors before `de_lighting_init()`.
3. Add new events to `de_lighting_event.h` and handle them in engine modules.
4. Keep effects in RGB Matrix; add only selection, state, and policy logic here.
