//Sunday 08 January 2017 01:16:13 PM IST 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct list{
	void * type;
	struct list * next;
}Stack;

Stack * base, * _TOS;

/*
* Provides basic datatypes stack like int, float, char, double.
*/

void getCharStack(){
	base = (Stack *)malloc(sizeof(Stack));
	base->next = NULL;
//	(char *)base->type;
	base->type = (char *)malloc(sizeof(char));
	*(char *)base->type = '-'; 
	_TOS = base;
}

bool isStackEmpty(){
	if(base == NULL){
		return true;
	}else{
		return false;
	}
}

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
*  checkParen ... function pushes the '(' [left parentheses] onto the stack and pops it on an encounter of ')' [right parentheses], if there is no element in the stack on ')' paren, then the string of parentheses is not balanced.
*/

bool checkParen(const char * paren, int n){
	int i;
	char c;
	if(paren[0] == ')'){
		return false;
	}
	i = 0;
	while(paren[i] != '\0'){
		if(paren[i] == '('){
			push(paren[i]);
		}else if(paren[i] == ')'){
			if(isStackEmpty()){
				return false;
			}
			c = pop();
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
	printf("Enter any non-zero positive number for parentheses checking code:");
	scanf("%d", &n);
	if(n){
		printf("Enter the size of sequence of parentheses:\n");
		scanf("%d", &cs);
		if(cs%2 == 1){
			printf("You cannot have balanced parentheses with odd number of parentheses!\n");
		}else{
			fflush(stdin);
			paren = (char *)calloc(cs, sizeof(char));
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
