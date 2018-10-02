#ifndef __CALC_POWER_H
#define __CALC_POWER_H


/** Vi beräknar här effektutvecklingen över en resistans

 *  med formeln P = U * U / R enligt uppgiftens instruktioner.

 *  Parametern volt: Spänningen över resistorn

 *  Parametern resistance: Resistorns resistans

 *  return i scriptet ska returnera den beräknade effektutvecklingen

 */


float calc_power_r(float volt, float resistance);


/** Vi beräknar här effektutvecklingen över en resistans

 *  med formeln P = U * I enligt uppgiftens instruktioner.

 *  Parametern volt: Spänningen över resistorn.

 *  Parametern current: Strömmen genom resistorn.

 *  return i scriptet ska returnera den beräknade effektutvecklingen.

 */


float calc_power_i(float volt, float current);


#endif
