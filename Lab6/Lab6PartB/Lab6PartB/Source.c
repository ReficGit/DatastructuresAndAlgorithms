/*#include "intstack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void infixTopostfix(char *infix,char *postfix);
int priority(char op_tor,const Tintstack *op_tors, int top);

int main(void)
{
	char infix[80];
	char postfix;
	int i = 0;
	fflush(stdin);
	fgets(infix, 80, stdin);
	infixTopostfix(infix, &postfix);
}

void infixTopostfix(char *infix,char *postfix)
{
	Tintstack operators;
	int i = 0;
	int j = 0;
	int k = 0;
	int out = 0;
	int f_sign = 0;
	int top = 0;
	initialize_int_stack(&operators);
	postfix = (char *) calloc(strlen(infix),sizeof(infix));

	//Go through the infix array
	for(i=0; i<strlen(infix);i++){			
		f_sign = sign(infix[i]);
		if(isdigit(infix[i])){ //Operand? -> append. if not -> continue
			postfix[j] = infix[i];
			j++;
		}
		//check if it is an operator
		else if(sign(infix[i]) == -1 || sign(infix[i]) == -2) {	
			//if stack is empty -> push
			if(is_empty_int_stack(&operators)){						
				push_int(&operators, infix[i]);
			}
			 //If stack is not empty, check priority
			else if(!(is_empty_int_stack(&operators))){           
				for(k = operators.top;k>-1; --k){
					//Operator's priority in stack is higher, then pop and append
					if((priority(infix[i], &operators, k) == -2)){ 
						pop_int(&operators, &out);
						postfix[j] = out;
						j++;
					}
					//Operator's priority in stack is lower or same, then push
					if((priority(infix[i], &operators, k) == -1 || (priority(infix[i], &operators, k) == 0))){ 
						push_int(&operators, infix[i]);
						printf("push\n");
					}
					//if stack is empty again -> push
					else if(is_empty_int_stack(&operators)){	
						push_int(&operators, infix[i]);
					}
				}
			}
		}
	}
	//Append all the left operators
	for(i=operators.top; i>-1;i--){			
		pop_int(&operators, &out);
		postfix[j] = out;
		printf("last pop\n");
		j++;
	}

	for(i = 0; i<strlen(postfix);i++){
		printf("%c", postfix[i]);
	}
}

int priority(char op_tor,const Tintstack *op_tors, int top)
{
	int i = 0;
	int f_sign = 0, f_sign2 = 0;
	f_sign = sign(op_tor);
	f_sign2 = sign(op_tors->array[top]);
	/*if(op_tors->array[k] != op_tor && (op_tors->array[k] == '*' || op_tors->array[k] == '/')){
	return -2;
	}
	else  return -1;
	
	if(f_sign > f_sign2){
		return -2;
	}
	if(f_sign < f_sign2){ printf("-1 return\n");return -1;}
	if(f_sign == f_sign2){ printf("0 return\n");return 0;}
}

int sign(const char op_tor)
{
	switch(op_tor){
	case '+':
		return -1;
	case '-':
		return -1;
	case '*':
		return -2;
	case '/':
		return -2;
	}

}
for(k=operators.top; k>-1; k--){
if(priority(infix[i],&operators, k) == -2){
pop_int(&operators, &out);
postfix[j] = out;
printf("pop\n");
j++;
}
else if(priority(infix[i],&operators, k) == -1){
push_int(&operators, infix[i]);
printf("push\n");
}
}

}*/