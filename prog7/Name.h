/*****************************************************************
* EECE.2160: ECE Application Programming
* M.Geiger--Instructor solution to Program 8
* Tests understanding of nested structures
*
* Name.h : Name structure definition; related function prototypes
*
* v0: created for in-class exercise on 4/8/16
* v1: added prototypes for new functions
******************************************************************/

/*****************************************
 ******** DO NOT MODIFY THIS FILE ********
 *****************************************/

#ifndef Name_h
#define Name_h

typedef struct {
	char first[50];
	char middle;
	char last[50];
} Name;

// Print contents of Name struct
void printName(Name* n);

// Read information into existing Name
void readName(Name* n);

/*** NEW FUNCTIONS FOR PROGRAM 8 ***/

// Print contents of Name struct in form: last, first middle
void printNameLFM(Name* n);

// Returns 1 if structure pointed to by n1 is "less than" 
//   (earlier in alphabetical order) struct pointed to by n2
//   and 0 otherwise
// Should compare names in order: last, first, middle
int lessThan(Name* n1, Name* n2);

// Returns 1 if structure pointed to by n1 is
//   equal to structure pointed to by n2 and
//   0 otherwise
int equal(Name* n1, Name* n2);

/*** END NEW FUNCTIONS FOR PROGRAM 8 ***/

#endif /* Name_h */
