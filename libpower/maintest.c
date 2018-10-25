#include "libpower.h"
#include <stdio.h>

float volt,resistance;


int main(void)

{

	float sum;
	printf("Ange volt: ");

	scanf("%f", &volt);

	printf("Ange resistans: ");

	scanf("%f", &resistance);

	sum=calc_power_r(volt, resistance);

	printf("Power %.2f\n",sum);

	return 0;

}
