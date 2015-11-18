#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include "arrque.h"

//The implementations of operation functions of the queue
Tqueue CreateQueue(Tboolean fCircular) {
	Tqueue Pqueue = (Tqueue)malloc(sizeof(_Tqueue));
	Pqueue->number_of_items = 0;
	Pqueue->size = MAXN;
	Pqueue->array = (Titem *)malloc(Pqueue->size*sizeof(Titem));
	Pqueue->first = 0;
	Pqueue->last = -1;
	Pqueue->circular = fCircular;
	return Pqueue;
}

Tboolean enqueue( Tqueue Pqueue, Titem item) {
	Titem *new_array;
	int i;

	Pqueue->last++;
	if (Pqueue->number_of_items == Pqueue->size) {
		new_array = (Titem *)malloc(Pqueue->size*sizeof(Titem)+MAXN*sizeof(Titem));
		for (i=0; i<Pqueue->size; i++) {
			if (Pqueue->first + i < Pqueue->size) new_array[i] = Pqueue->array[i + Pqueue->first];
			else new_array[i] = Pqueue->array[Pqueue->first + i - Pqueue->size];
		}
		Pqueue->first = 0;
		Pqueue->last = Pqueue->size;
		Pqueue->size += MAXN;
		free(Pqueue->array);
		Pqueue->array = new_array;
	} else if (Pqueue->last == Pqueue->size) {
		Pqueue->last = 0;
	}

	Pqueue->array[Pqueue->last] = item;
	Pqueue->number_of_items++;
	return (OK);
}

Tboolean dequeue( Tqueue Pqueue, Titem *Pitem) {
	int i;

	if (Pqueue->number_of_items == 0) 
		return(NOT_OK);

	else if (Pqueue->circular == OK) {
		*Pitem = Pqueue->array[Pqueue->first++];

		if (Pqueue->first == Pqueue->size) 
			Pqueue->first = 0;

		Pqueue->number_of_items--;
	} 

	else if (Pqueue->circular == NOT_OK) {
		*Pitem = Pqueue->array[0];

		for (i = 0 ; i < Pqueue->number_of_items-1 ; i++)
			Pqueue->array[i] = Pqueue->array[i+1];

		Pqueue->number_of_items--;
	}

	return (OK);
}

void print_queue (Tqueue Pqueue) {
	int i;

	printf("\nQueue now: \n\n");
	for (i = 0 ; i <  Pqueue->number_of_items ; i++ ) {
		if (Pqueue->first + i < Pqueue->size) printf(" %c", Pqueue->array[Pqueue->first + i]);
		else printf(" %c", Pqueue->array[Pqueue->first + i - Pqueue->size]);
	}
	printf("\n\n");
}

void DestroyQueue(Tqueue Pqueue) {
	free(Pqueue);
}