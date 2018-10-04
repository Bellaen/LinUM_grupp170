#ifndef __LIB_POWER_H
#define __LIB_POWER_H


/** Vi ber�knar h�r effektutvecklingen �ver en resistans

 *  med formeln P = U * U / R enligt uppgiftens instruktioner.

 *  Parametern volt: Sp�nningen �ver resistorn

 *  Parametern resistance: Resistorns resistans

 *  return i scriptet ska returnera den ber�knade effektutvecklingen

 */


float calc_power_r(float volt, float resistance);


/** Vi ber�knar h�r effektutvecklingen �ver en resistans

 *  med formeln P = U * I enligt uppgiftens instruktioner.

 *  Parametern volt: Sp�nningen �ver resistorn.

 *  Parametern current: Str�mmen genom resistorn.

 *  return i scriptet ska returnera den ber�knade effektutvecklingen.

 */


float calc_power_i(float volt, float current);


#endif
