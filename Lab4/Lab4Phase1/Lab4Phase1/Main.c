/*
* measure.c – Test bench code for the exercise 4
*
* Written by Jarkko Vuori
*/
#include <stdio.h>
#include "measurement.h"
#include <string.h>
#if 1
int main(int argc, char *argv[]) {
Tmeasurement m;

m = readMeasurements("Z:\\Datastructures and aglorithms\\Lab4\\Lab4Phase1\\Lab4Phase1\\mea.dat"); // xxxx to be replaced by your path
printMeasurements(m);

printf("Mean is %.4lf\n", meanMeasurements(m));

fflush(stdin); 
getchar();

return 0;
}
#else 
int main(int argc, char *argv[]) {
	Tmeasurement m1, m2;

	m1 = readMeasurements("Z:\\Datastructures and aglorithms\\Lab4\\Lab4Phase1\\Lab4Phase1\\mea.dat");
	printMeasurements(m1);
	//m2 = m1; // they both have the addresses of the values not the values themselves

	copy(&m1, &m2);
	incMeasurements(m2, 0.1);

	printf("Mean m1 is %.4lf\n", meanMeasurements(m1));
	printf("Mean m2 is %.4lf\n", meanMeasurements(m2));

	fflush(stdin); 
	getchar();

	return 0;
}
#endif