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

tr* MakeMirror(tr* root)
{
	tr* temp;
	if(root){
		root->left = MakeMirror(root->left);
		root->right = MakeMirror(root->right);
		temp = root->left;
		root->left = root->right;
		root->right = temp;
	}
	return root;
}

int AreMirror(tr* root1, tr* root2)
{
	if(root1 == NULL && root2 == NULL)
		return 1;
	if(root1 == NULL || root2 == NULL)
		return 0;
	//if(root1->info != root2->info) for exact mirrors includeing data check
	//	return 0;
	else
		return(AreMirror(root1->left, root2->right) && AreMirror(root1->right, root2->left));
}

int IsSymmetrical(tr* root)
{
	if(!root)
		return 1;
	else 
		return(AreMirror(root->left, root->right));
}

int main()
{
	tr* start;
	//tr* start1;
	start = NULL;
	start = insert_tree(start, 12);
	start = insert_tree(start, 14);
	start = insert_tree(start, 10);
	start = insert_tree(start, 11);
	start = insert_tree(start, 13);
	display(start);
	if(IsSymmetrical(start))
		printf("Symmetrical\n");
	else
		printf("Not symmetrical\n");	
	delete_tree(start);
}
