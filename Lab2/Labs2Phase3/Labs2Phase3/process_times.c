#include "time2.h"
#include "stdio.h"

#define M 10

int smallest(Ttime *time, int j);

int main(void)
{
	Ttime j;
	Ttime time[M];
	Ttime dur;
	Ttime smal;
	int i = 0;

	printf("How many times you have? ");
	scanf("%d", &j);
	
	for(i = 0; i<j; i++){
	printf("Give the time %d (hh mm)? ", i+1);
	read_time(&time[i]);
	}
	
	smal = smallest(time, j);
	//printf("%d" , smal);
	//display_time(&smal);
	printf("Result list:\n");
	for(i = 0; i<j; i++){
	time_diff(&smal, &time[i], &dur);
	display_time(&time[i]);
	printf(" ");
	display_time(&dur);
	printf("\n");
	}
	
	return 0;
}

int smallest(Ttime *time, int j)
{
	int smal = 0;
	int i = 0;
	smal = time[0];
	//printf("%d", smal);

	for(i = 1; i<j; i++){
		if(time[i] < smal){
			smal = time[i];
		}
	}

	//printf("smal %d\n", smal);
	return smal;
}