#include "time2.h"
#include "stdio.h"

int main(void)
{
	Ttime t1, t2, dur;
	
	printf("Enter starting time in the format of hh mm: ");
	read_time(&t1);
	
	printf("Enter ending time in the format of hh mm: ");
	read_time(&t2);

	time_diff(&t1, &t2, &dur);
	display_time(&dur);

	return 0;
}