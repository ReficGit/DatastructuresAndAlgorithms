/*#include <stdio.h>
#include <stdlib.h>
#include "list.h"

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
		//	tmp = *list;
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

	printf("\nList:\n");
	while(what != NULL){
		printf("%c \n", what->item);
		what = what->next;
	}
}

void delete_first(Tlist *list){
	Tpointer tmp;
	tmp=*list;
	if(*list==NULL){
		printf("Nothing to delete\n");
	}
	else{
		*list = tmp->next;
		free(tmp);	
		printf("First item is deleted\n");
	}
}

void delete_last(Tlist *list){
	Tpointer tmp;
	Tpointer tmp2;

	if(*list == NULL){
		//do nothing
		printf("Nothing to delete\n");
	}
	else {
		tmp = *list;
		if(tmp->next == NULL){
			free(tmp);
			initialize_list(*&list);
		}
		else{

			while(tmp->next->next!=NULL){ 
				tmp = tmp->next;
			}
			tmp2=tmp->next;
			tmp->next = NULL;
			free(tmp2);
		}
		printf("Last item is deleted\n");
	}
}

int find_pos_in_list(const Tlist *list, Titem item, int *pos){
	Tpointer tmp;

	*pos = 1;
	tmp = *list;
	if(*list == NULL){
		//do nothing
		printf("There are no items in the list\n");
	}
	else{
		while(tmp != NULL){			
			if(tmp->item==item){
				return 1;
			}
			else {
				tmp=tmp->next;
				(*pos)++;
			}
		}
	}
	return 0;
}*/