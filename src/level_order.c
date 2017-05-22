/* Author: Ananya Jana */
#include <stdio.h>
#include <stdlib.h>


struct tree
{
	   int info;
	   struct tree* left;
	   struct tree* right;
};

typedef struct tree tr;


struct ListNode
{
	   tr* root1;
	   struct ListNode* next;
};

typedef struct ListNode nd;


struct Queue
{
	   nd* front;
	   nd* rear;
};

typedef struct Queue q;

nd* dummy1;

tr* insert_tree(tr* start, int val)
{
	   if(!start){
			 start = (tr*)malloc(sizeof(tr));
			 start->info = val;
			 //printf("Value assigned\n");
			 start->left = start->right = NULL;
	   }

	   else{
			 if(val < start->info)
				    start->left = insert_tree(start->left, val);
			 else
				    start->right = insert_tree(start->right, val);
	   }

	   return start;
}
	  
void display(tr* start)
{
	   //printf("in display.\n");
	   if(!start){
	//		 printf("Null tree:\n");
			return;	 
	   }

		display(start->left);
	   	printf("%d \n", start->info);
		display(start->right);	
}

void delete_tree(tr* start)
{
	   //printf("In delete:\n");
	   if(!start){
			 //printf("tree null.\n");
			 return;
	   }

	   delete_tree(start->left);
	   delete_tree(start->right);
	   free(start);
}


nd* dummy;

static int i = 0;
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

void  EnQueue(q* q1,tr* tr1) 
{
	   nd* temp;
	   temp = (nd*)malloc(sizeof(nd));
	   temp->root1 = tr1;
	   temp->next = NULL;
	   printf("EnQueueing: %d\n", temp->root1->info);
	   //if(q1->rear != dummy)
	   //printf("In queue: %d\n", q1->rear->root1->info);
	   q1->rear->next = temp;
	   q1->rear = temp;
	   printf("EnQueued: %d\n", q1->rear->root1->info);
	   //q1->rear = temp;
	   if(!q1->front){
			 printf("i = %d ", i++);
			 q1->front = q1->rear;
			 dummy1 = q1->front;
			 free(dummy);
	   }
}

tr* DeQueue(q* q1)
{
	   tr* temp1;
	   nd* temp;
	   printf("Hello");
	   if(IsEmptyQueue(q1)){
			 printf("Queue is empty");
			 return 0;
	   }
	   temp1 = q1->front->root1;
	   printf("DeQueueing: %d\n", temp1->info);
	   temp = q1->front;
	   q1->front = q1->front->next;
	   //free(temp);
	   return temp1;
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

void LevelOrder(q* q1, tr* root)
{
	   tr* temp;
	   //q* q1;
	   if(!root)
			 return;
	   //q1 = CreateQueue();
	   EnQueue(q1, root);
	   while(!IsEmptyQueue(q1)){
			 temp = DeQueue(q1);
			 printf("%d ", temp->info);
			 if(temp->left){
				    printf("left\n");
				    EnQueue(q1, temp->left);
			 }
			 if(temp->right){
				    printf("right\n");
				    EnQueue(q1, temp->right);
			 }
	   }
}

void DeleteAll(nd* nd1)
{
	   nd* temp;
	   while(nd1){
			 printf("%d ", nd1->root1->info);
			 temp = nd1;
			 nd1 = nd1->next;
			 free(temp);
	   }
}

int main()
{
	   q* q1;
	   q1 = CreateQueue();

	tr* start;
	start = NULL;
	start = insert_tree(start, 12);
	start = insert_tree(start, 13);
	start = insert_tree(start, 10);
	start = insert_tree(start, 15);
	start = insert_tree(start, 11);
	start = insert_tree(start, 14);
	display(start);
	LevelOrder(q1, start);
	delete_tree(start);
	   DeleteQueue(q1);
	   DeleteAll(dummy1);
}
