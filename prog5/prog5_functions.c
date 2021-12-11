/* Matt Zagame Copyright 2021
 * November 10, 2021
 * A bank simulator.
 * prog5_functions.c contains the function definitions for the program.
*/
#define _CRT_SECURE_NO_WARNINGS
#include "prog5_functions.h"

/* Prompt the user for the number of each type of coin from the piggy bank.
Perform input validation as necessary (must all be integers and >=0), then calculate and return the amount
in dollars */
double GetPiggyBankMoney() {
	int numVals;
	int quarters, dimes, nickels, pennies;
	double totalDollars;

	do {
		printf("Please enter the number of quarters, dimes, nickels, and pennies, separated by spaces: ");
		numVals = scanf("%d %d %d %d", &quarters, &dimes, &nickels, &pennies);
		if (numVals != 4) {
			ClearLine();
		}
		else if (quarters < 0 || dimes < 0 || nickels < 0 || pennies < 0) {
			printf("All values must be >= 0!\n");
		}
		else {
			totalDollars = (quarters * 0.25) + (dimes * 0.10) + (nickels * 0.05) + (pennies * 0.01);
		}
	} while (numVals != 4 || quarters < 0 || dimes < 0 || nickels < 0 || pennies < 0);

	return totalDollars;
}

/* Given the principal amount in the bank account and the yearly rate, calculate and return the new amount
after the given number of years has passed */
double GetNewAmount(double principal, double rate, int years) {
	return principal * pow((1 + rate), years);
}

/* Print a generic error message about bad format, then clear all characters from input until a newline is
found */
void ClearLine() {
	char junk;
	printf("Bad format!\n");
	do {
		scanf("%c", &junk);
	} while (junk != '\n');
}
