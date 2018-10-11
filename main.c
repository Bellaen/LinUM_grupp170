#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "resistance.h" // WARNING: resistance.h does not exist in current directory
//#include "libpower.h" // WARNING: libpower.h does not exist in current directory

int main()
{
    char conn_type = 0;
    int count = 0;
    int i;
    float *output = NULL;
    float validResistance = 0.0;
    float totalResistance = 0.0;
    float effect = 0.0;
    // p = pointer to first non-numeric character
    char *p, myCount[100];
    char myResistance[100];
    char *inputNotFloat;

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
            printf("Antal komponenter:\n");
        }
        else
            break;
    }

    output = calloc(count, sizeof(float));
    if (output == NULL)
        exit(EXIT_FAILURE);

    for (size_t i = 0; i < count; i++)
    {
        do
        {
            printf("Komponent %ld i ohm:\n", i + 1);
            fgets(myResistance, sizeof(myResistance), stdin);
            validResistance = strtof(myResistance, &inputNotFloat);

        } while (validResistance == 0);

        output[i] = validResistance;
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