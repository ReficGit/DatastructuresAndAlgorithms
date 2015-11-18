/* Array implementation of an ordered list. The order is defined
* as alphabetic order. The location in the array presents the order.
* This version is independent (on source level) of the item type
* stored in list
*
* In order to run this program in Visual Studio 2010 select
* Debug-Start-without-Debugging (or pressing Ctrl-F5)
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 10
/* ADT item  */
typedef char Titem;
int read_item(Titem *item);
void print_item(Titem item);
int compare(Titem item1, Titem item2);

/* ADT list */
/*
#define MAX 10
typedef struct  {
int count;
Titem array[MAX];
} TOrderedList;*/

//typedef char Titem;

// Interface of list
typedef struct node *Tpointer;

typedef struct node {
	Titem item;
	Tpointer next;
} Tnode;

typedef Tpointer TOrderedList;

void initialize_list(TOrderedList *list);
int insert_item(TOrderedList *list, Titem item);
int retrieve_ith(const TOrderedList *list, int i, Titem *item);
int number_of_items(const TOrderedList *list);
int list_empty(const TOrderedList *list);
void print_list (TOrderedList list);

/* The application */
int main () {
	TOrderedList list; Titem item;
	int i;

	initialize_list(&list);
	printf("\n Enter items in any order\n");

	for (i = 0 ; i < 5 ; i++) {
		read_item(&item);
		if (!insert_item(&list, item))
			printf("\nList is full");
	}

	printf("\nList ouputted using for loop and retrieve_ith function:\n");
	  for (i=0; i<number_of_items(&list); i++) {
		retrieve_ith(&list, i, &item);
		print_item(item);
	  }
	return 0;
}

/* Operation function implementations for ADT list */
void initialize_list(TOrderedList *list) {
	//  list->count = 0;
	*list = NULL;
}

int insert_item(TOrderedList *list, Titem item) {
	TOrderedList t_temp, t_temp2, *t_temp3;

	t_temp = (TOrderedList)malloc(sizeof(TOrderedList));
	t_temp->item = item;
	t_temp->next = NULL;
	t_temp2 = *list;
	t_temp3 = *&list;
	while(t_temp2 != NULL && (int)(t_temp2->item) < (int)(t_temp->item))
	{
		t_temp3 = &t_temp2->next;
		t_temp2 = t_temp2->next;
	}
	*t_temp3 = t_temp;
	t_temp->next = t_temp2;
	return 1;
}

int retrieve_ith(const TOrderedList *list, int i, Titem *item) {
	TOrderedList tmp;
	tmp = *list;
	while (tmp!=NULL) {
		*item = tmp->item;
		printf("%c\n",tmp->item);
		tmp=tmp->next;
	}
	return 1;
}

int number_of_items(const TOrderedList *list){
	return 1;
}

int list_empty(const TOrderedList *list) {
	 return 0;
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
	//printf("%c\n", item);
}

int compare(Titem item1 , Titem item2) {
	if ((int)item1 < (int)item2)
		return -1;
	else if ((int)item1 == (int)item2)
		return 0;
	else
		return 1;
}
