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

/*int PrintAllAncestors(tr* root, tr* nd)
{
	if(!root)
		return 0;
	if(root->left == node || root->right == node || PrintAllAncestors(root->left, node) || PrintAllAncestors(root->right, node)){
		printf("%d\n", root->data);
		return 1;
	}
	return 0;
}
*/

/*
int PrintAllAncestors(tr* root, int data)
{
	if(!root)
		return 0;
	if((root->left) && root->left->info == data || root->right && root->right->info == data || PrintAllAncestors(root->left, data) || PrintAllAncestors(root->right, data)){
		printf("all ancestors:\n");
		printf("%d\n", root->info);
		return 1;
	}
	return 0;
}
*/

int PrintAllAncestors(tr* root, int data)
{
	if(!root)
		return 0;
	if(root->info == data){
		printf("all ancestors\n");
		printf("%d\n", root->info);
		return 1;
	}

	if(root->left && PrintAllAncestors(root->left, data) || root->right && PrintAllAncestors(root->right, data)){
		printf("all ancestors:\n");
		printf("%d\n", root->info);
		return 1;
	}
	return 0;
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
	display(start);
	PrintAllAncestors(start, 15);
	delete_tree(start);
}
