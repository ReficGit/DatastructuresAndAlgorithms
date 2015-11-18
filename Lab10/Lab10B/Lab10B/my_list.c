#include "my_list.h"
/* Operation function implementations for ADT list */
void initialize_list(TOrderedList *list) {
     list->count = 0;
}

int insert_item(TOrderedList *list, Titem item) {
    int find_position(Titem *array, Titem item, int number_of_items);
    int make_room(Titem *array, int where, int size_of_array);
    int i;

    if (list->count < MAX ) {
		i = find_position(list->array, item,  list->count);
		make_room(list->array,i, list->count);
		list->array[i] = item;
		list->count++;
		return 1;
    } else
		return 0;
}

int retrieve_ith(const TOrderedList *list, int i, Titem *item) {
    if (!list_empty(list) && i <list->count) {
		*item = list->array[i];
		return 1;
    } else
		return 0;
}

int number_of_items(const TOrderedList *list){
    return list->count;
}

int list_empty(const TOrderedList *list) {
    return !list->count;
}

/* These are "private" low level functions used to implement public
 operation functions for list */
int find_position(Titem *array, Titem item, int number_of_items) {
    int i=0;

    while (compare(array[i], item) == -1 && i < number_of_items) i++;

    return i;
}

int make_room(Titem *array, int where, int number_of_items) {
    int i;

    if (number_of_items < MAX) {
	for (i = number_of_items - 1 ; i >= where ; i-- )
	    array[i+1] = array[i];
	    return 1;
	} else
	    return 0;
}


/*
 * These are operation functions for abstract datatype Titem 
 */

int read_item(Titem *item) {
    fflush(stdin);	// flush (emtpy) the input keyboard buffer
    *item = getchar();

    return 1;
}

void print_item(Titem item) {
    printf("%c\n", item);
}

int compare(Titem item1 , Titem item2) {
    if ((int)item1 < (int)item2)
		return -1;
    else if ((int)item1 == (int)item2)
		return 0;
    else
		return 1;
}
