/* Matt Zagame Copyright 2021
 * December 10 2021
 * Nested Structures demo
 * Name.c contains the function definitions for the Name structure */

 /** Functions to be modified start on line 21 **/

#include "Name.h"
#define _CRT_SECURE_NO_WARNINGS     // Necessary on Visual Studio
#include <stdio.h>
#include <string.h>

// Print contents of Name struct
void printName(Name* n) {
	printf("%s %c. %s\n", n->first, n->middle, n->last);
}

// Prompt for and read information into existing Name
void readName(Name* n) {
	char dot;
	printf("Enter name: ");
	scanf("%s %c%c %s", n->first, &(n->middle), &dot, n->last);
}

/*** NEW FUNCTIONS FOR PROGRAM 8 ***/

// Print contents of Name struct in form: last, first middle
void printNameLFM(Name* n) {
	printf("%s, %s %c.\n", n->last, n->first, n->middle);
}

// Returns 1 if structure pointed to by n1 is "less than" 
//    (earlier in alphabetical order) struct pointed to by n2
// Should compare names in order: last, first, middle
int lessThan(Name* n1, Name* n2) {
	if (strcmp(n1->last, n2->last) < 0) {
		// n1 last name is less than n2 last name
		return 1;
	}
	else if
		(strcmp(n1->last, n2->last) == 0 && strcmp(n1->first, n2->first) < 0) {
		// last names are equal and n1 first name is less than n2 first name
		return 1;
	}
	else if
		(strcmp(n1->last, n2->last) == 0 && strcmp(n1->first, n2->first) == 0 &&
			n1->middle < n2->middle) {
		// last and first names are equal and n1 middle initial is less than n2
		// middle initial
		return 1;
	}
	return 0;
}

// Returns 1 if structure pointed to by n1 is
//   equal to structure pointed to by n2 and
//   0 otherwise
int equal(Name* n1, Name* n2) {
	if (strcmp(n1->first, n2->first) == 0 && strcmp(n1->last, n2->last) == 0 && n1->middle == n2->middle) {
		// both structures contain equal values
		return 1;
	}
	return 0;
}

/*** END NEW FUNCTIONS FOR PROGRAM 8 ***/
