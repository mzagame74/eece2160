/* Matt Zagame Copyright 2021
 * October 13, 2021
 * prog3.c performs an integer calculation on an input in the form a op b where
 * op is either +, -, *, /, or %.
*/
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>

int main(void) {
	int a, b;		// a and b are operands
	int n;			// scanf return value
	char op;		// operator

	// get user input
	printf("Please enter your integer arithmetic expression: ");
	n = scanf("%d %c %d", &a, &op, &b);

	// check input for operands and operator
	if (n < 3) {
		printf("Error: only %d value(s) entered correctly!\n", n);
	}
	else {
		switch (op) {
		case '+':
			printf("Answer: %d + %d = %d\n", a, b, a + b);
			break;
		case '-':
			printf("Answer: %d - %d = %d\n", a, b, a - b);
			break;
		case '*':
			printf("Answer: %d * %d = %d\n", a, b, a * b);
			break;
		case '/':
			if (b == 0) {
				printf("Error: divide by zero!\n");
			}
			else {
				printf("Answer: %d / %d = %d\n", a, b, a / b);
			}
			break;
		case '%':
			if (b == 0) {
				printf("Error: divide by zero!\n");
			}
			else {
				printf("Answer: %d %% %d = %d\n", a, b, a % b);
			}
			break;
		default:
			printf("Error: invalid operator %c!\n", op);
			break;
		}
	}

	return 0;
}
