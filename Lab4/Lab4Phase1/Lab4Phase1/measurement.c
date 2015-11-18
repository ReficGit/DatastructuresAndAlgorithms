#include <stdlib.h>
#include <stdio.h>
#include "measurement.h"

Tmeasurement readMeasurements(char *filename)
{
	Tmeasurement m;
	FILE *my_file;
	int line_number = 0;
	double read = 0;
	int i = 0;
	double n = 0;

	my_file = fopen(filename, "r");

	if(my_file == NULL){
		printf("Unable to open file\n");
	}
	else {
		while(!feof(my_file)){
			if(fscanf(my_file, "%lf", &read) != NULL){
				if(line_number == 0){
					m.i = read;			
					m.meas = (double*)malloc(m.i*sizeof(double));
					line_number++;
				}
				else{
					m.meas[i] = read;
					i++;
				}
			}
		}		
	}

	return m;
}

void printMeasurements(Tmeasurement m)
{
	int i = 0;
	
	for(i=0; i<m.i; i++){
		printf("%lf\n", m.meas[i]);
	}
}

double meanMeasurements(Tmeasurement m)
{
	int i = 0;
	double sum = 0;
	for(i=0; i<m.i; i++){
		sum = sum + m.meas[i];
	}

	return (sum/i);
}

void incMeasurements(Tmeasurement m, double increment)
{
	int i = 0;
	for(i = 0; i<m.i; i++){
		m.meas[i] = m.meas[i] + increment;
	}
}

void copy(Tmeasurement *source ,Tmeasurement *dest)
{
	int i = 0;
	dest->i = source->i;
	dest->meas = (double *) malloc(dest->i*sizeof(double));
	for(i = 0; i<dest->i; i++){
		dest->meas[i] = source->meas[i];
	}

}