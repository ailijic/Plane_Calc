#pragma once

#include "i4/real.h"

typedef struct Sfc {
	Real t; // (kg / s) / N
} Sfc;

Sfc* Sfc_init(Sfc* a_this, Real a_value);

Sfc lbsPerHourPerThrustLbs(Real r);
