/********************************************************************
* EECE.2160: ECE Application Programming
* M.Geiger--Instructor solution to Program 8
* Tests understanding of nested structures
*
* Roster.h : Roster structure definition; related function prototypes
*
* v1: Added all function prototypes and structure definition
*********************************************************************/

/*****************************************
 ******** DO NOT MODIFY THIS FILE ********
 *****************************************/

#ifndef Roster_h
#define Roster_h

#include "Name.h"

typedef struct {
	char course[50];	// Course name
	Name instructor;	// Instructor name
	char days[5];		// Days on which class meets (string)
	char time[15];		// Time at which class meets (string)
	char room[25];		// Room in which class meets (string)
	unsigned cap;		// Enrollment cap
	unsigned ns;		// Number of enrolled students
	Name students[100];	// List of student names
} Roster;

// Add student to roster; returns 1 if successful or 0 if roster full
int addStudent(Roster* r, Name* n);

// Print contents of roster
void printRoster(Roster* r);

// Find student in roster; returns 1 if successful or 0 if student not found
int findStudent(Roster* r, Name* n);

#endif
