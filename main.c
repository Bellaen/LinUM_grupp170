#include <stdio.h>
#include <stdlib.h>
#include "resistance.h"

int main()
{
    int count;
    char conn;
    float resistance = 0;
    float myResistance;

    printf("Ange koppling [S/P]:\n");
    scanf("%c", &conn);

    printf("Ange antalet elektriska komponenter:\n");
    scanf("%d", &count);

    float *array = calloc(count, sizeof(float));

    for (int i = 0; i < count; i++)
    {
        printf("Komponent %d i ohm:\n", i + 1);
        scanf("%f", &myResistance);
        array[i] = myResistance;
    }

    resistance = calc_resistance(count, conn, array);

    printf("Resistance is %f ohm\n", resistance);

    free(array);
}