#pragma once

#include "i4/define.h"
#include "i4/type.h"
#include <stdbool.h>

typedef struct Real {
  real t;
} Real;

Real* Real_ctor(Real* a_this);
void  Real_dtor(Real* a_this);
Real* Real_init(Real* a_this, real a_value);

real Real_convert(Real a_this) CONST;

Real Real_absValue(Real a_value) CONST;
Real      Real_neg(Real a_value) CONST;
Real        Real_e(Real a_value) CONST;  // e^a_value

bool     Real_isEqual(Real a_lhs, Real a_rhs) CONST;
bool Real_isLessEqual(Real a_lhs, Real a_rhs) CONST;
Real         Real_max(Real a_lhs, Real a_rhs) CONST;
Real         Real_min(Real a_lhs, Real a_rhs) CONST;

Real Real_add(Real a_lhs, Real a_rhs) CONST;
Real Real_sub(Real a_lhs, Real a_rhs) CONST;
Real Real_mul(Real a_lhs, Real a_rhs) CONST;
Real Real_div(Real a_lhs, Real a_rhs) CONST;