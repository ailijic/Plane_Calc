#pragma once

#include "i4/real.h"

typedef struct Time {
	Real t;
} Time;

Time* Time_ctor(Time* a_this);
void  Time_dtor(Time* a_this);
Time* Time_init(Time* a_this);

Time  Time_hours(real a_value);
Time  Time_minutes(real a_value);
Time  Time_seconds(real a_value);