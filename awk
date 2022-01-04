const Real* Real_init(Real* a_this, real a_value);
real Real_convert(Real a_this) __attribute__ ((const));
Real Real_absValue(Real a_value) __attribute__ ((const));
Real Real_neg(Real a_value) __attribute__ ((const));
Real Real_e(Real a_value) __attribute__ ((const));
_Bool Real_isEqual(Real a_lhs, Real a_rhs) __attribute__ ((const));
_Bool Real_isLessEqual(Real a_lhs, Real a_rhs) __attribute__ ((const));
Real Real_max(Real a_lhs, Real a_rhs) __attribute__ ((const));
Real Real_min(Real a_lhs, Real a_rhs) __attribute__ ((const));
Real Real_add(Real a_lhs, Real a_rhs) __attribute__ ((const));
Real Real_sub(Real a_lhs, Real a_rhs) __attribute__ ((const));
Real Real_mul(Real a_lhs, Real a_rhs) __attribute__ ((const));
Real Real_div(Real a_lhs, Real a_rhs) __attribute__ ((const));
static inline int Int_neg(int a_value) { return -a_value; }
static inline long Long_neg(long a_value) { return -a_value; }
static inline long long LongLong_neg(long long a_value) { return -a_value; }
static inline int Int_absValue(int a_value) { return abs(a_value); }
static inline long Long_absValue(long a_value) { return labs(a_value); }
static inline long long LongLong_absValue(long long a_value) { return llabs(a_value); }
real Real_convert(Real a_this) { return a_this.t; }
