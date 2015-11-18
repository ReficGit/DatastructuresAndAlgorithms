#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// Implementation of list (only obj is need in appl)
void initialize_list (Tlist *list) {
	*list = (Tpointer)malloc(sizeof(Tnode));
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
#if 1
		printf("%d+%di\n", *((Tcomplex*)(what->item)));
#else
		printf("%c \n", *((char*)(what->item)));
#endif
		what = what->next;
	}
}