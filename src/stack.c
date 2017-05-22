/* Author: Ananya Jana */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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

void push(nd** top, int val)
{
	nd* nd1 = (nd*)malloc(sizeof(nd));
	nd1->info = val;
	nd1->next = *top;
	*top = nd1; 
}


int empty_stack(nd* start)
{
	return start == NULL;
}

int pop(nd** top)
{
	if(empty_stack(*top)){
		printf("Stack empty\n");
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
	int i;
	nd* stack;

	stack = create_stack();
	
	for(i = 0; i < 5; ++i)
		push(&stack, i);

	for(i = 0; i < 5; ++i)
		printf("%d ", pop(&stack));

	if(empty_stack(stack))
		printf("The stack is empty\n");
	pop(&stack);
}
