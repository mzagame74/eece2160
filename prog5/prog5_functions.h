/* Matt Zagame Copyright 2021
 * November 10, 2021
 * A bank simulator.
 * prog5_functions.h contains the function prototypes for the program.
*/
#ifndef PROG5_FUNCTIONS_H
#define PROG5_FUNCTIONS_H
#include <stdio.h>
#include <math.h>

double GetPiggyBankMoney();

double GetNewAmount(double principal, double rate, int years);

void ClearLine();

#endif
