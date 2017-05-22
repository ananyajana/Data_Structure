/* Author: Ananya Jana */
#include <stdio.h>
#include <stdlib.h>


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

int pop(nd** top)
{
	int val = (*top)->info;
	nd* temp;
	temp = *top;
	*top = (*top)->next;
	free(temp);
	return val;
}

void empty_stack()
{
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

	if(stack == NULL)
		printf("The stack is empty\n");
}
