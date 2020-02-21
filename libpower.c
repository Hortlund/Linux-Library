#include "libpower.h"

float calc_power_r(float volt, float resistance) {
	return volt * volt / resistance;
}

float calc_power_i(float volt, float current) {
	return volt * current;
}
