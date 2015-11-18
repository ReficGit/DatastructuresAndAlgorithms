#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "heapdump.h"

char *CreateChar(char c);
Tcomplex *CreateComplex(int a, int b);

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
	heapleak();
	fflush(stdin); getchar();
	//heapdump();


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