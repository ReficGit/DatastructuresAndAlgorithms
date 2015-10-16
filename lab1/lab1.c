#include <stdio.h>

typedef struct{
	int h;
	int min;
} Ttime;

void read_time(Ttime *t1, Ttime *t2);
int check_time(Ttime *t1, Ttime *t2);
void time_diff(Ttime *t1, Ttime *t2, Ttime *dur);
void display_time(Ttime *dur);

int main(void)
{
	Ttime t1, t2, dur;

	read_time(&t1, &t2);
	time_diff(&t1, &t2, &dur);
	display_time(&dur);

	return 0;
}

void read_time(Ttime *t1, Ttime *t2)
{
	int aux1 = 0;
	int aux2 = 0;
	int status = 0;
	printf("Enter starting time in the format of hh mm: ");
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

}

void time_diff(Ttime *t1, Ttime *t2, Ttime *dur)
{
	int check = 0;
	int full_minutes_time1 = 0, full_minutes_time2 = 0, answer = 0;	

	full_minutes_time1 = t1->h * 60 + t1->min;
	full_minutes_time2 = t2->h * 60 + t2->min;

	if (check_time(t1, t2) == 0){
		answer = full_minutes_time2 - full_minutes_time1;
	}
	else {
		answer = 24*60 - full_minutes_time1 + full_minutes_time2;
	}
	dur->h = answer/60;
	dur->min = answer%60;
}

void display_time(Ttime *dur)
{
	printf("%.2d::%.2d\n", dur->h, dur->min);
}

int check_time(Ttime *t1, Ttime *t2)
{
	int status_check = 0;
	if(t1->h > t2->h){
		if(t1->min > t2->min){
			status_check = 1;
		}
		else status_check = 1;
	}
	else status_check = 0;

	return status_check;
}
