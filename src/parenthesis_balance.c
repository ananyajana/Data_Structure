/* Author: Ananya Jana */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


struct node
{
	int info;
	struct node* next;
};

typedef struct node nd;


nd* create_stack()
{
	return NULL;
}

int empty_stack(nd* stack)
{
	   return stack == NULL;
}

void push(nd** top, int val)
{
	nd* nd1 = (nd*)malloc(sizeof(nd));
	nd1->info = val;
	nd1->next = *top;
	*top = nd1; 
}

int pop(nd** top)
{
	if(empty_stack(*top)){
		   printf("stack empty\n");
		   return INT_MIN;
	}

	int val = (*top)->info;
	nd* temp;
	temp = *top;
	*top = (*top)->next;
	free(temp);
	return val;
}


int main()
{
	int i, c;
	nd* stack;

	stack = create_stack();

	while((c = getchar()) != '@'){
		switch(c){
			case '(':
			case '{':
			case '[':
				 push(&stack, c);
				 break;

			case ')':
			case '}':
			case ']':
				 i = pop(&stack);
				 if((i + 1 == c) || (i + 2 == c))
					    printf("%c matched with %c\n", i, c);
				 else
					    printf("Error: not matched\n");
				 break;

			default:
				 break;
		}
	}

	if(!empty_stack(stack)){
		   printf("Error: all parentheses not matched\n");
		   printf("%c remained.\n", pop(&stack));
		   return 1;
	}
	return 0;
}
