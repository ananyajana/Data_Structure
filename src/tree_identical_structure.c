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

int AreStructurallyIdentical(tr* root1, tr* root2)
{
	   if(root1 == NULL && root2 == NULL)
			 return 1;
	   if(root1 == NULL || root2 == NULL)
			 return 0;
	   return(AreStructurallyIdentical(root1->left,root2->left) && AreStructurallyIdentical(root1->right, root2->right));
}

int main()
{
	tr* start;
	start = NULL;
	start = insert_tree(start, 12);
	start = insert_tree(start, 13);
	start = insert_tree(start, 10);
	start = insert_tree(start, 15);
	start = insert_tree(start, 11);
	start = insert_tree(start, 14);

	tr* start1;
	start1 = NULL;
	start1 = insert_tree(start1, 12);
	start1 = insert_tree(start1, 13);
	start1 = insert_tree(start1, 10);
	start1 = insert_tree(start1, 15);
	start1 = insert_tree(start1, 11);
//start1 = insert_tree(start1, 14);
	display(start);
	display(start1);
	if(AreStructurallyIdentical(start, start1))
		   printf("Both are structurally identical\n");
	else
		   printf("Not structurally identical\n");
	delete_tree(start1);
	delete_tree(start);
}
