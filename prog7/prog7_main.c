/*****************************************************************
* EECE.2160: ECE Application Programming
* Instructor: M.Geiger
* Tests understanding of nested structures
*
* prog7_main.c : main program used to test P7 functions
*
* v1: main test program for assignment
* v2: modified to account for individual function test cases
*     (output functions only)
******************************************************************/

/*****************************************
 ******** DO NOT MODIFY THIS FILE ********
 *****************************************/

#define _CRT_SECURE_NO_WARNINGS     // Necessary on Visual Studio
#include <stdio.h>
#include <string.h>
#include "Roster.h"
#include "Name.h"

 // Short function to prompt for and read section number,
 //    since we have to do that repeatedly
 // Returns 0 for section 201, 1 for section 202
int getSection() {
	int s;

	do {
		printf("Enter section #: ");
		scanf("%d", &s);

		if (s < 201 || s > 202)
			printf("Invalid section # %d\n", s);

	} while (s < 201 || s > 202);

	return s - 201;
}

int main() {
	Roster eece2160[2] =					// Array of structures representing last semester's sections,
									 //    since that semester had a little more variety!
	{
		{
			"EECE.2160",					// course
			{ "Rachel" , 'E', "Wakim" },	// instructor
			"MWF",							// days
			"8:00-8:50 AM",					// time
			"Ball 326",						// room
			60,								// cap
			0								// ns (number of students)
		},

		{
			"EECE.2160",					// course
			{ "Michael" , 'J', "Geiger" },	// instructor
			"MWF",							// days
			"12:00-12:50 PM",				// time
			"Ball 314",						// room
			60,								// cap
			0								// ns (number of students)
		}
	};

	char cmd[20];			// Input command
	int section;			// Section of course
	Name n;					// Temporary name structure
	int test;				// Test case number

	printf("Enter test case #: ");
	scanf("%d", &test);

	switch (test) {
	case 1:				// Test printNameLFM() function
		strcpy(n.first, "James");
		n.middle = 'E';
		strcpy(n.last, "Jones");
		printNameLFM(&n);

		break;

	case 2:				// Test printRoster() function

		eece2160[1].ns = 3;
		strcpy(eece2160[1].students[0].first, "Dewey");
		eece2160[1].students[0].middle = 'U';
		strcpy(eece2160[1].students[0].last, "Duck");
		strcpy(eece2160[1].students[1].first, "Huey");
		eece2160[1].students[1].middle = 'A';
		strcpy(eece2160[1].students[1].last, "Duck");
		strcpy(eece2160[1].students[2].first, "Louie");
		eece2160[1].students[2].middle = 'E';
		strcpy(eece2160[1].students[2].last, "Duck");

		printf("SECTION 201:\n");
		printRoster(&eece2160[0]);
		printf("\nSECTION 202:\n");
		printRoster(&eece2160[1]);

		break;

	case 3:				// Test overall program
		do {
			printf("\nEnter command: ");
			scanf("%s", cmd);

			if (strcmp(cmd, "print") == 0) {		// Print roster
				printRoster(&eece2160[getSection()]);
			}

			else if (strcmp(cmd, "add") == 0) {		// Add student
				section = getSection();
				readName(&n);

				if (addStudent(&eece2160[section], &n)) {
					printf("Added ");
					printNameLFM(&n);
					printf(" to Section %d\n", section + 201);
				}
				else
					printf("Section %d full; could not add\n", section + 201);
			}

			else if (strcmp(cmd, "find") == 0) {	// Find student in section
				section = getSection();
				readName(&n);

				if (findStudent(&eece2160[section], &n))
					printf("Student found in Section %d\n", section + 201);
				else
					printf("Student not found in Section %d\n", section + 201);
			}

			else if (strcmp(cmd, "exit") != 0)
				printf("Invalid command %s\n", cmd);

		} while (strcmp(cmd, "exit") != 0);

		break;

	default:
		printf("Invalid test case # %d\n", test);
	}

	return 0;
}
