#include "runner.h"
#include "stdlib.h"
#include "stdio.h"

int main(void)
{
	Trunner runner1, runner2;
	int i = 0;
	char s[80];
	int best = 0;
	/*
	printf("Enter name for runner 1: ");
	readName(&runner1, s);
	printf("Enter name for runner 2: ");
	readName(&runner2, s);
	printf("Enter time for runner 1: ");
	readTime(&runner1, s);
	printf("Enter time for runner 2: ");
	readTime(&runner2, s);*/


	sprintf(s, "Give the name for the runner %d? ", 1);
	readName(&runner1, s);
	sprintf(s, "Give the name for the runner %d? ", 2);
	readName(&runner2, s);

	sprintf(s, "Give the time (hh mm) for the runner %d? ", 1);
	readTime(&runner1, s);
	sprintf(s, "Give the time (hh mm) for the runner %d? ", 2);
	readTime(&runner2, s);
	

	best = betterRunner(&runner1, &runner2);

	printf("The best runner is ");
	if(best == 0){
		displayRunner(&runner1);
	}
	else displayRunner(&runner2);
}