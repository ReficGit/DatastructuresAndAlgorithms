/* arrque0.c -- An array implementation of Queue
 *
 * This is simple solution where array elements are moved
 * forward in the array in dequeue operation
 */

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
typedef char Titem;

/* The interface of queue */
#define MAXN 5
typedef enum {NOT_OK, OK } Tboolean;
typedef struct {
    Titem *array;
    int number_of_items;
	int max_size;
} Tqueue;
void initialize_queue (Tqueue *Pqueue);
Tboolean enqueue(Tqueue *p, Titem item);
Tboolean dequeue(Tqueue *p, Titem *Pitem);
void print_queue(const Tqueue *Pqueue);


/* Application */
int main() {
    Tqueue queue;
    Tboolean succeed;
    char chr;

    initialize_queue(&queue);
    printf("\nEnter a letter to be queued ");
    printf("\nor digit 1 to dequeue a letter");
    printf("\nor Return to quit a program\n");

    chr = getche();
    while (chr != '\n' && chr != '\r') {
        if (isalpha(chr)) {
			succeed=enqueue(&queue, chr);
			print_queue(&queue);
			if (!succeed)
				printf("\n Enqueue operation failed\n");
		}
		if (chr == '1') {
			succeed = dequeue(&queue, &chr);
			if  (succeed) {
				printf("\na letter dequeued %c ", chr);
				print_queue(&queue);
			} else
				printf("\nDequeue operation failed\n ");
		}

		chr = getche();
     }
}

/* The implementations of operation functions of the queue */
void initialize_queue ( Tqueue *Pqueue)  {
    Pqueue->number_of_items = 0;
	Pqueue->array = (Titem *) malloc(3*sizeof(Titem));
	Pqueue->max_size = 3;
}

Tboolean enqueue( Tqueue *Pqueue, Titem item) {
	char *copy;
	int i = 0;
	if (Pqueue->number_of_items >= Pqueue->max_size){
		copy = (char *) malloc((Pqueue->max_size + 3)*sizeof(char));
		for(i = 0; i<Pqueue->max_size;i++){
			copy[i] = Pqueue->array[i];
		}
		Pqueue->max_size = Pqueue->max_size + 3;
		free(Pqueue->array);
		//Pqueue->array = (Titem *) malloc((Pqueue->max_size)*sizeof(Titem));
	//	for(i = 0; i<Pqueue->max_size-3;i++){
	//		Pqueue->array[i] = copy[i];
	//	}
		Pqueue->array = copy;
		Pqueue->array[Pqueue->number_of_items++] = item;
		printf("size is increased and is now %d items", Pqueue->max_size);
		return (OK);
	}
    else {
		Pqueue->array[Pqueue->number_of_items++] = item;
		return (OK);
    }
}

Tboolean dequeue( Tqueue *Pqueue, Titem *Pitem) {
    int i;

    if (Pqueue->number_of_items == 0)
		return(NOT_OK);
    else {
        *Pitem = Pqueue->array[0];
        for (i = 0 ; i < Pqueue->number_of_items-1 ; i++)
            Pqueue->array[i] = Pqueue->array[i+1];
        Pqueue->number_of_items--;

		return (OK);
    }
}

void print_queue (const Tqueue *Pqueue) {
    int i;

    printf("\nQueue now: \n\n");
    for (i = 0 ; i <  Pqueue->number_of_items ; i++ ) {
		printf(" %c ", Pqueue->array[i]);
    }
    printf("\n\n");
}
