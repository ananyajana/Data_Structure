/* Author: Ananya Jana */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct ListNode
{
	   int info;
	   struct ListNode* next;
};

struct Queue
{
	   struct ListNode* front;
	   struct ListNode* rear;
};

typedef struct Queue q;
typedef struct ListNode nd;

nd* dummy;

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

q* CreateQueue()
{
	   q* q1;
	   q1 = (q*)malloc(sizeof(q));
	   dummy = (nd*)malloc(sizeof(nd));
	   if(!q1)
			 return NULL;
	   q1->front = NULL;
	   q1->rear = dummy;
	   dummy->next = NULL;
	   return q1;
}

int IsEmptyQueue(q* q1)
{
	   return q1->front == NULL;
}

void  EnQueue(q* q1, int data)
{
	   nd* temp;
	   temp = (nd*)malloc(sizeof(nd));
	   temp->info = data;
	   temp->next = NULL;
	   q1->rear->next = temp;
	   q1->rear = temp;
	   if(!q1->front){
			 q1->front = q1->rear;
			 free(dummy);
	   }
}

int DeQueue(q* q1)
{
	   int data;
	   nd* temp;
	   if(IsEmptyQueue(q1)){
			 printf("Queue is empty");
			 return 0;
	   }
	   data = q1->front->info;
	   temp = q1->front;
	   q1->front = q1->front->next;
	   free(temp);
	   return data;
}

void DeleteQueue(q* q1)
{
	   nd* temp;
	   while(q1->front){
			 temp = q1->front;
			 q1->front = q1->front->next;
			 free(temp);
	   }
	   //free(q1->rear);
	   free(q1);
}

void rev_queue(q* q1)
{
	   nd* stack =create_stack();
	   while(!IsEmptyQueue(q1))
			 push(&stack, DeQueue(q1));
	   while(!empty_stack(stack))
			 EnQueue(q1, pop(&stack));
}

int main()
{
	   q* q1;
	   q1 = CreateQueue();
	   EnQueue(q1, 10);
	   EnQueue(q1, 11);
	   EnQueue(q1, 12);
	   EnQueue(q1, 13);
	   EnQueue(q1, 14);
	   EnQueue(q1, 15);
	  /* printf("%d ", DeQueue(q1));
	   printf("%d ", DeQueue(q1));
	   printf("%d ", DeQueue(q1));
	   printf("%d ", DeQueue(q1));
	   printf("%d ", DeQueue(q1));
	   printf("%d ", DeQueue(q1));
	   EnQueue(q1, 10);
	   EnQueue(q1, 11);
	   EnQueue(q1, 12);
	   EnQueue(q1, 13);
	   EnQueue(q1, 14);
	   EnQueue(q1, 15);*/
	   rev_queue(q1);
	   printf("%d ", DeQueue(q1));
	   printf("%d ", DeQueue(q1));
	   printf("%d ", DeQueue(q1));
	   printf("%d ", DeQueue(q1));
	   printf("%d ", DeQueue(q1));
	   printf("%d ", DeQueue(q1));
	   DeleteQueue(q1);
}
