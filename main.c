#include <stdio.h>
#include <stdlib.h>
#include "resistance.h"

int main()
{
    printf("Ange koppling [S|P]:\n");
    scanf("%c", &conn);

    printf("Antal komponenter:\n");
    scanf("%d", &count);

    float *array = calloc(count, sizeof(float));

    for (i = 0; i < count; i++)
    {
        printf("Komponent %d i ohm:\n", i + 1);
        scanf("%f", &myResistance);
        array[i] = myResistance;
    }

    totalResistance = calc_resistance(count, conn, array);

    printf("Ersättningsresistans: %f ohm\n", totalResistance);

    free(array);
}