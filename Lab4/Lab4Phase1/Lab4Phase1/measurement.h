typedef struct{
	int i;
	double *meas;
	
} Tmeasurement;

Tmeasurement readMeasurements(char *filename);
void printMeasurements(Tmeasurement m);
double meanMeasurements(Tmeasurement m);
void incMeasurements(Tmeasurement m, double increment);
void copy(Tmeasurement *m2,Tmeasurement *m1);