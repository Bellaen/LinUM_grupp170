#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../libresistance/libresistance.h"
#include "../libpower/libpower.h"
#include "../libcomponent/libcomponent.h"

int main()
{
    char conn_type = 0;         // connection type (serial or parallel)
    int count = 0;              // number of components
    int i = 0;                  
    float *output = NULL;       
    float validResistance = 0.0;
    float totalResistance = 0.0;
    float effect = 0.0;
    
    char *p = NULL;             // p = pointer to first non-numeric character
    char *myCount = calloc(19, sizeof(char))
    char *myResistance = calloc(19, sizeof(char));
    char *inputNotFloat = NULL;
    float volt, resistance, sum, current;


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
        {
            break;
        }
    }

    output = calloc(count, sizeof(float));
    myResistance = calloc(count, sizeof(float));
    if (output == NULL || myResistance == NULL)
        exit(EXIT_FAILURE);

    for (size_t i = 0; i < count; i++)
    {

        do
        {
            printf("Komponent %ld i ohm:\n", i + 1);
            fgets(myResistance, sizeof(myResistance), stdin);
            validResistance = strtof(myResistance, &inputNotFloat);

        } while (validResistance == 0 && myResistance == inputNotFloat);

        output[i] = validResistance;
    }

    totalResistance = calc_resistance(count, conn_type, output);

    printf("Ersättningsresistans: %f ohm\n", totalResistance);

    printf("Ange volt: ");

    scanf("%f", &volt);

    printf("Ange resistans: ");

    scanf("%f", &resistance);

    sum = calc_power_r(volt, resistance);

    printf("Power är: %.2f\n", sum);

    // Calculate E12 replacement components
    count = e_resistance(totalResistance, output);
    if (count > 0 && output != NULL) {
        for(size_t i = 0; i < count; i++) {
            printf("%G\n", output[i]);
        }
    } else {
        puts("");
    }

    free(output);
    free(myCount);
    free(myResistance);

    return 0;
}