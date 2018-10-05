#include <stdio.h>
#include <stdlib.h>
#include "resistance.h"

int main()
{
    // User form
    printf("Ange koppling [S|P]:\n");
    scanf("%c", &conn);

    printf("Antal komponenter:\n");
    scanf("%d", &count);
    // End of user form


    // Resistance
    float *array = calloc(count, sizeof(float));

    for (i = 0; i < count; i++)
    {
        printf("Komponent %d i ohm:\n", i + 1);
        scanf("%f", &myResistance);
        array[i] = myResistance;
    }
    
    totalResistance = calc_resistance(count, conn, array);
    // End of resistance


    // Output
    printf("Ersättningsresistans: %f ohm\n", totalResistance);
    // End of output


    free(array);
}