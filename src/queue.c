/* Author: Ananya Jana */
#include <stdio.h>
#include <stdlib.h>


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

int main()
{
	   q* q1;
	   //printf("Hello");
	   q1 = CreateQueue();
	   //printf("Hello");
	   EnQueue(q1, 10);
	   EnQueue(q1, 11);
	   EnQueue(q1, 12);
	   EnQueue(q1, 13);
	   EnQueue(q1, 14);
	   EnQueue(q1, 15);
	   printf("Hello");
	   printf("%d ", DeQueue(q1));
	   printf("Hello");
	   printf("%d ", DeQueue(q1));
	   printf("%d ", DeQueue(q1));
	   printf("%d ", DeQueue(q1));
	   printf("%d ", DeQueue(q1));
	   printf("%d ", DeQueue(q1));
	   DeleteQueue(q1);
}
