#include "i4/real.h"
#include "i4/math.h"
#include <stddef.h>
#include <stdbool.h>

Real* Real_init(Real* a_this, real a_value)
{
  a_this->t = a_value;
  return a_this;
}

real Real_convert(Real a_this) { return a_this.t; }

Real Real_e(Real a_value)
{ // e^a_value
  Real ret = { .t = e(a_value.t) };
  return ret;
}

Real Real_add(Real a_lhs, Real a_rhs)
{
  Real ret = { .t = a_lhs.t + a_rhs.t };
  return ret;
}

Real Real_sub(Real a_lhs, Real a_rhs)
{
  Real ret = { .t = a_lhs.t - a_rhs.t };
  return ret;
}

Real Real_mul(Real a_lhs, Real a_rhs)
{
  Real ret = { .t = a_lhs.t * a_rhs.t };
  return ret;
}

Real Real_div(Real a_lhs, Real a_rhs)
{
  Real ret = { .t = a_lhs.t / a_rhs.t };
  return ret;
}

Real Real_absValue(Real a_value)
{
  Real ret = { .t = absValue(a_value.t) };
  return ret;
}

Real Real_max(Real a_lhs, Real a_rhs)
{
  // TODO: Which of these is faster?
  // return (isgreater(a_lhs.t, a_rhs.t)) ? (Real){a_lhs.t}
  //                                      : (Real){a_rhs.t};
  //  max(a,b) = (a+b+abs(a-b))/2
  real a = a_lhs.t, b = a_rhs.t;
  Real ret = { .t = (a + b + absValue(a - b)) / (real)2.0 };
  return ret;
}

Real Real_min(Real a_lhs, Real a_rhs)
{
  Real ret;
  if (isLessEqual(a_lhs.t, a_rhs.t)) {
    ret.t = a_lhs.t;
  } else {
    ret.t = a_rhs.t;
  }
  return ret;
  // TODO is this faster?
  // min(a,b) = (a+b-abs(a-b))/2
}

bool Real_isLessEqual(Real a_lhs, Real a_rhs)
{
  return isLessEqual(a_lhs.t, a_rhs.t);
}

bool Real_isEqual(Real a_lhs, Real a_rhs)
{
  Real absTol, relTol;
  absTol.t = DBL_EPSILON;
  relTol.t = (real)DBL_EPSILON * Real_max(absValue(a_lhs), absValue(a_rhs)).t;

  return isLessEqual(absValue(sub(a_lhs, a_rhs)), max(absTol, mul(relTol, max(absValue(a_lhs), absValue(a_rhs)))));
}