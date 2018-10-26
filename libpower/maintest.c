#include "libpower.h"
#include <stdio.h>

float volt,resistance,current;


int main(void)

{

	float effect_r,effect_i;
	printf("Ange volt: ");

	scanf("%f", &volt);

	printf("Ange resistans: ");

	scanf("%f", &resistance);

	printf("Ange Ström i A: ");

	scanf("%f", &current);


	effect_i=calc_power_i(volt, current);

	printf("Effekt %.2f\n",effect_i);

	effect_r=calc_power_r(volt, resistance);

	printf("Power %.2f\n",effect_r);

	return 0;

}
