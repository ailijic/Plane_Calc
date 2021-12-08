#pragma once

#include "i4/real.h"
#include "i4/type.h"

typedef struct LiftDragRatio {
	Real t;
} LiftDragRatio;

static inline LiftDragRatio LiftDragRatio_stor(real a_value) {
	return (LiftDragRatio){.t = (Real){.t= a_value}};
}