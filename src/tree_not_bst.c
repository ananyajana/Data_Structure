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

tr* BuildBST(int a[], int left, int right)
{
	tr* newnode;
	int mid;
	if(left > right)
		return NULL;

	newnode = (tr*)malloc(sizeof(tr));

	if(!newnode){
		printf("Memory Error\n");
		return NULL;
	}
	if(left == right){
		newnode->info = a[left];
		newnode->left = newnode->right = NULL;
	}
	else{
		mid = (left + right) / 2;
		newnode->info = a[mid];
		newnode->left = BuildBST(a, left, mid - 1);
		newnode->right = BuildBST(a, mid + 1, right);
	}
	return newnode;
}


int main()
{
	tr* start;
	start = NULL;
	int a[6] = {4, 2, 3, 1, 5, 6};
	/*
	start = insert_tree(start, 12);
	start = insert_tree(start, 13);
	start = insert_tree(start, 10);
	start = insert_tree(start, 15);
	start = insert_tree(start, 11);
	start = insert_tree(start, 14);
	*/
	start = BuildBST(a, 0, 5);
	display(start);
	delete_tree(start);
}
