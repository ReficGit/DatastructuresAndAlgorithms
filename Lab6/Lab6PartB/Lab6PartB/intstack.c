#include "intstack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void infixTopostfix(char *infix,char *postfix);
int priority(char op_tor,const Tintstack *op_tors, int top);
int evaluatepostfix(char *postfix);

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

	//Go through each character in the string
	for(i=0; i<strlen(infix);i++){	
		//If it is between 0 to 9, append it to output string.
		if ((infix[i] >= '0') && (infix[i] <= '9')){
			postfix[j] = infix[i];
			j++;
		}
		//If it is left brace push to stack
		else if(infix[i] == '('){
			push_int(&operators, infix[i]);
		}
		//If it is operator *+-/ then 
		else if(sign(infix[i]) == -1 || sign(infix[i]) == -2) {	
			// If the stack is empty push it to the stack
			if(is_empty_int_stack(&operators)){						
				push_int(&operators, infix[i]);
			}
			// If the stack is not empty then start a loop:
			else if(!(is_empty_int_stack(&operators))){   
				/* If the top of the stack has higher precedence
                 * Then pop and append to output string
                 * Else break
				 * Push to the stack
                 */ 
				for(k = operators.top;k>-1; --k){
					if((priority(infix[i], &operators, k) == -2)){ 
						pop_int(&operators, &out);
						postfix[j] = out;
						j++;
					}
					else break;
				}
				push_int(&operators, infix[i]);
			}
		}
		 // If it is right brace then
		else if(infix[i] == ')'){
			 /* While stack not empty and top not equal to left brace
			  * Pop from stack and append to output string
			  * Finally pop out the left brace.
			  */
			 while(!(is_empty_int_stack(&operators)) && operators.array[operators.top] != '('){
				pop_int(&operators, &out);
				postfix[j] = out;
				j++;
			 }
			 pop_int(&operators, &out);
		 }
	}
	//Append all the left operators
	for(i=operators.top; i>-1;i--){			
		pop_int(&operators, &out);
		postfix[j] = out;
		j++;
	}

	for(i = 0; i<strlen(postfix);i++){
		printf("%c", postfix[i]);
	}
	evaluatepostfix(postfix);
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
	*/
	if(f_sign > f_sign2){
		return -2;
	}
	//if(f_sign < f_sign2){ printf("-1 return\n");return -1;}
	//if(f_sign == f_sign2){ printf("0 return\n");return 0;}
	return 0;
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
	default:
		return 0;
	}

}

int evaluatepostfix(char *postfix)
{
	Tintstack answer;
	int i = 0;
	int left = 0, right = 0;
	initialize_int_stack(&answer);

	for(i=0;i<strlen(postfix);i++){
		if((postfix[i] >= '0') && (postfix[i] <= '9')){
			push_int(&answer, (postfix[i]-'0'));
			//printf("%d", answer.array[i]);
		}
		else {
			switch(sign_for_evaluate(postfix[i])){
			case -1:
				pop_int(&answer, &right);
				pop_int(&answer, &left);
				push_int(&answer, ((left+right)));
				break;
			case -2:
				pop_int(&answer, &right);
				pop_int(&answer, &left);
				push_int(&answer, ((left)-(right)));
				break;
			case -3:
				pop_int(&answer, &right);
				pop_int(&answer, &left);
				push_int(&answer, ((left)*(right)));
				break;
			case -4:
				pop_int(&answer, &right);
				pop_int(&answer, &left);
				push_int(&answer, ((left)/(right)));
				break;
			}
			
		}
		
	}
	print_int_stack(&answer);
	return(0);
}

int sign_for_evaluate(const char op_tor)
{
	switch(op_tor){
	case '+':
		return -1;
	case '-':
		return -2;
	case '*':
		return -3;
	case '/':
		return -4;
	}
	return 0;
}