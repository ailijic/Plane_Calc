#pragma once

//#include <stdlib.h>
#include <stdlib.h>
#include <float.h>
#include <stdbool.h>
#include "i4/define.h"
#include "i4/type.h"
#include <math.h>
//#include <tgmath.h>


//TODO: Why do I have to define these manually
#define islessequal(m1, m2) ((m1) <= (m2))

static inline F32 F32_e(F32 a_value) { return expf(a_value); }
static inline F64 F64_e(F64 a_value) { return  exp(a_value); }
static inline F80 F80_e(F80 a_value) { return expl(a_value); }

static inline F32 F32_neg(F32 a_value) { return -a_value; }
static inline F64 F64_neg(F64 a_value) { return -a_value; }
static inline F80 F80_neg(F80 a_value) { return -a_value; }

static inline F32 F32_absValue(F32 a_value) { return fabsf(a_value); }
static inline F64 F64_absValue(F64 a_value) { return  fabs(a_value); }
static inline F80 F80_absValue(F80 a_value) { return fabsl(a_value); }

static inline int            Int_absValue(int a_value)       { return   abs(a_value); }
static inline long          Long_absValue(long a_value)      { return  labs(a_value); }
static inline long long LongLong_absValue(long long a_value) { return llabs(a_value); }

static inline bool F32_isLessEqual(F32 a_lhs, F32 a_rhs) { return islessequal(a_lhs, a_rhs); }
