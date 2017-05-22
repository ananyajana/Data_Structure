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

int FindMax(tr* root)
{
	while(root->right)
		root = root->right;
	return root->info;
}

int FindMin(tr* root)
{
	while(root->left)
		root = root->left;
	return root->info;
}

int IsBst(tr* root)
{
	if(root == NULL)
		return 1;
	if(root->left != NULL && FindMax(root->left) > root->info)
		return 0;
	if(root->right != NULL && FindMin(root->right) < root->info)
		return 0;
	if(!IsBst(root->left) || !IsBst(root->right))
		return 0;
	return 1;
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
	printf("The max value %d\n", FindMax(start));
	display(start);
	printf("The min value %d\n", FindMin(start));
	if(IsBst(start))
		printf("It's a BST");
	else
		printf("It's not a BST");
	delete_tree(start);
}
