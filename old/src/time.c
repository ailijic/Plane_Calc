#include <assert.h>

#include "i4/mem.h"
#include "i4/type.h"
#include "sfc.h"
#include "time.h"
#include <stddef.h>
#include "lift_drag_ratio.h"
#include "generic.h"

Time* Time_ctor(Time* a_this)
{
	void* vp = NULL;
	vp = ctor(vp, ssizeof(*a_this));
	assert(vp != NULL);
	return vp;
}

void  Time_dtor(Time* a_this)
{
	assert(a_this != NULL);
	void* vp = a_this;
	dtor(vp);
}

Time  Time_hours(real a_value)
{
	Real r;
  init(&r, a_value * (real)60.0 * (real)60.0);
	Time ret = {.t = r};
	return ret;
}

Time  Time_minutes(real a_value)
{
	Real r;
  init(&r, a_value, (real)60.0);
	Time ret = {.t = r};
	return ret;
}

Time  Time_seconds(real a_value)
{
	Real r;
  init(&r, (real)a_value);
	Time ret = {.t = r};
	return ret;
}