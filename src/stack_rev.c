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

void rec_push(nd** top, int data)
{
	   int temp;

	   if(empty_stack(*top)){
			 push(top, data);
			 return;
	   }
	   temp = pop(top);
	   rec_push(top, data);
	   push(top, temp);
}

void rev_stack(nd** top)
{
	   int data;
	   if(empty_stack(*top))
			 return;
	   data = pop(top);
	   rev_stack(top);
	   rec_push(top, data);
}


int main()
{
	int i;
	nd* stack;

	stack = create_stack();
	
	for(i = 0; i < 5; ++i)
		push(&stack, i);

	rev_stack(&stack);
	for(i = 0; i < 5; ++i)
		   printf("%d ", pop(&stack));
}
