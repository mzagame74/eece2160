#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFF_SIZE 32
#define INIT_DATA_SIZE 50

int main(void) {

	/* Type your code here. */
	int numVals, arraySize, commas;
	char title[BUFF_SIZE];
	char column1[BUFF_SIZE], column2[BUFF_SIZE];

	char input[BUFF_SIZE];
	char name[BUFF_SIZE];
	int num;
	char* stringData[INIT_DATA_SIZE];
	int numberData[INIT_DATA_SIZE];

	// get table string data
	printf("Enter a title for the data:");
	fgets(title, BUFF_SIZE, stdin);
	title[strlen(title) - 1] = '\0';
	printf("\nYou entered: %s\n\n", title);

	printf("Enter the column 1 header:");
	fgets(column1, BUFF_SIZE, stdin);
	column1[strlen(column1) - 1] = '\0';
	printf("\nYou entered: %s\n\n", column1);

	printf("Enter the column 2 header:");
	fgets(column2, BUFF_SIZE, stdin);
	column2[strlen(column2) - 1] = '\0';
	printf("\nYou entered: %s\n\n", column2);

	arraySize = 0;
	do {
		printf("Enter a data point (-1 to stop input):\n");
		fgets(input, BUFF_SIZE, stdin);
		input[strlen(input) - 1] = '\0';

		// check if user input -1
		if (strcmp(input, "-1") != 0) {
			// read in any character followed by a comma followed by an integer
			// and count commas
			numVals = sscanf(input, "%[^,], %d", name, &num);

			if (numVals != 2) {
				commas = 0;
				for (int i = 0; i < strlen(input) + 1; ++i) {
					if (input[i] == ',') {
						++commas;
					}
				}
				switch (commas) {
				case 0:
					printf("Error: No comma in string.\n\n");
					break;
				case 1:
					printf("Error: Comma not followed by an integer.\n\n");
					break;
				default:
					printf("Error: Too many commas in input.\n\n");
				}
			}
			else {
				stringData[arraySize] = (char*)malloc((strlen(name) + 1) * sizeof(char));
				strcpy(stringData[arraySize], name);
				numberData[arraySize] = num;

				printf("Data string: %s\n", stringData[arraySize]);
				printf("Data integer: %d\n\n", numberData[arraySize]);

				++arraySize;
			}
		}
	} while (strcmp(input, "-1") != 0 && arraySize < INIT_DATA_SIZE);
	// only allows 50 data entries

	// print data in table form
	printf("\n%33s\n", title);
	printf("%-20s", column1);
	printf("|");
	printf("%23s\n", column2);
	printf("--------------------------------------------\n");
	for (int i = 0; i < arraySize; ++i) {
		printf("%-20s|", stringData[i]);
		printf("%23d\n", numberData[i]);
	}
	printf("\n");

	// print data in histogram form
	for (int i = 0; i < arraySize; ++i) {
		printf("%20s ", stringData[i]);
		for (int j = 0; j < numberData[i]; ++j) {
			printf("*");
		}
		printf("\n");
	}

	// free dynamically allocated string memory
	for (int i = 0; i < arraySize; ++i) {
		free(stringData[i]);
	}

	return 0;
}
