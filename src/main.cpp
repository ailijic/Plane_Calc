#include <stdio.h>
#include <stdlib.h>
#include "i4/real.h"
#include "time.h"
#include "sfc.h"
#include "lift_drag_ratio.h"
#include "weight_fraction.h"

int main() {
  Real           r;
  Time           time = hours(3);
	Sfc            sfc;
	LiftDragRatio ld;

	init(&sfc, 0.0001111);
  init(&ld, 16.0);

  F64 res = convert(WeightFraction.asReal(WeightFraction.loiter(&time, &sfc, &ld)));
  printf("Loiter: %f\n", res);

  return EXIT_SUCCESS;
}
