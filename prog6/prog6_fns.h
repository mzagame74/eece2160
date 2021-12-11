/* Matt Zagame Copyright 2021
 * December 5, 2021
 * Arrays and strings demo.
 * prog6_fns.h contains declarations for the main program array and commonly
 * used functions.
*/
#ifndef PROG6_FNS_H
#define PROG6_FNS_H
#define MAX_ARRAY_SIZE 10
#define BUFFER_SIZE 16

#include <stdio.h>
#include <limits.h>

int myArray[MAX_ARRAY_SIZE];	// main array

void printArray(int array[], size_t array_size);

void sortArray(int array[], size_t array_size);

void clearLine();

#endif
