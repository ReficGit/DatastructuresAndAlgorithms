typedef struct{
	int h;
	int min;
} Ttime;

void read_time(Ttime *t1);
int compare_Ttime(Ttime t1, Ttime t2);
void display_time(Ttime dur);
