#pragma once

#include "i4/i4.h"

#ifdef __cplusplus
#define MEM(m) m
#else
#define MEM(m) CONCAT(Mem_, m)
#endif

#define ssizeof(m) CAST(IntPtr, sizeof(m))

void* MEM(ctor)(void* a_this, IntPtr a_size);

void  MEM(dtor)(void* a_this);