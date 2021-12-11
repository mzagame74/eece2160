/* Matt Zagame Copyright 2021
 * October 29, 2021
 * A number guessing game that uses loops to verify valid user input and allow
 * for multiple runs of the game.
*/
#define _CRT_SECURE_NO_WARNINGS     // Necessary on Visual Studio, not zyBooks
#include <stdio.h>

#include <stdlib.h>                 // Necessary for rand(), srand() functions

int main() {
	int seed;		// RNG seed

	/*** DECLARE OTHER VARIABLES HERE ***/
	int min, max, numGuesses, numRounds;
	int guess, answer;
	int wins = 0, losses = 0;
	int i, j;		// game loop indexes
	int nvals;		// scanf return value
	char junk;		// used to clear incorrectly formatted inputs

	// Input loops
	// Read RNG seed until error-free
	do {
		printf("Enter seed for random number generator: ");
		nvals = scanf("%d", &seed);
		if (nvals != 1) {
			printf("ERROR: Incorrectly formatted input\n");
			// clear input
			do {
				scanf("%c", &junk);
			} while (junk != '\n');
		}
		else if (seed < 0) {
			printf("ERROR: Seed value should be > 0\n");
		}
	} while (nvals != 1 || seed < 0);
	printf("Seed: %d\n\n", seed);

	// Read range endpoints until error-free
	do {
		printf("Enter range endpoints: ");
		nvals = scanf("%d %d", &min, &max);
		if (nvals != 2) {
			printf("ERROR: Incorrectly formatted input\n");
			// clear input
			do {
				scanf("%c", &junk);
			} while (junk != '\n');
		}
		else {
			if (min + 4 > max) {
				printf("ERROR: Max value should be at least 4 more than min value\n");
			}
			if (max < 0) {
				printf("ERROR: Max value should be positive\n");
			}
			if (min < 0) {
				printf("ERROR: Min value should be positive\n");
			}
		}
	} while (nvals != 2 || min < 0 || max < 0 || min + 4 > max);
	printf("Range endpoints: %d %d\n\n", min, max);

	// Read number of guesses allowed until error-free
	do {
		printf("Enter number of guesses per round: ");
		nvals = scanf("%d", &numGuesses);
		if (nvals != 1) {
			printf("ERROR: Incorrectly formatted input\n");
			// clear input
			do {
				scanf("%c", &junk);
			} while (junk != '\n');
		}
		else if (numGuesses < 2) {
			printf("ERROR: Must allow at least 2 guesses\n");
		}
	} while (nvals != 1 || numGuesses < 2);
	printf("Number of guesses: %d\n\n", numGuesses);

	// Read number of rounds until error-free
	do {
		printf("Enter number of rounds for game: ");
		nvals = scanf("%d", &numRounds);
		if (nvals != 1) {
			printf("ERROR: Incorrectly formatted input\n");
			// clear input
			do {
				scanf("%c", &junk);
			} while (junk != '\n');
		}
		else if (numRounds < 1) {
			printf("ERROR: Must allow at least 1 round\n");
		}
	} while (nvals != 1 || numRounds < 1);
	printf("Number of rounds: %d\n\n", numRounds);


	srand(seed);		// Seed random number generator--DO NOT CHANGE THIS LINE

	// Loop to control number of rounds--uncomment and fix
	for (i = 1; i < numRounds + 1; ++i) {

		// In each round:

		// Print round number
		printf("ROUND %d\n", i);

		// Choose new random value within range
		answer = (rand() % (max - min + 1)) + min;

		// Loop until maximum number of guesses is reached or user correctly guesses number
		j = 1;
		do {
			// Inside loop described above:
			// Prompt user to enter a guess until error-free (no formatting errors)
			do {
				printf("Enter guess #%d: ", j);
				nvals = scanf("%d", &guess);
				if (nvals != 1) {
					printf("ERROR: Incorrectly formatted input\n");
					// clear input
					do {
						scanf("%c", &junk);
					} while (junk != '\n');
				}
			} while (nvals != 1);

			// If guess matches, user wins!
			// Otherwise, tell them if it's too high or low and go on to next guess
			// If user reaches max number of guesses without winning, tell them they lost
			if (guess == answer) {
				printf("Correct guess!\n");
				++wins;
			}
			else if (guess < answer) {
				printf("%d is too low!\n", guess);
				if (j == numGuesses) {
					printf("No more guesses--the correct answer was %d\n", answer);
					++losses;
				}
			}
			else {
				printf("%d is too high!\n", guess);
				if (j == numGuesses) {
					printf("No more guesses--the correct answer was %d\n", answer);
					++losses;
				}
			}
			++j;
		} while (j <= numGuesses && guess != answer);	// end of round

		printf("Current wins: %d\n", wins);
		printf("Current losses: %d\n\n", losses);
	}	// end of game

	// Print final statistics
	printf("FINAL STATS\n");
	printf("Wins: %d\n", wins);
	printf("Losses: %d\n", losses);
	printf("Winning percentage: %0.2lf%%\n", wins / (double)numRounds * 100);

	return 0;
}
