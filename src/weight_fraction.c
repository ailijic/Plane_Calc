#include "i4/real.h"
#include "time.h"
#include "sfc.h"
#include "lift_drag_ratio.h"
#include "weight_fraction.h"

#include "i4/math.h"
#include "generic.h"

WeightFraction WeightFraction_loiter(Time a_time, Sfc a_sfc, LiftDragRatio a_ld)
{
	Real time = a_time.t;
	Real sfc = a_sfc.t;
	Real ld = a_ld.t;

	return (WeightFraction){.t = 
		Real_e(
			Real_div(
				Real_mul(Real_neg(time), sfc),
				ld)
		)
	};
}