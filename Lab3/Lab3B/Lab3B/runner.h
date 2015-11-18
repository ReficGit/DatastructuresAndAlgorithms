#include "time2.h"

typedef struct {
	char name[30];
	Ttime time;
}Trunner;

void readName(Trunner *runner, const char *prompt);
void readTime(Trunner *runner, const char *prompt);
void displayRunner(const Trunner *runner);
int betterRunner(Trunner *runner, int M);