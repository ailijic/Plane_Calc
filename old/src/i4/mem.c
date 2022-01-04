#include "i4/mem.h"
#include "i4/define.h"
#include <assert.h>
#include <stdlib.h>

void* Mem_ctor(void* a_this, IntPtr a_size){
	UNUSED(a_this);
	assert(a_size >= 0);
	void* vp = malloc((size_t)a_size);
	assert(vp != NULL);
	return vp;
}

void Mem_dtor(void* a_this) {
	assert(a_this != NULL);
	free(a_this);
}