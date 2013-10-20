/*
 * moving_average.c
 *
 *  Created on: Oct 16, 2013
 *      Author: C15Michael.Bentley
 */

// Finds the average of an array.
int getAverage(int array[], unsigned int arrayLength) {

	int sum = 0;
	int i;
	for (i = 0; i < arrayLength; i++) {
		sum += array[i];
	}
	return sum / arrayLength;
}

// Inserts a new value into the last position in an array and shifts all over values down by one, discarding the value at 0.
void addSample(int sample, int array[], unsigned int arrayLength) {
	int i;
	for (i = 0; i < arrayLength; i++) {
		array[i] = array[i + 1];
	}
	array[arrayLength - 1] = sample;
}

// Calculates the maximum value in an array.
int max(int array[], unsigned int arrayLength) {
	int i;
	int max = array[0];
	for(i = 1; i < arrayLength; i++) {
		if ( max < array[i] ) {
			max = array[i];
		}
	}
	return max;
}

// Calculates the minimum value in an array.
int min(int array[], unsigned int arrayLength) {
	int i;
	int min = array[0];
	for(i = 1; i < arrayLength; i++) {
		if ( min > array[i] ) {
			min = array[i];
		}
	}
	return min;
}

// Calcuates the range of values in an array.
unsigned int range(int array[], unsigned int arrayLength) {
	unsigned int range = max(array, arrayLength) - min(array, arrayLength);
	return range;
}

