#include <assert.h>

#include "i4/mem.h"
#include "time.h"

#ifdef NULL
#undef NULL
#define NULL nullptr
#endif

Time* TIME(ctor)(Time* a_this)
{
	void* vp = NULL;
	vp = ctor(vp, ssizeof(*a_this));
	assert(vp != NULL);
	return CAST(Time*, vp);
}

void  TIME(dtor)(Time* a_this)
{
	assert(a_this != NULL);
	void* vp = a_this;
	dtor(vp);
}

Time  TIME(hours)  (real a_value)
{
	Real r;
  init(&r, a_value * CAST(real, 60.0) * CAST(real, 60.0));
	Time ret = {.t = r};
	return ret;
}

Time  TIME(minutes)(real a_value)
{
	Real r;
  init(&r, a_value * CAST(real, 60.0));
	Time ret = {.t = r};
	return ret;
}

Time  TIME(seconds)(real a_value)
{
	Real r;
  init(&r, a_value);
	Time ret = {.t = r};
	return ret;
}