/* dynlist4a.c -- Dynamic linked linear list
*
* The abstraction is ok, because first and last are are
* incapsulated inside datatype Tlist and all paramaters of
* operation functions are of this type.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "heapdump.h"


// Interface of list
typedef struct node *Tpointer;

typedef struct node {
	void *item;
	Tpointer next;
} Tnode;

typedef struct complex_numbers{
	int x;
	int y;
}Tcomplex;

typedef Tpointer Tlist;

void initialize_list(Tlist *list);
void insert_to_list_end (Tlist *list, void *data);
extern void print_list(void *p);
extern void cleanup_list(void *p);
char *CreateChar(char c);
Tcomplex *CreateComplex(int a, int b);

#if 1
// Application
int main (void) {
	Tlist list;
	initialize_list(&list);
	insert_to_list_end(&list, CreateComplex(1, 2)); // add 1+2i
	insert_to_list_end(&list, CreateComplex(2, 3)); // add 2+3i
	insert_to_list_end(&list, CreateComplex(3, 4)); // add 3+4i
	insert_to_list_end(&list, CreateComplex(4, 5)); // add 4+5i
	print_list(list);
	cleanup_list(&list);
	fflush(stdin); getchar();
}
#else
int main (void) {
	Tlist list;
	
	initialize_list(&list);
	insert_to_list_end(&list, CreateChar('a'));
	insert_to_list_end(&list, CreateChar('b'));
	insert_to_list_end(&list, CreateChar('c'));
	insert_to_list_end(&list, CreateChar('d'));
	print_list(list);
	cleanup_list(&list);
	heapleak();
	fflush(stdin); getchar();
	
}
#endif


// Implementation of list (only obj is need in appl)
void initialize_list (Tlist *list) {
	//*list = (Tpointer)malloc(sizeof(Tnode));
	*list = NULL;
}

void cleanup_list(Tlist *list) {
	Tpointer aux1, aux2;

	aux1 = *list;
	while (aux1 != NULL) {
		aux2 = aux1->next;
		free(aux1->item);
		free(aux1);
		printf("\nDeleted"); //for testing purposes
		aux1=aux2;
	}
	initialize_list(list);
}

void insert_to_list_end(Tlist *list, void *data) {
	Tlist tmp, tmp2;

	tmp = *list;

	if(*list==NULL){ 
		tmp = (Tpointer)malloc(sizeof(Tnode));
		tmp->item = data;
		tmp->next = NULL;
		*list = tmp;
	}
	else{ 
		tmp = *list;
		while(tmp->next !=NULL){ 
			tmp = tmp->next;
		}
		tmp2 = (Tpointer)malloc(sizeof(Tnode));
		tmp2->item = data;
		tmp2->next = NULL;
		tmp->next = tmp2;
	}
}

void print_list (Tlist list) {
	Tlist what;

	what = list;

	printf("\nList 4 :");
	while(what != NULL){
#if 0
		printf("%d+%di\n", *((Tcomplex*)(what->item)));
#else
		printf("%c \n", *((char*)(what->item)));
#endif
		what = what->next;
	}
}

char *CreateChar(char c)
{
	char *ptr;
	ptr = (char *) malloc(sizeof(char));
	*ptr = c;

	return ptr;
}

Tcomplex *CreateComplex(int a, int b)
{
	Tcomplex *my;
	my = (Tcomplex *) malloc(sizeof(Tcomplex));
	my->x = a;
	my->y = b;

	return my;
}