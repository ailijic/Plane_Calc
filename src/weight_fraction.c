#include "i4/real.h"
#include "time.h"
#include "sfc.h"
#include "lift_drag_ratio.h"
#include "weight_fraction.h"
#include "generic.h"
#include "i4/math.h"

WeightFraction WeightFraction_loiter(Time a_time, Sfc a_sfc, LiftDragRatio a_ld)
{
	Real time = a_time.t;
	Real sfc = a_sfc.t;
	Real ld = a_ld.t;

	return (WeightFraction){.t = 
		e(
			div(
				mul(neg(time), sfc),
				ld)
		)
	};
}