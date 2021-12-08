#pragma once

#include "i4/i4.h"

#ifdef __cplusplus
#define REAL(m) m
#else
#define REAL(m) CONCAT(Real_, m)
#endif

typedef struct Real {
  real t;
} Real;

Real* REAL(ctor)(Real* a_this);
void  REAL(dtor)(Real* a_this);
Real* REAL(init)(Real* a_this, real a_value);

real REAL(convert)(Real a_this) CONST;

Real REAL(absValue)(Real a_value) CONST;
Real      REAL(neg)(Real a_value) CONST;
Real        REAL(e)(Real a_value) CONST;  // e^a_value

bool  REAL(isEqual)(Real a_lhs, Real a_rhs)  CONST;
Real      REAL(max)(Real a_lhs, Real a_rhs)  CONST;
Real      REAL(min)(Real a_lhs, Real a_rhs)  CONST;

Real REAL(add)(Real a_lhs, Real a_rhs) CONST;
Real REAL(sub)(Real a_lhs, Real a_rhs) CONST;
Real REAL(mul)(Real a_lhs, Real a_rhs) CONST;
Real REAL(div)(Real a_lhs, Real a_rhs) CONST;