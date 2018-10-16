#include "libpower.h"
#include <stdio.h>

float calc_power_r(float volt, float resistance)

{

        float power;

        power=(volt*volt)/resistance;

        return power;

}



float calc_power_i(float volt, float current)

{

        float power;

        power=volt*current;

        return power;

}

int main(void)

{

	float volt,resistance,sum;

	printf("Ange volt: ");

	scanf("%f", &volt);

	printf("Ange resistans: ");

	scanf("%f", &resistance);

	sum=calc_power_r(volt, resistance);

	printf("Power är: %.2f\n", sum);

	return 0;

}
