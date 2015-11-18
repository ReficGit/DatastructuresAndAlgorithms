/* arrque0.c -- An array implementation of Queue
*
* This is simple solution where array elements are moved
* forward in the array in dequeue operation
*/

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#define N 100000
typedef int Titem;

/* The interface of queue */
#define MAXN 5
typedef enum {NOT_OK, OK } Tboolean;
typedef struct {
	Titem *array;
	int number_of_items;
	int max_size;
	int first;
	int last;
} Tqueue;
void initialize_queue (Tqueue *Pqueue);
Tboolean enqueue(Tqueue *p, Titem item);
Tboolean dequeue(Tqueue *p, Titem *Pitem);
void print_queue(const Tqueue *Pqueue);


/* Application */
#if 0
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
#else
int main() {
	Tqueue queue;
	Titem item;
	clock_t tic, tac;
	double duration;
	int i;
	initialize_queue(&queue);
	// first we play a little with the queue to test that it really works
	printf("Fill the queue with %d items\n", N);
	item = 0;
	for (i = 0; i < N; i++) {
		if (enqueue(&queue, item++) != OK) {
			fprintf(stderr, "Enqueue failed\n");
			exit(1);
		}
	}
	printf("Remove half of them\n");
	for (i = 0; i < N/2; i++) {
		if (dequeue(&queue, &item) != OK) {
			fprintf(stderr, "Dequeue failed\n");
			exit(1);
		}
	}
	printf("Add then new %d items to the queue\n", N/2);
	item++;
	for (i = 0; i < N/2; i++) {
		if (enqueue(&queue, item++) != OK) {
			fprintf(stderr, "Enqueue failed\n");
			exit(1);
		}
	}
	// then we deque elements and measure the execution time
	printf("Then dequeue them\n");
	tic = clock();
	for (i = 0; i < N; i++)
		dequeue(&queue, &item);
	tac = clock();
	printf("Last item value %d (should be %d)\n", item, N-1);
	duration = (double)(tac - tic) / CLOCKS_PER_SEC;
	printf("\ndequeue took %lf us to run\n", duration/N*1e6);
}
#endif
/* The implementations of operation functions of the queue */
void initialize_queue ( Tqueue *Pqueue)  {
	Pqueue->number_of_items = 0;
	Pqueue->array = (Titem *) malloc(3*sizeof(Titem));
	Pqueue->max_size = 3;
	Pqueue->first = 0;
	Pqueue->last = -1;
}

Tboolean enqueue( Tqueue *Pqueue, Titem item) {
	int *copy;
	int i = 0;
	if (Pqueue->number_of_items >= Pqueue->max_size){
		copy = (int *) malloc((Pqueue->max_size)*sizeof(int));
		for(i = 0; i<Pqueue->max_size;i++){
			copy[i] = Pqueue->array[i];
		}
		free(Pqueue->array);
		Pqueue->max_size = Pqueue->max_size + 3;
		//Pqueue->array = (Titem *) malloc((Pqueue->max_size)*sizeof(Titem));
	//	for(i = 0; i<Pqueue->max_size-3;i++){
	//		Pqueue->array[i] = copy[i];
	//	}
		Pqueue->array = copy;
		Pqueue->last++;
		if (Pqueue->last > Pqueue->max_size - 1)
			Pqueue->last = 0;
		Pqueue->array[Pqueue->last] = item;
		Pqueue->number_of_items++;
		//printf("size is increased and is now %d items", Pqueue->max_size);
		return (OK);
	}
	else {
		//Pqueue->array[Pqueue->number_of_items++] = item;
		Pqueue->last++;
		if (Pqueue->last > Pqueue->max_size - 1)
			Pqueue->last = 0;
		Pqueue->array[Pqueue->last] = item;
		Pqueue->number_of_items++;
		return (OK);
	}
}

Tboolean dequeue( Tqueue *Pqueue, Titem *Pitem) {
	int i;

	/*if (Pqueue->number_of_items == 0)
	return(NOT_OK);
	else {
	*Pitem = Pqueue->array[0];
	for (i = 0 ; i < Pqueue->number_of_items-1 ; i++)
	Pqueue->array[i] = Pqueue->array[i+1];
	Pqueue->number_of_items--;

	return (OK);
	}*/
	if (Pqueue->number_of_items == 0)
		return(NOT_OK);
	else {
		*Pitem = Pqueue->array[Pqueue->first++];
		if (Pqueue->first > Pqueue->max_size - 1)
			Pqueue->first = 0;
		Pqueue->number_of_items--;
		return (OK);
	}
}

void print_queue (const Tqueue *Pqueue) {
	/*int i;

	printf("\nQueue now: \n\n");
	for (i = 0 ; i <  Pqueue->number_of_items ; i++ ) {
	printf(" %c ", Pqueue->array[i]);
	}
	printf("\n\n");*/
	int i, n;
	printf("\nQueue now: \n\n");
	for (n = 1, i=Pqueue->first ; n <= Pqueue->number_of_items ; n++ ) {
		printf(" %c ", Pqueue->array[i]);
		i++;
		if (i>MAXN-1)
			i = 0;
	}
	printf("\n\n");
}
