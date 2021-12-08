#pragma once

#include "i4/real.h"

typedef struct Sfc {
	Real t; // (kg / s) / N
} Sfc;

Sfc lbsPerHourPerThrustLbs(Real r);
