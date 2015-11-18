#include "runner.h"
#include "stdio.h"
#include "string.h"

void readName(Trunner *runner, const char *prompt)
{
	//char temp[30];
	int k = 0;
	printf("%s ", prompt);
	fgets(runner->name, 30, stdin);
	k = strlen(runner->name);
	runner->name[k-1] = '\0';
}

void readTime(Trunner *runner, const char *prompt)
{
	Ttime temp;
	printf("%s ", prompt);
	read_time(&temp);
	runner->time = temp;
}

void displayRunner(const Trunner *runner)
{
	Ttime temp = runner->time;
	printf("%s\t\t\t", runner->name);
	display_time(&temp);
}

int betterRunner(Trunner *runners, Ttime s)
{
	int status = 0;
	Ttime time_small;
	int i = 0;
	time_small = runners[0].time;

	for(i = 1; i<s; i++){
		if(time_small > runners[i].time){
			time_small = runners[i].time;
			status = i;
		}
	}

	return status;
}