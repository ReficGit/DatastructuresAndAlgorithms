#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>

typedef int Titem;

//The interface of queue
#define MAXN 3
typedef enum {NOT_OK, OK } Tboolean;
typedef struct {
	Titem *array;
	int   first;
	int   last;
    int   number_of_items;
	int   size;
	Tboolean circular;
} *Tqueue, _Tqueue;

Tqueue CreateQueue(Tboolean fCircular);
Tboolean enqueue(Tqueue Pqueue, Titem item);
Tboolean dequeue(Tqueue Pqueue, Titem *Pitem);
void print_queue(Tqueue Pqueue);
void DestroyQueue(Tqueue Pqueue);