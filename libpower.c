#include <stdio.h>
#include "libpower.h"


float calc_power_r(float volt, float resistance)
{
	float power = 0;
	if (resistance > 0)
	{
	result = (volt * volt / resistance);
	}

	return power;

}



float calc_power_i(float volt, float current)
{
	float power;
	power=(volt * current);

	return power;
}
