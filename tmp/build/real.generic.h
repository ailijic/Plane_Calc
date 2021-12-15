#pragma once

/* macro_name used by generator */
#define GEN_LINE(macro_name, type, fn_name) type : fn_name


#define absValue(m, ...) _Generic((m), \
	GEN_LINE(absValue, F32 , F32_absValue), \
	GEN_LINE(absValue, F64 , F64_absValue), \
	GEN_LINE(absValue, F80 , F80_absValue), \
	GEN_LINE(absValue, int , Int_absValue), \
	GEN_LINE(absValue, long , Long_absValue), \
	GEN_LINE(absValue, long long , LongLong_absValue), \
	GEN_LINE(absValue, Real , Real_absValue) \
)((m))

#define add(m, ...) _Generic((m), \
	GEN_LINE(add, Real , Real_add) \
)((m))

#define convert(m, ...) _Generic((m), \
	GEN_LINE(convert, Real , Real_convert) \
)((m))

#define divy(m, ...) _Generic((m), \
	GEN_LINE(divy, Real , Real_divy) \
)((m))

#define e(m, ...) _Generic((m), \
	GEN_LINE(e, F32 , F32_e), \
	GEN_LINE(e, F64 , F64_e), \
	GEN_LINE(e, F80 , F80_e), \
	GEN_LINE(e, Real , Real_e) \
)((m))

#define init(m, ...) _Generic((m), \
	GEN_LINE(init, Real* , Real_init) \
)((m))

#define isEqual(m, ...) _Generic((m), \
	GEN_LINE(isEqual, Real , Real_isEqual) \
)((m))

#define isLessEqual(m, ...) _Generic((m), \
	GEN_LINE(isLessEqual, F32 , F32_isLessEqual), \
	GEN_LINE(isLessEqual, Real , Real_isLessEqual) \
)((m))

#define max(m, ...) _Generic((m), \
	GEN_LINE(max, Real , Real_max) \
)((m))

#define min(m, ...) _Generic((m), \
	GEN_LINE(min, Real , Real_min) \
)((m))

#define mul(m, ...) _Generic((m), \
	GEN_LINE(mul, Real , Real_mul) \
)((m))

#define neg(m, ...) _Generic((m), \
	GEN_LINE(neg, F32 , F32_neg), \
	GEN_LINE(neg, F64 , F64_neg), \
	GEN_LINE(neg, F80 , F80_neg), \
	GEN_LINE(neg, int , Int_neg), \
	GEN_LINE(neg, long , Long_neg), \
	GEN_LINE(neg, long long , LongLong_neg), \
	GEN_LINE(neg, Real , Real_neg) \
)((m))

#define sub(m, ...) _Generic((m), \
	GEN_LINE(sub, Real , Real_sub) \
)(m, __VA_ARGS__)
