#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "resistance.h"
#include "libpower.h"

int main()
{
    char conn_type = 0;
    unsigned int count = 0;
    float* output = NULL;

    float myResistance;
    float resistanceS;
    float resistanceP;
    float totalResistanceS = 0;
    float totalResistanceP = 0;
    float effect,volt,power;

    printf("Ange spänningskälla i V: ");

    scanf("%f", &volt);

    do {
        printf("Ange koppling [S|P]:\n");
        scanf("%1c", &conn_type);

        conn_type = conn_type.toupper();

    } while (conn_type != 'S' || conn_type != 'P');

    do {
        printf("Antal komponenter:\n");
        scanf("%d", &count);

    } while (count <= 0);

    output = calloc(count, sizeof(float));
    if (output) == NULL
        exit(EXIT_FAILURE);

    for (size_t i = 0; i < count; i++)
    {
        printf("Komponent %d i ohm:\n", i + 1);
        scanf("%f", &myResistance);
        array[i] = myResistance;
    }
    
    totalResistance = calc_resistance(count, conn_type, array);
    // End of resistance


    // Output
    printf("Ersï¿½ttningsresistans: %f ohm\n", totalResistance);
    // End of output


    // Call the power function with value from resistance.
    float calc_power_r(float volt, float resistance)
{
	power=(volt*volt)/resistance;
	return power;
}

    effect = calc_power_r(volt, totalResistance);

    printf("Effekt%f .2f Watt\n", effect;
   // End of power function

    free(output);

    return 0;
}
