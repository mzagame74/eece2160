/* Matt Zagame Copyright 2021
 * September 19, 2021
 * prog2_shapes.c reads dimensions for three different shapes from the user and
 * calculates areas and volumes and prints the information to the console.
*/
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

int main(void) {
	double sphereRadius;
	double coneRadius, coneHeight;
	double prismWidth, prismLength, prismHeight;

	// get user input
	printf("Enter sphere radius (cm): ");
	scanf("%lf", &sphereRadius);
	printf("\nEnter base radius and height of cone (cm): ");
	scanf("%lf %lf", &coneRadius, &coneHeight);
	printf("\nEnter base width, length, and height of triangular prism (cm): ");
	scanf("%lf %lf %lf", &prismWidth, &prismLength, &prismHeight);

	// calculate and print results
	printf("\n\nSphere information:\n");
	printf("Radius = %0.2lf cm\n", sphereRadius);
	printf("Surface area = %0.4lf square cm\n", 4 * M_PI *
		pow(sphereRadius, 2));
	printf("Volume = %0.4lf cubic cm\n", (4 / 3.0) * M_PI *
		pow(sphereRadius, 3));

	printf("\nCone information:\n");
	printf("Base radius = %0.2lf cm\n", coneRadius);
	printf("Height = %0.2lf cm\n", coneHeight);
	printf("Surface area = %0.4lf square cm\n", M_PI * coneRadius *
        (coneRadius + sqrt(pow(coneHeight, 2) + pow(coneRadius, 2))));
	printf("Volume = %0.4lf cubic cm\n", M_PI * pow(coneRadius, 2) *
		(coneHeight / 3));

	printf("\nPrism information:\n");
	printf("Base width = %0.2lf cm\n", prismWidth);
	printf("Length = %0.2lf cm\n", prismLength);
	printf("Height = %0.2lf cm\n", prismHeight);
	printf("Surface area = %0.4lf square cm\n", (prismWidth * prismHeight) +
		prismLength * (prismWidth + (2 * sqrt(pow(0.5 * prismWidth, 2) +
			pow(prismHeight, 2)))));
	printf("Volume = %0.4lf cubic cm\n", 0.5 * prismWidth * prismHeight *
		prismLength);

	return 0;
}
