#include <stdio.h>
#include <stdlib.h>
#include "ch_list.h"
#include "time_list.h"
#include "list.h"



int main () {
	TListTitem item_list;
	TListTtime ttime_list;
	Titem item;
	Ttime time;
	int i = 0;

	initialize_list_Ttime(&ttime_list); //time list initialization
	initialize_list_Titem(&item_list); //item list initialization

	printf("Enter time in format of hh mm\n");
	for (i=0; i<5; i++) {
		read_time(&time);
		insert_item_Ttime(&ttime_list, time);
	}

	printf("Enter single characters\n");
	for (i=0; i<10; i++) {
		read_item(&item);
		insert_item_Titem(&item_list, item);
	}

	printf("Sorted times\n");
	for (i=0; i<number_of_items_Ttime(&ttime_list); i++) {
		retrieve_ith_Ttime(&ttime_list, i, &time);
		display_time(time);
	}
	printf("\nSorted characters\n");
	for (i=0; i<number_of_items_Titem(&item_list); i++) {
		retrieve_ith_Titem(&item_list, i, &item);
		print_item(item);
	}

	system("pause");
	return 0;
}