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

int FindInBinaryTree(tr* root, int data)
{
	   int temp;

	   if(root == NULL)
			 return 0;
	   else{
			 if(data == root->info)
				    return 1;
			 else{
				    temp = FindInBinaryTree(root->left, data);
				    if(temp != 0)
						  return temp;
				    else return FindInBinaryTree(root->right, data);
			 }
	   }
	   return 0;
}

int main()
{
	tr* start;
	int flag;
	start = NULL;
	start = insert_tree(start, 12);
	start = insert_tree(start, 13);
	start = insert_tree(start, 10);
	start = insert_tree(start, 15);
	start = insert_tree(start, 11);
	start = insert_tree(start, 14);
	flag = FindInBinaryTree(start, 14);
	if(flag)
		   printf("found\n");
	else
		   printf("Not found\n");
	display(start);
	delete_tree(start);
}
