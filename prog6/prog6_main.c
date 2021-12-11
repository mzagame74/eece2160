/* Matt Zagame Copyright 2021
 * December 5, 2021
 * Arrays and strings demo.
 * prog6_main.c contains the main program loop.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include "prog6_fns.h"

int main(void) {
	int numVals;		// used for scanf
	int arraySize = 0;	// current array size
	int val, found;
	int tempArray[MAX_ARRAY_SIZE];
	int min, max;
	float avg, median;
	char command[BUFFER_SIZE];

	// main program loop
	do {
		printf("Enter command (type help for command list): ");
		scanf("%s", command);

		// trim newline character
		command[strcspn(command, "\n")] = 0;

		// help
		if (strcmp(command, "help") == 0) {
			printf("Commands:\n");
			printf("help:\tprint this command list\n");
			printf("add:\tadd a value at the end of the array\n");
			printf("remove:\tremove a value from the array\n");
			printf("print:\tprint the array contents\n");
			printf("stats:\tgenerate array stats (min, max, avg, median)\n");
			printf("sort:\tsort the array contents\n");
			printf("exit:\tend the program\n\n");
		}

		// add
		else if (strcmp(command, "add") == 0) {
			if (arraySize == MAX_ARRAY_SIZE) {
				printf("Array is full!\n\n");
			}
			else {
				do {
					// prompt user for value to add
					printf("Enter value to add: ");
					if ((numVals = scanf("%d", &val)) != 1) {
						printf("Formatting error!\n");
					}
					clearLine();
				} while (numVals != 1);
				myArray[arraySize++] = val;		// add value to array
				// print new array state
				printf("New array state:\n");
				printArray(myArray, arraySize);
				printf("\n");
			}
		}

		// remove
		else if (strcmp(command, "remove") == 0) {
			if (arraySize == 0) {
				printf("Array is empty!\n\n");
			}
			else {
				// prompt user for value to remove
				do {
					printf("Enter value to remove: ");
					if ((numVals = scanf("%d", &val)) != 1) {
						printf("Formatting error!\n");
					}
					clearLine();
				} while (numVals != 1);
				// search array for value to remove
				found = 0;
				for (int i = 0; i < arraySize; ++i) {
					if (myArray[i] == val) {
						// remove value from array
						for (int j = i; j < arraySize - 1; ++j) {
							myArray[j] = myArray[j + 1];
						}
						arraySize--;
						found = 1;
						break;
					}
				}
				if (found) {
					// print new array state
					printf("New array state:\n");
					printArray(myArray, arraySize);
					printf("\n");
				}
				else {
					printf("%d not found in array!\n\n", val);
				}
			}
		}

		// print
		else if (strcmp(command, "print") == 0) {
			printArray(myArray, arraySize);
			printf("\n");
		}

		// stats
		else if (strcmp(command, "stats") == 0) {
			if (arraySize == 0) {
				printf("Array is empty!\n\n");
			}
			else {
				// copy array into sorted temp array
				avg = 0;
				for (int i = 0; i < arraySize; ++i) {
					tempArray[i] = myArray[i];
					avg += myArray[i];
				}
				sortArray(tempArray, arraySize);

				// get min, max, average, and median
				min = tempArray[0];
				max = tempArray[arraySize - 1];
				avg /= arraySize;

				printf("Min = %d\n", min);
				printf("Max = %d\n", max);
				printf("Average = %0.2f\n", avg);

				if (arraySize % 2 == 0) {
					median = (tempArray[arraySize / 2] + tempArray[(arraySize / 2) - 1]) / 2.0;
					printf("Median = %0.1f\n\n", median);
				}
				else {
					median = tempArray[arraySize / 2];
					printf("Median = %d\n\n", (int)median);
				}
			}
		}

		// sort
		else if (strcmp(command, "sort") == 0) {
			sortArray(myArray, arraySize);
			if (arraySize != 0) {
				printf("New array state:\n");
				printArray(myArray, arraySize);
			}
			printf("\n");
		}

		// exit
		else if (strcmp(command, "exit") == 0) {
			printf("Bye!\n");
		}

		// default case
		else {
			printf("Error: invalid command %s\n\n", command);
		}

	} while (strcmp(command, "exit") != 0);

	return 0;
}
