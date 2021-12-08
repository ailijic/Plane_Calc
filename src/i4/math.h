#pragma once

#include <stdlib.h>

#ifdef __cplusplus
#include <cmath>
#else
#include <math.h>
#endif

// TODO: I think we only need float.h for epsilon
/*
#ifdef __cplusplus
#include <cfloat>
#else
#include <float.h>
#endif
*/

/*
#ifdef __cplusplus
#define islessequal(m1, m2) std::islessequal(m1, m2)
#endif
*/

#ifdef __cplusplus
#define MATH(m) m
#else
#define Math(m) CONCAT(Math_, m)
#endif

static inline F32 e(F32 a_value) { return expf(a_value); }
static inline F64 e(F64 a_value) { return  exp(a_value); }
static inline F80 e(F80 a_value) { return expl(a_value); }

static inline F32 absValue(F32 a_value) { return fabsf(a_value); }
static inline F64 absValue(F64 a_value) { return  fabs(a_value); }
static inline F80 absValue(F80 a_value) { return fabsl(a_value); }

static inline int       absValue(int a_value)       { return   abs(a_value); }
static inline long      absValue(long a_value)      { return  labs(a_value); }
static inline long long absValue(long long a_value) { return llabs(a_value); }

static inline