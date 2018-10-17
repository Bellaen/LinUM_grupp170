#include "libcomponent.h"


static int move_to_int(float);

static const float E12[] = {1.0, 1.2, 1.5, 1.8, 2.2, 2.7, 3.3, 3.9, 4.7, 5.6, 6.8, 8.2};

/*
* origo_resistance: Ersättningsresistans
* res_array: vektor med lämpliga E12-värden
* return: antalet element i res_array
*/
int e_resistance(float orig_resistance, float *res_array)
{
    if (res_array == NULL) return -1;
    
    int index = 0;
    float input = orig_resistance;

    float exponent = 0;
    const float base = 10;
    float multiple = pow(base, exponent);

    float recent_match = 0;
    float current_match = 0;
    bool can_subtract = false;

    bool float_state = false;
    int iterations = 0;
    int moved = 0;


    while (input >= 0) {

        while (!can_subtract) {

            multiple = pow(base, exponent);

            if (input >= 1) {

                for(size_t i = 0; i < E12_LENGTH; i++) {
                    current_match = E12[i] * multiple;

                    // round to nearest value if no fraction part, otherwise move to fraction handler
                    if ((input - (int) input) == 0) {
                        if (current_match == input) {
                            recent_match = current_match;
                            can_subtract = true;
                            input = 0;

                            break;
                        }
                    }

                    // moved too far; use previous eligible entry
                    if ((input - current_match) < 0) {
                        can_subtract = true;
                        break;
                    }

                    // set as largest eligible entry
                    recent_match = current_match;
                }

                exponent++;
            } else {
                // fraction handler
                float_state = true;

                // move a single decimal from fraction part to integer part
                iterations = move_to_int(input);
                moved = moved + iterations;
                input = input * roundf(pow(base, iterations));

                // adjust for inaccuracy in floating-point representation (e.g., 0.99085 -> 1)
                if (input < 1)
                    input = roundf(input);
            }

            multiple = pow(base, exponent);
        }
        
        input = input - recent_match;

        if (float_state == true) {
            res_array[index] = recent_match / pow(base, ((moved + 1) - iterations));
            float_state = false;

        } else {
            res_array[index] = recent_match;
        }
        index++;
        if (index == MAX_RESULT) return index - 1;

        exponent = 0;
        recent_match = 0;
        current_match = 0;
        can_subtract = false;
    }

    return index;
}

static int move_to_int(float fp)
{
    int i = 0;

    while (roundf(fp) < 1) {
        i++;
        fp = fp * pow(10, i);
    }

    return i;
}
