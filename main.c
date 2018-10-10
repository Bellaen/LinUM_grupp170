#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "resistance.h" // WARNING: resistance.h does not exist in current directory
//#include "libpower.h" // WARNING: libpower.h does not exist in current directory

int main()
{
    char conn_type = 0;
    int count = 0;
    float *output = NULL;
    float myResistance = 0.0;
    float totalResistance = 0.0;
    float effect = 0.0;
    // p = pointer to first non-numeric character
    char *p, myCount[100];

    do
    {
        puts("Ange koppling [S|P]:");
        scanf(" %c", &conn_type);
        conn_type = toupper(conn_type);

    } while (conn_type != 'S' && conn_type != 'P');

    while (fgets(myCount, sizeof(myCount), stdin))
    {
        count = strtol(myCount, &p, 10);
        if (p == myCount || *p != '\n')
        {
            printf("Antal komponenter: ");
        }
        else
            break;
    }

    output = calloc(count, sizeof(float));
    if (output == NULL)
        exit(EXIT_FAILURE);
    
    // TODO: if input is non-numeric (e.g. a letter), the user should be prompted to enter a valid input (e.g. a float).
    for (size_t i = 0; i < count; i++)
    {
        printf("Komponent %ld i ohm:\n", i + 1);
        scanf("%f", &myResistance);
        output[i] = myResistance;
    }

    totalResistance = calc_resistance(count, conn_type, output);
    // End of resistance

    // Output
    printf("Ersättningsresistans: %f ohm\n", totalResistance);
    // End of output

    // Call the power function with value from resistance.
    //effect = calc_power_r(volt, totalResistance);

    //printf("Effekten är: %f Watt\n", effect);
    // End of power function

    free(output);

    return 0;
}