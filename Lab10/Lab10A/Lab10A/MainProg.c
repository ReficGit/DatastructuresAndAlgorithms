#include <stdio.h>
#include "list.h"


int main () {
	Tlist list;
	int order_no;
	char to_be_searched;

	initialize_list(&list);
	delete_last(&list);

	insert_to_list_end(&list, '?');
	print_list(list);
	delete_last(&list);
	print_list(list);

	insert_to_list_end(&list, 'x');
	insert_to_list_end(&list, 'a');
	insert_to_list_end(&list, 'b');
	insert_to_list_end(&list, 'c');
	insert_to_list_end(&list, 'd');
	insert_to_list_end(&list, 'y');
	//delete_last(&list);
	print_list(list);

	printf("Enter first character to be searced\n");
	fflush(stdin); scanf("%c", &to_be_searched);
	if (find_pos_in_list(&list,to_be_searched, &order_no))
		printf("The order no is %d\n", order_no);
	else
		printf("Not found\n");

	printf("Enter second character to be searced\n");
	fflush(stdin); scanf("%c", &to_be_searched);
	if (find_pos_in_list(&list, to_be_searched, &order_no))
		printf("The order no is %d\n", order_no);
	else
		printf("Not found\n");
	
	delete_first(&list);
	print_list(list);
	delete_last(&list);
    print_list(list);
	fflush(stdin); getchar();
}