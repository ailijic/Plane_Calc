#pragma once

// TODO: Make pure again

#include "i4/i4.h"

#ifdef __cplusplus
#define REAL(m) m
#else
#define REAL(m) CONCAT(Real_, m)
#endif

typedef struct Real {
  real t;
} Real;

Real* REAL(ctor)(Real const* a_this);
void  REAL(dtor)(Real* a_this);
Real* REAL(init)(Real* a_this, real a_value);

real REAL(convert)(Real*a_this);

Real* REAL(absValue)(Real* a_out, Real const* a_value);
Real*      REAL(neg)(Real* a_out, Real const* a_value);
Real*        REAL(e)(Real* a_out, Real const* a_value);  // e^a_value

bool  REAL(isEqual)(Real const* a_lhs, Real const* a_rhs);
Real*     REAL(max)(Real* a_out, Real const* a_lhs, Real const* a_rhs);
Real*     REAL(min)(Real* a_out, Real const* a_lhs, Real const* a_rhs);

Real* REAL(add)(Real* a_out, Real const* a_lhs, Real const* a_rhs);
Real* REAL(sub)(Real* a_out, Real const* a_lhs, Real const* a_rhs);
Real* REAL(mul)(Real* a_out, Real const* a_lhs, Real const* a_rhs);
Real* REAL(div)(Real* a_out, Real const* a_lhs, Real const* a_rhs);