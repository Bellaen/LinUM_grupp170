#include "resistance.h"
#include <stdio.h>

float calc_resistance(int count, char conn, float *array)
{
    for (i = 0; i < count; i++)
    {
        resistanceS = resistanceS + array[i];
        resistanceP = resistanceP + 1 / (array[i]);

        totalResistanceS = resistanceS;
        totalResistanceP = 1 / resistanceP;
    }

    if (conn == 'S')
    {
        return totalResistanceS;
    }
    else if (conn == 'P' && i != 0)
    {
        return totalResistanceP;
    }
    else
    {
        return -1;
    }
}