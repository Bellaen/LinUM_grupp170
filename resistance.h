#ifndef __RESISTANCE__
#define __RESISTANCE__

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

extern float calc_resistance(int count, char conn, float *array);

#endif