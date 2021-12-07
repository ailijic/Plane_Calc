// #include <math.h>
// #include <stddef.h>

#include "i4/mem.h"
// #include "i4/type.h"
// #include "i4/math.h"
#include "i4/real.h"

Real* REAL(ctor)(Real const* a_this) {
	return CAST(Real*, ctor(NULL, ssizeof(*a_this)));
}

void REAL(dtor)(Real* a_this) { dtor(CAST(void*, a_this)); }

Real* REAL(init)(Real* a_this, real a_value) {
  a_this->t = a_value;
  return a_this;
}

real REAL(convert)(Real* a_this) { return a_this->t; }

Real* REAL(e)(Real* a_out, Real const* a_value) {  // e^a_value
  a_out->t = e(a_value->t);
	return a_out;
}

Real* REAL(add)(Real* a_out, Real const* a_lhs, Real const* a_rhs)
{
  a_out->t = a_lhs->t + a_rhs->t;
  return a_out;
}

Real* REAL(sub)(Real* a_out, Real const* a_lhs, Real const* a_rhs)
{
  a_out->t = a_lhs->t - a_rhs->t;
  return a_out;
}

Real* REAL(mul)(Real* a_out, Real const* a_lhs, Real const* a_rhs)
{
  a_out->t = a_lhs->t * a_rhs->t;
  return a_out;
}

Real* REAL(div)(Real* a_out, Real const* a_lhs, Real const* a_rhs)
{
  a_out->t = a_lhs->t / a_rhs->t;
  return a_out;
}

Real* REAL(absValue)(Real* a_out, Real const* a_value)
{
  a_out->t = absValue(a_value->t);
  return a_out;
}

Real* REAL(max)(Real* a_out, Real const* a_lhs, Real const* a_rhs)
{
  // TODO: Which of these is faster?
  // return (isgreater(a_lhs.t, a_rhs.t)) ? (Real){a_lhs.t}
  //                                      : (Real){a_rhs.t};
  //  max(a,b) = (a+b+abs(a-b))/2
  real a = a_lhs->t, b = a_rhs->t;
  a_out->t = (a + b + absValue(a - b)) / CAST(real, 2.0);
	return a_out;
}

Real* REAL(min)(Real* a_out, Real const* a_lhs, Real const* a_rhs)
{
	if (a_lhs->t <= a_rhs->t) {
		a_out->t = a_lhs->t;
	} else {
		a_out->t = a_rhs->t;
	}
  return a_out;
  // min(a,b) = (a+b-abs(a-b))/2
}

/*
static Real emp(void)
{
	Real ret;
	ret.t = CAST(real, 0.0);
	return ret;
}
*/

bool REAL(isEqual)(Real const* a_lhs, Real const* a_rhs)
{
  Real tmp[10], absTol, relTol;
  init(&absTol, CAST(real, DBL_EPSILON));
  init(&relTol,
      CAST(real, DBL_EPSILON) * max(&tmp[0], absValue(&tmp[1], a_lhs), absValue(&tmp[2], a_rhs))->t);

  return absValue(&tmp[3], sub(&tmp[4], a_lhs, a_rhs))->t <= max(&tmp[5], &absTol,
             mul(&tmp[6], &relTol, max(&tmp[7], absValue(&tmp[8], a_lhs), absValue(&tmp[9], a_rhs))))
                                                                 ->t;
}