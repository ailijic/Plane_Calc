#pragma once

#include "i4/type.h"

#define ssizeof(m) ((IntPtr)sizeof(m))

void* Mem_ctor(void* a_this, IntPtr a_size);

void  Mem_dtor(void* a_this);