#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "libcomponent.h"

#define E12_SIZE 12

const int const E12[] = {10, 12, 15, 18, 22, 27, 33, 39, 47, 56, 68, 82};

int decimals(int resistance)
{
    if (resistance <= 0) return -1; 
    
    int p = 0;
    while ((resistance / 10) >  0) {
        p++;
        resistance /= 10;
    }

    return pow(10, p);
}

/*
* origo_resistance: Ersättningsresistans
* res_array: vektor med lämpliga E12-värden
* return: antalet element i res_array
*/
int e_resistance(float orig_resistance, float *res_array)
{
    int count = 0;
    bool match = false;
    int p = decimals(orig_resistance);
    if (p < 0) exit(EXIT_FAILURE);
    /*
    * Algoritm under utveckling
    */

    return count;
}



int main(void)
{
    float *array = malloc(sizeof(float) * 3);
    memset(array, 0, sizeof(float) * 3);
    e_resistance(1398, array);

    for(size_t i = 0; i < 3; i++) {
        printf("%f\n", array[i]);
    }

    free(array);

    return 0;
}