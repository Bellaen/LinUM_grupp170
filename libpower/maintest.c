#include "libpower.h"
#include <stdio.h>

float volt,resistance,current;


int main(void)

{

	float sum,effect;
	printf("Ange volt: ");

	scanf("%f", &volt);

	printf("Ange resistans: ");

	scanf("%f", &resistance);

	printf("Ange Ström i A: ");

	scanf("%f", &current);


	effect=calc_power_i(volt, current);

	printf("Effekt %.2f\n",effect);

	sum=calc_power_r(volt, resistance);

	printf("Power %.2f\n",sum);

	return 0;

}
