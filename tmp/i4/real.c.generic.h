#pragma once

/* macro_name and num_args used by generator */
#define GEN_LINE(macro_name, num_args, type, fn_name) type : fn_name


#define absValue(m) _Generic((m), \
	GEN_LINE(absValue, 1, F32 , F32_absValue), \
	GEN_LINE(absValue, 1, F64 , F64_absValue), \
	GEN_LINE(absValue, 1, F80 , F80_absValue), \
	GEN_LINE(absValue, 1, int , Int_absValue), \
	GEN_LINE(absValue, 1, long , Long_absValue), \
	GEN_LINE(absValue, 1, long long , LongLong_absValue), \
	GEN_LINE(absValue, 1, Real , Real_absValue) \
)((m))

#define add(m, ...) _Generic((m), \
	GEN_LINE(add, 2, Real , Real_add) \
)((m), __VA_ARGS__)

#define convert(m) _Generic((m), \
	GEN_LINE(convert, 1, Real , Real_convert) \
)((m))

#define divy(m, ...) _Generic((m), \
	GEN_LINE(divy, 2, Real , Real_divy) \
)((m), __VA_ARGS__)

#define e(m) _Generic((m), \
	GEN_LINE(e, 1, F32 , F32_e), \
	GEN_LINE(e, 1, F64 , F64_e), \
	GEN_LINE(e, 1, F80 , F80_e), \
	GEN_LINE(e, 1, Real , Real_e) \
)((m))

#define init(m, ...) _Generic((m), \
	GEN_LINE(init, 2, Real* , Real_init) \
)((m), __VA_ARGS__)

#define isEqual(m, ...) _Generic((m), \
	GEN_LINE(isEqual, 2, Real , Real_isEqual) \
)((m), __VA_ARGS__)

#define isLessEqual(m, ...) _Generic((m), \
	GEN_LINE(isLessEqual, 2, F32 , F32_isLessEqual), \
	GEN_LINE(isLessEqual, 2, Real , Real_isLessEqual) \
)((m), __VA_ARGS__)

#define max(m, ...) _Generic((m), \
	GEN_LINE(max, 2, Real , Real_max) \
)((m), __VA_ARGS__)

#define min(m, ...) _Generic((m), \
	GEN_LINE(min, 2, Real , Real_min) \
)((m), __VA_ARGS__)

#define mul(m, ...) _Generic((m), \
	GEN_LINE(mul, 2, Real , Real_mul) \
)((m), __VA_ARGS__)

#define neg(m) _Generic((m), \
	GEN_LINE(neg, 1, F32 , F32_neg), \
	GEN_LINE(neg, 1, F64 , F64_neg), \
	GEN_LINE(neg, 1, F80 , F80_neg), \
	GEN_LINE(neg, 1, int , Int_neg), \
	GEN_LINE(neg, 1, long , Long_neg), \
	GEN_LINE(neg, 1, long long , LongLong_neg), \
	GEN_LINE(neg, 1, Real , Real_neg) \
)((m))

#define sub(m, ...) _Generic((m), \
	GEN_LINE(sub, 2, Real , Real_sub) \
)((m), __VA_ARGS__)
