#include "time.h"
#include <stdio.h>

void read_time(Ttime *t1)
{
	int aux1 = 0;
	int aux2 = 0;
	int status = 0;
	do {
	scanf("%d %d", &aux1, &aux2);
	if (aux1 > 24 || aux2 > 60){
		printf("Time should be in the format of hh mm. Enter your time again!\n");
	}
	else {
		t1->h = aux1;
		t1->min = aux2;
		//printf("%d:%d\n", t1->h, t1->min);
		status = 1;
	}
	}while(status != 1);
	
	status = 0;
	/*
	printf("Enter ending time in the format of hh mm: ");
	do {
	scanf("%d %d", &aux1, &aux2);
	if (aux1 > 24 || aux2 > 60){
		printf("Time should be in the format of hh mm. Enter your time again!\n");
	}
	else {
		t2->h = aux1;
		t2->min = aux2;
		//printf("%d:%d\n", t2->h, t2->min);
		status = 1;
	}
	}while(status != 1);
	*/
}


void display_time(Ttime dur)
{
	printf("%.2d::%.2d\n", dur.h, dur.min);
}

int compare_Ttime(Ttime t1, Ttime t2)
{
	int full_minutes_time1 = 0, full_minutes_time2 = 0, answer = 0;	
	int status_check = 0;
	full_minutes_time1 = t1.h * 60 + t1.min;
	full_minutes_time2 = t2.h * 60 + t2.min;

	if (full_minutes_time1 < full_minutes_time2)
		status_check = -1;
	else if (full_minutes_time1 == full_minutes_time2)
		status_check = 0;
    else
		status_check = 1;

	return status_check;
}