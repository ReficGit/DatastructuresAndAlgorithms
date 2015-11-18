/* dynlist4a.c -- Dynamic linked linear list
*
* The abstraction is ok, because first and last are are
* incapsulated inside datatype Tlist and all paramaters of
* operation functions are of this type.
*/

#include <stdio.h>
#include <stdlib.h>

typedef char Titem;

// Interface of list
typedef struct node *Tpointer;

typedef struct node {
	Titem item;
	Tpointer next;
} Tnode;

/*typedef struct {
Tpointer first;
Tpointer last;
} Tlist;*/

typedef Tpointer Tlist;

void initialize_list(Tlist *list);
void insert_to_list_end (Tlist *list, Titem data);
void print_list(Tlist list);
void cleanup_list(Tlist *list);


// Application
int main (void)  {
	Tlist list;

	initialize_list(&list);
	insert_to_list_end(&list, 'a');
	insert_to_list_end(&list, 'b');
    insert_to_list_end(&list, 'c');
	insert_to_list_end(&list, 'd');

	   print_list(list);
	   cleanup_list(&list);

	fflush(stdin); getchar();
}


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
		free(aux1);
		printf("\nDeleted"); //for testing purposes
		aux1=aux2;
	}
	initialize_list(list);
}

void insert_to_list_end(Tlist *list, Titem data) {
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
		printf("%c \n", what->item);
		what = what->next;
	}
}