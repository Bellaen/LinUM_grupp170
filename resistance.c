#include "resistance.h"
#include <stdio.h>
#include <ctype.h>

// Variables
int count;
char conn;
float myResistance;
float totalResistance;
float resistanceS;
float resistanceP;
float totalResistanceS = 0;
float totalResistanceP = 0;
int i;

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