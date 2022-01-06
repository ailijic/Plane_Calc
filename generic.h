#pragma once

#define ctor(m, ...)  \
	_Generic((m),       \
		void* : Mem_ctor \
	)(m, __VA_ARGS__)

#define dtor(m)  \
	_Generic((m),       \
		void* : Mem_dtor \
	)(m)

#define convert(m)  \
	_Generic((m),       \
		Real : Real_convert \
	)(m)

#define asReal(m)  \
	_Generic((m),       \
		WeightFraction : WeightFraction_asReal \
	)(m)
	
#define init(m, ...)  \
	_Generic((m),       \
		Real* : Real_init, \
		Time* : Time_init, \
		Sfc* : Sfc_init, \
		LiftDragRatio* : LiftDragRatio_init, \
		void* : Mem_init, \
	)(m, __VA_ARGS__)

#define add(m, ...) \
	_Generic((m),     \
		Real: Real_add \
	)(m, __VA_ARGS__)

#define sub(m, ...) \
	_Generic((m),     \
		Real: Real_sub \
	)(m, __VA_ARGS__)

	#define mul(m, ...) \
	_Generic((m),     \
		Real: Real_mul \
	)(m, __VA_ARGS__)

#define divide(m, ...) \
	_Generic((m),     \
		Real: Real_div \
	)(m, __VA_ARGS__)

#define max(m, ...) \
	_Generic((m),     \
		Real: Real_max \
	)(m, __VA_ARGS__)

#define min(m, ...) \
	_Generic((m),     \
		Real: Real_min  \
	)(m, __VA_ARGS__)

	#define isLessEqual(m, ...) \
	_Generic((m),            \
		F32:  F32_isLessEqual,  \
		Real: Real_isLessEqual \
	)(m, __VA_ARGS__)

#define e(m)        \
	_Generic((m),     \
		F32 : F32_e,    \
		F64 : F64_e,    \
		F80 : F80_e    \
	)(m)

#define absValue(m)              \
	_Generic((m),                  \
		Real:      Real_absValue,    \
		F64:       F64_absValue,     \
		F80:       F80_absValue,     \
		F32:			 F32_absValue,\
		int:       Int_absValue,     \
		long:      Long_absValue,    \
		long long: LongLong_absValue \
	)(m)

#define neg(m)              \
	_Generic((m),                  \
		Real:      Real_neg,    \
		F32:       F32_neg,     \
		F64:       F64_neg,     \
		F80:       F80_neg,     \
		int:       Int_neg,     \
		long:      Long_neg,    \
		long long: LongLong_neg \
	)(m)

#define loiter(m, ...) \
	_Generic((m),     \
		Time: WeightFraction_loiter \
	)(m, __VA_ARGS__)

#define hours(m)        \
	_Generic((m),     \
		F32 : Time_hours,    \
		F64 : Time_hours,    \
		F80 : Time_hours,    \
		int : Time_hours\
	)(m)

#define minutes(m)        \
	_Generic((m),     \
	  int : Time_minutes,\
		F32 : Time_minutes,    \
		F64 : Time_minutes,    \
		F80 : Time_minutes    \
	)(m)

#define seconds(m)        \
	_Generic((m),     \
	  int : Time_seconds,\
		F32 : Time_seconds,    \
		F64 : Time_seconds,    \
		F80 : Time_seconds    \
	)(m)