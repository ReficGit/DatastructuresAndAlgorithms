/*#include "runner.h"
#include "stdio.h"

#define M 10

int main(int argc, char *argv[])
{
	Trunner runners[M];
	int n, dur;
	char s[80];
	char temp[30];
	int i = 0;
	int status = 0;

	printf("How many names you have? ");
	fgets(temp, 10, stdin);
	sscanf_s(temp, "%d", &n);


	for(i = 0; i<n; i++){
		sprintf(s, "Give the name for the runner %d? ", i+1);
		//printf("Enter name for runner %d: ", i+1);
		readName(&runners[i], s);
	}

	for(i = 0; i<n; i++){
		sprintf(s, "Give the time (hh mm) for the runner %d? ", i+1);
		//printf("Enter time for runner %d: ", i+1);
		readTime(&runners[i], s);
	}


	status = betterRunner(runners, n);

	printf("The winner is: ");
	displayRunner(&runners[status]);
	
	printf("\n\nThe result list: \n");
	for(i = 0; i<n; i++){
		printf("%d:", i+1);
		displayRunner(&runners[i]);
		time_diff(&runners[status].time, &runners[i].time, &dur);
		printf(" +");
		display_time(&dur);
		printf("\n");
	}
}*/

#include "stdio.h"
#include "stdlib.h"
#include "runner.h"
#define N 2
int main(int argc, char *argv[]) {
Trunner runners[N];
int i, n;
char s[80];
n = N;
printf("%d", n);
for (i = 0; i < n; i++) {
sprintf(s, "Give the name for the runner %d? ", i+1); 
//printf("Give the name for the runner %d? ", i+1); 
readName(&runners[i], s);
}
for (i = 0; i < n; i++){
displayRunner(&runners[i]);
printf("\n");
}
system("PAUSE");
}