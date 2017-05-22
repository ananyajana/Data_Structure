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

tr* LCA(tr* root, int data1, int data2)
{
	while(1){
		if(data1 <= root->info && root->info <= data2 || data2 <= root->info && root->info <= data1)
			return root;
		else if(data1 < root->info)
			root = root->left;
		else
			root = root->right;
	}
}

int main()
{
	tr* start;
	tr* temp;	
	start = NULL;
	start = insert_tree(start, 12);
	start = insert_tree(start, 13);
	start = insert_tree(start, 10);
	start = insert_tree(start, 15);
	start = insert_tree(start, 11);
	start = insert_tree(start, 14);
	//temp = LCA(start, 10, 15);
	temp = LCA(start, 1, 15);
	if(temp)
		printf("LCA: %d\n", temp->info);
	else
		printf("no LCA\n");
	display(start);
	delete_tree(start);
}
