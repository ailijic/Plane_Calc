#pragma once

#include "i4/real.h"
#include "i4/i4.h"

#define TIME(m) PREFIX(Time_, m)

typedef struct Time {
	Real t;
} Time;

Time* TIME(ctor)(Time* a_this);
void  TIME(dtor)(Time* a_this);

Time  TIME(hours)  (real a_value);
Time  TIME(minutes)(real a_value);
Time  TIME(seconds)(real a_value);