#pragma once

#include "de_lighting_channel.h"
#include "de_lighting_event.h"
#include "de_lighting_keycode.h"
#include "de_lighting_renderer.h"
#include "de_lighting_state.h"
#include "de_lighting_via.h"

void de_lighting_init(void);
void de_lighting_task(void);
void de_lighting_dispatch_event(const de_lighting_event_record_t *event);
void de_lighting_save(void);
