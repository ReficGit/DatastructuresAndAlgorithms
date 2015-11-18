typedef struct{
	int h;
	int min;
} Ttime;

void read_time(Ttime *time);
int check_time(Ttime *t1, Ttime *t2);
void time_diff(Ttime *t1, Ttime *t2, Ttime *dur);
void display_time(Ttime *dur);