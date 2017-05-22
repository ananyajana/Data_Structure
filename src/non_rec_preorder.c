/* Author: Ananya Jana */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct tree
{
	   int info;
	   struct tree* left;
	   struct tree* right;
};

typedef struct tree tr;

struct node
{
	tr* tr1;
	struct node* next;
};

typedef struct node nd;


nd* create_stack()
{
	return NULL;
}

void push(nd** top, tr* tree)
{
	nd* nd1 = (nd*)malloc(sizeof(nd));
	nd1->tr1 = tree;
	nd1->next = *top;
	*top = nd1; 
}


int empty_stack(nd* start)
{
	return start == NULL;
}

tr* pop(nd** top)
{
	if(empty_stack(*top)){
		printf("Stack empty\n");
		return NULL;
	}
	tr* tree = (*top)->tr1;
	nd* temp;
	temp = *top;
	*top = (*top)->next;
	free(temp);
	return tree;
}


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
		//	 printf("Null tree:\n");
			return;	 
	   }

		display(start->left);
	   	printf("%d \n", start->info);
		display(start->right);	
}

void delete_tree(tr* start)
{
	 //  printf("In delete:\n");
	   if(!start){
	//		 printf("tree null.\n");
			 return;
	   }

	   delete_tree(start->left);
	   delete_tree(start->right);
	   free(start);
}

void print_array(int path[], int pathlen)
{
	   int i;
	   for(i = 0; i < pathlen; ++i)
			 printf("% d", path[i]);
}

void non_rec_pre(tr* root)
{
	   nd* stack; 
	   stack = create_stack();

	   while(1){
			 while(root){
				    printf("%d ", root->info);
				    push(&stack, root);
				    root = root->left;
			 }

			 if(empty_stack(stack))
				    break;
			 
			 root = pop(&stack);
			 root = root->right;
	   }
	   stack = NULL;
}

void print_all(tr* start, int path[], int pathlen)
{
	   if(!start)
			 return;
	   path[pathlen] = start->info;
	   pathlen++;

	   if(start->left == NULL && start->right == NULL)
	   {
			 print_array(path, pathlen);
	   }
	   else{
			 print_all(start->left, path, pathlen);
			 print_all(start->right, path, pathlen);
	   }
}



int main()
{
	int path[1000];
	int pathlen = 0;
	tr* start;
	start = NULL;
	start = insert_tree(start, 12);
	start = insert_tree(start, 13);
	start = insert_tree(start, 10);
	start = insert_tree(start, 11);
	start = insert_tree(start, 9);
	start = insert_tree(start, 15);
	start = insert_tree(start, 14);
	start = insert_tree(start, 16);

	//display(start);
	//print_all(start, path, pathlen);
	non_rec_pre(start);
	delete_tree(start);
}
