#include "time2.h"
#include "stdio.h"

void read_time(Ttime *time)
{
	int aux1 = 0;
	int aux2 = 0;
	int status = 0;
	//printf("Enter starting time in the format of hh mm: ");
	do {
	scanf("%d %d", &aux1, &aux2);
	if (aux1 > 24 || aux2 > 60){
		printf("Time should be in the format of hh mm. Enter your time again!\n");
	}
	else {
		*time = aux1*60 + aux2;
		//printf("%d:%d\n", t1->h, t1->min);
		status = 1;
	}
	}while(status != 1);
	/*
	status = 0;

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

void time_diff(Ttime *t1, Ttime *t2, Ttime *dur)
{
	int check = 0;
	int full_minutes_time1 = 0, full_minutes_time2 = 0, answer = 0;	

	full_minutes_time1 = *t1;
	full_minutes_time2 = *t2;

	if (check_time(t1, t2) == 0){
		answer = full_minutes_time2 - full_minutes_time1;
	}
	else {
		answer = 24*60 - full_minutes_time1 + full_minutes_time2;
	}
	*dur = answer;
}

void display_time(Ttime *dur)
{
	printf("%.2d::%.2d", *dur/60, *dur%60);
}

int check_time(Ttime *t1, Ttime *t2)
{
	int status_check = 0;
	if(*t1 > *t2){
			status_check = 1;
	}
	else status_check = 0;

	return status_check;
}