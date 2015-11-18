#include "ch.h"
#include <stdio.h>

int read_item(Titem *item) {
    fflush(stdin);	// flush (emtpy) the input keyboard buffer
    *item = getchar();

    return 1;
}

void print_item(Titem item) {
    printf("%c\n", item);
}

int compare_Titem(Titem item1 , Titem item2) {
    if ((int)item1 < (int)item2)
		return -1;
    else if ((int)item1 == (int)item2)
		return 0;
    else
		return 1;
}
