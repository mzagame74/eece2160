/* Matt Zagame Copyright 2021
 * November 10, 2021
 * A bank simulator.
 * prog5.c contains the main program loop.
*/
#define _CRT_SECURE_NO_WARNINGS
#include "prog5_functions.h"

int main() {
	char command;
	int numVals;				// used for scanf
	int waitYears = 0;
	int year = 0;				// current year
	double availableFunds = 0;	// total funds in dollars
	double interestRate = 0;
	double piggyBankMoney;

	// main program loop
	do {
		// initial prompt/scan
		printf("Year %d:\n", year);
		printf("There is $%0.2lf in your bank account with an annual rate of %0.3lf. What do you wish to do? (Wait, Invest, Quit): ", availableFunds, interestRate);

		do {
			scanf("%c", &command);
		} while (command == '\n');

		// evaluate the user's command
		switch (command) {
		case 'w':
		case 'W':
			// if w/W, wait the prescribed number of years (needs to be a positive number) while compounding interest
			do {
				printf("How many years do you want to wait? ");
				numVals = scanf("%d", &waitYears);
				if (numVals != 1) {
					ClearLine();
				}
				else if (waitYears < 1) {
					printf("Need a positive amount!\n");
				}
				else {
					printf("Waiting %d year(s)...\n", waitYears);
					availableFunds = GetNewAmount(availableFunds, interestRate, waitYears);
					year += waitYears;
				}
			} while (numVals != 1 || waitYears < 1);
			break;

		case 'i':
		case 'I':
			// if i/I, use the GetPiggyBankMoney function to get the correct amount from the user
			// Then prompt for the new yearly rate (must be positive)
			// Then let the new total earn interest for one year
			piggyBankMoney = GetPiggyBankMoney();
			availableFunds += piggyBankMoney;
			printf("You got $%0.2lf from your piggy bank and added it to your account! Your total is now $%0.2lf", piggyBankMoney, availableFunds);
			do {
				printf("What is the new yearly rate? ");
				numVals = scanf("%lf", &interestRate);
				if (numVals != 1) {
					ClearLine();
				}
				else if (interestRate <= 0) {
					printf("Need a positive amount!\n");
				}
				else {
					availableFunds = GetNewAmount(availableFunds, interestRate, 1);
					year++;
				}
			} while (numVals != 1 || interestRate <= 0);
			break;

		case 'q':
		case 'Q':
			// if q/Q, quit the program
			printf("Bye!\n");
			break;

		default:
			// Any other command, yell at the user
			printf("Invalid command %c!\n", command);
		}
	} while (command != 'q' && command != 'Q');

	return 0;
}
