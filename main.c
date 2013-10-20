#include <msp430.h> 
#include "moving_average.h"

#define N_AVG_SAMPLES 2
#define ARRAY_LENGTH 10

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	
    int output[20] = 0;
    int sampleArray[N_AVG_SAMPLES];
    int input[] = {45, 42, 41, 40, 43, 45, 46, 47, 49, 45};
    int i;

    // Initializes the sample array with zeros.
    for (i = 0; i < N_AVG_SAMPLES; i++) {
    	sampleArray[i] = 0;
    }

    // Fence post initializes the output with the first average of all zero values.
    output[0] = getAverage(sampleArray, N_AVG_SAMPLES);

    // Inserts the values in the input array to the sample array one at a time, finds the average, and outputs it to the next place in the output array.
    for(i = 0; i < ARRAY_LENGTH; i++) {
    	addSample(input[i], sampleArray, N_AVG_SAMPLES);
    	output[i + 1] = getAverage(sampleArray, N_AVG_SAMPLES);
    }

    output[++i] = max(input, ARRAY_LENGTH); // Outputs the max of the input array right after the moving average.

    output[++i] = min(input, ARRAY_LENGTH); // Outputs the min of the array next.

    output[++i] = range(input, ARRAY_LENGTH); // Finally, outputs the range.


    while (1) {
    }
}
