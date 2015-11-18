#include "intstack.h"
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

int main(void){
	Tintstack my_stack;

	char input = '0';
	int number = 0, number2 = 0;

	initialize_int_stack(&my_stack);

	do{
		fflush(stdin);
		input = getchar();
		if(isdigit(input)){
			number = input - 48;
			if(!push_int(&my_stack, number)){
				printf("an error occured while pushing values into the stack\n");
			}
		}
		else if(input == '+'){
			if(pop_int(&my_stack, &number)){
				if(pop_int(&my_stack, &number2)){
					number = number2 + number;
				}
				else printf("an error occured while popping values from the stack\n");
			}
			else printf("an error occured while popping values from the stack\n");
			if(!push_int(&my_stack, number)){
				printf("an error occured while pushing values into the stack\n");
			}
		}
		else if(input == '-'){
			if(pop_int(&my_stack, &number)){
				if(pop_int(&my_stack, &number2)){
					number = number2 - number;
				}
				else printf("an error occured while popping values from the stack\n");
			}
			else printf("an error occured while popping values from the stack\n");
			if(!push_int(&my_stack, number)){
				printf("an error occured while pushing values into the stack\n");
			}
		}
		else if(input == '='){
			if(pop_int(&my_stack, &number)){
				printf("top value is %d\n", number);
				if(!(push_int(&my_stack, number))){
					printf("an error occured while pushing values into the stack\n");
				}
			}
			else printf("an error occured while popping values from the stack\n");
		}
	}while(input != 'Q');

	print_int_stack(&my_stack);
	is_empty_int_stack(&my_stack);

	system("pause");
}