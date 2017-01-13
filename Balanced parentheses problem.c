#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct list{
	void * type;
	struct list * next;
}Stack;

Stack * base, * _TOS = NULL;

/*
* Provides basic datatypes stack like int, float, char, double.
*/

void getCharStack(){
	base = (Stack *)malloc(sizeof(Stack));
	base->next = NULL;
//	(char *)base->type;
	base->type = (char *)malloc(sizeof(char));
	*(char *)base->type = '-'; 
}

/* old push(char)
*  assumes that getCharStack() is called and base is already initialized.
*/

void push(char c){
	Stack * t = (Stack *)malloc(sizeof(Stack));
	if(base == NULL){
		t->next = base;
		base = t;
	}else{
		t->next = _TOS;
	}
	_TOS = t;
//	(char *)t->type;
	t->type = (char *)malloc(sizeof(char));
	*(char *)t->type = c;
}

bool isStackEmpty(){
	if(base == NULL){
		return true;
	}else{
		return false;
	}
}

char pop(){
	if(base == NULL){
		return('-');
	}
	char c;
	Stack * t = _TOS;
	if(_TOS != base){
		_TOS = _TOS->next;
	}else{
		_TOS = NULL;
		base = NULL;
	}
	c = *(char *)t->type;
	free(t);
	return(c);
}

/*
*	checkParen ... function pushes the '(', '[', '{' [left parentheses] onto the stack and pops it on an encounter of *   corresponding ')', ']', '}' [right parentheses], if there is no element in the stack on ')', ']', '}' paren or the *   parentheses poped does not match, then the string of parentheses is not balanced.
*   Matching is done by the fact that '(', ')', '[', ']', '{', '}' have ASCII value of 40, 41, 90, 91, 93, 123, 125 - so *   the difference between the braces is 1 or 2, and between different parens it is much greater than 2.
*/

bool checkParen(const char * paren, int n){
	int i;
	char c;
	const int TWO = 2;
		
//	getCharStack();
		
	i = 0;

	while(i < n){
		
		if(paren[i] == '(' || paren[i] == '[' || paren[i] == '{'){
	
			push(paren[i]);
			
		}else if(paren[i] == ')' | paren[i] == ']' | paren[i] == '}'){

			if(isStackEmpty()){
				return false;
			}

			c = pop();

			if(paren[i] - c > TWO){
				return false;
			}
		}
		++i;
	}

	if(isStackEmpty()){
		return true;
	}else{
		return false;
	}

}

int main(){

	int n, cs, i;
	char * paren;
	
	printf("Enter any non-zero positive number for parentheses checking code segment to run:");
	scanf("%d", &n);
	
	if(n){
		
		printf("Enter the size of sequence of parentheses:\n");
		scanf("%d", &cs);
		
		getc(stdin);
		
		if(cs%2 == 1){
			printf("You cannot have balanced parentheses with odd number of parentheses!\n");
		}else{
			
			paren = (char *)calloc(cs + 1, sizeof(char));
		
			i = 0;
			
			while(i <= cs){
				scanf("%c", &paren[i]);
				++i;
			}
			
			if(checkParen(paren, cs)){
				printf("The sequence is a balanced parentheses sequence.\n");
			}else{
				printf("The sequence is not a balanced parentheses sequence.\n");
			}
		}
	}
}
