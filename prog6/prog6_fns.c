/* Matt Zagame Copyright 2021
 * December 5, 2021
 * Arrays and strings demo.
 * prog6_fns.c contains the function definitions for commonly used functions.
*/
#define _CRT_SECURE_NO_WARNINGS
#include "prog6_fns.h"

/* prints the contents of an array */
void printArray(int array[], size_t array_size) {
	if (array_size == 0) {
		printf("Array is empty!\n");
	}
	else {
		for (int i = 0; i < array_size; ++i) {
			printf("%d ", array[i]);
		}
		printf("\n");
	}
}

/* sorts an array in ascending order by swapping minimum values toward the end
of the array toward the beginning */
void sortArray(int array[], size_t array_size) {
	int min, minIndex, temp;

	if (array_size == 0) {
		printf("Array is empty!\n");
	}
	else {
		for (int i = 0; i < array_size - 1; ++i) {
			min = INT_MAX;
			for (int j = i; j < array_size; ++j) {
				if (array[j] < min) {
					min = array[j];
					minIndex = j;
				}
			}
			temp = array[i];
			array[i] = min;
			array[minIndex] = temp;
		}
	}
}

/* clears the input buffer of junk characters */
void clearLine() {
	char junk;
	do {
		scanf("%c", &junk);
	} while (junk != '\n');
}
