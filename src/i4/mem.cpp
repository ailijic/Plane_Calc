#include "i4/mem.h"
#include <assert.h>
#include <stdlib.h>

void* ctor(void* a_this, IntPtr a_size){
	UNUSED(a_this);
	assert(a_size >= 0);
	void* vp = malloc(CAST(size_t, a_size));
	assert(vp != NULL);
	return vp;
}

void dtor(void* a_this) {
	assert(a_this != NULL);
	free(a_this);
}