#include "runner.h"
#include "stdio.h"
#include "string.h"
/*
void readName(Trunner *runner, const char *prompt)
{
	//char temp[30];
	int k = 0;

	fgets(runner->name, 30, stdin);
	k = strlen(runner->name);
	runner->name[k-1] = '\0';
}

void readTime(Trunner *runner, const char *prompt)
{
	Ttime temp;
	read_time(&temp);
	runner->time = temp;
}*/

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
	//printf("DO PRINTF\n");
	printf("%s ", runner->name);
	//printf("POSLE PRINTF\n");
	display_time(&temp);
//	printf("POSLE DISP TIME\n");
	printf("\n");
}

int betterRunner(const Trunner *runner1, const Trunner *runner2)
{
	Ttime run1 = runner1->time;
	Ttime run2 = runner2->time;
	int status = 0;

	if(run1 < run2){
		status = 0;
	}
	else status = 1;

	return status;
}