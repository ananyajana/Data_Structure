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


tr* insert_tree(tr* start, int val)
{
	   if(!start){
			 start = (tr*)malloc(sizeof(tr));
			 start->info = val;
			 printf("Value assigned\n");
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
	   printf("in display.\n");
	   if(!start){
			 printf("Null tree:\n");
			return;	 
	   }

		display(start->left);
	   	printf("%d \n", start->info);
		display(start->right);	
}

void delete_tree(tr* start)
{
	   printf("In delete:\n");
	   if(!start){
			 printf("tree null.\n");
			 return;
	   }

	   delete_tree(start->left);
	   delete_tree(start->right);
	   free(start);
}
int FindMax(tr* root)
{
	   int root_val, left, right, max;
	   max = INT_MIN;

	   if(root){
			 root_val = root->info;
			 left = FindMax(root->left);
			 right = FindMax(root->right);

			 if(left > right)
				    max = left;
			 else
				    max = right;
			 if(root_val > max)
				    max = root_val;
	   }
	   return max;
}
				    
int main()
{
	   int max;
	tr* start;
	start = NULL;
	start = insert_tree(start, 12);
	start = insert_tree(start, 13);
	start = insert_tree(start, 10);
	start = insert_tree(start, 15);
	start = insert_tree(start, 11);
	start = insert_tree(start, 14);
	printf("Hello\n");
	max = FindMax(start);
	printf("max value = %d\n", max);
	display(start);
	delete_tree(start);
}
