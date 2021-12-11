/* Matt Zagame Copyright 2021
 * December 10 2021
 * Nested Structures demo
 * Roster.c contains the function definitions for the Roster structure */

#include "Roster.h"
#define _CRT_SECURE_NO_WARNINGS     // Necessary on Visual Studio
#include <stdio.h>

 // Add student to roster; returns 1 if successful or 0 if roster full
int addStudent(Roster* r, Name* n) {
	if (r->ns == r->cap) {
		// roster is full, cannot add student
		return 0;
	}
	else if (r->ns == 0) {
		// roster is empty, add student and increment ns
		r->students[r->ns++] = *n;
	}
	else {
		// add student in alphabetical order
		for (int i = 0; i < r->ns; ++i) {
			if (lessThan(n, &(r->students[i]))) {
				// shift each student on the list to the right by 1 position
				for (int j = r->ns; j > i; --j) {
					r->students[j] = r->students[j - 1];
				}
				r->students[i] = *n;
				break;
			}
			else if (i == r->ns - 1) {
				// name does not come before any existing student names
				r->students[i + 1] = *n;
			}
		}
		r->ns++;
	}
	return 1;
}

// Print contents of roster
void printRoster(Roster* r) {
	printf("%s\n", r->course);
	printf("Instructor: ");
	printNameLFM(&(r->instructor));
	printf("Course meetings: %s %s in %s\n", r->days, r->time, r->room);
	printf("Enrollment cap: %d\n", r->cap);
	printf("Number enrolled: %d\n", r->ns);
	if (r->ns > 0) {
		printf("Class roster:\n");
		for (int i = 0; i < r->ns; ++i) {
			printNameLFM(&(r->students[i]));
		}
	}
}

// Find student in roster; returns 1 if successful or 0 if student not found
int findStudent(Roster* r, Name* n) {
	for (int i = 0; i < r->ns; ++i) {
		// check if this student's name comes before the student in the list
		if (lessThan(n, &(r->students[i]))) {
			return 0;
		}
		else if (equal(&(r->students[i]), n)) {
			return 1;
		}
	}
	return 0;
}
