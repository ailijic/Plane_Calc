#pragma once

#include "i4/real.h"
#include "time.h"
#include "sfc.h"
#include "lift_drag_ratio.h"

typedef struct WeightFraction {
	Real t;
} WeightFraction;

WeightFraction WeightFraction_loiter(Time a_time, Sfc a_sfc, LiftDragRatio a_ld);

Real WeightFraction_asReal(WeightFraction a_this);