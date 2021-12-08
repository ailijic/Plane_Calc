#include "i4/mem.h"
#include "i4/real.h"
#include <stdbool.h>

Real* REAL(ctor)(Real* a_this)
{
  return CAST(Real*, ctor(NULL, ssizeof(*a_this)));
}

void REAL(dtor)(Real* a_this) { dtor(CAST(void*, a_this)); }

Real* REAL(init)(Real* a_this, real a_value)
{
  a_this->t = a_value;
  return a_this;
}

real REAL(convert)(Real a_this) { return a_this.t; }

Real REAL(e)(Real a_value)
{ // e^a_value
  Real ret = { .t = e(a_value->t) };
  return ret;
}

Real REAL(add)(Real a_lhs, Real a_rhs)
{
  Real ret = { .t = a_lhs->t + a_rhs->t };
  return ret;
}

Real REAL(sub)(Real a_lhs, Real a_rhs)
{
  Real ret = { .t = a_lhs->t - a_rhs->t };
  return ret;
}

Real REAL(mul)(Real a_lhs, Real a_rhs)
{
  Real ret = { .t = a_lhs->t * a_rhs->t };
  return ret;
}

Real REAL(div)(Real a_lhs, Real a_rhs)
{
  Real ret = { .t = a_lhs->t / a_rhs->t };
  return ret;
}

Real REAL(absValue)(Real a_value)
{
  Real ret = { .t = absValue(a_value->t) };
  return ret;
}

Real REAL(max)(Real a_lhs, Real a_rhs)
{
  // TODO: Which of these is faster?
  // return (isgreater(a_lhs.t, a_rhs.t)) ? (Real){a_lhs.t}
  //                                      : (Real){a_rhs.t};
  //  max(a,b) = (a+b+abs(a-b))/2
  real a = a_lhs->t, b = a_rhs->t;
  Real ret = { .t = (a + b + absValue(a - b)) / CAST(real, 2.0) };
  return ret;
}

Real REAL(min)(Real a_lhs, Real a_rhs)
{
  Real ret;
  if (a_lhs->t <= a_rhs->t) {
    ret.t = a_lhs->t;
  } else {
    ret.t = a_rhs->t;
  }
  return ret;
  // TODO is this faster?
  // min(a,b) = (a+b-abs(a-b))/2
}

static bool REAL(isLessEqual)(Real a_lhs, Real a_rhs) CONST
{
  return isLessEqual(a_lhs.t, a_rhs.t);
}

bool REAL(isEqual)(Real a_lhs, Real a_rhs)
{
  Real absTol, relTol;
  absTol.t = CAST(real, DBL_EPSILON));
  relTol.t = CAST(real, DBL_EPSILON) * max(absValue(a_lhs), absValue(a_rhs));

  return isLessEqual(absValue(sub(a_lhs, a_rhs)), max(absTol, mul(relTol, max(absValue(a_lhs), absValue(a_rhs)))));
}