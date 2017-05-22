/* Author: Ananya Jana */
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int info;
	struct node* next;
};


typedef struct node nd;



nd* create_list()
{
	return NULL;
}

nd* add_node(nd* start)
{
	int val;
	char c;
	nd* newnode;
	printf("Do you want to create a node? ");
	scanf(" %c", &c);
	fflush(stdin);
	if(c == 'y'){
		newnode = (nd*)malloc(sizeof(nd));
		if(!start){
			newnode->next = start;
			start = newnode;
		}
		printf("enter data: ");
		scanf("%d ", &val);
		fflush(stdin);
		newnode->info  = val;
		newnode->next = NULL;
	}


	printf("hello");

	while(c != 'n'){
		printf("enter data: ");
		scanf(" %d", &val);
		fflush(stdin);
		newnode->next = (nd*)malloc(sizeof(nd));
		newnode = newnode->next;
		newnode->info = val;
		newnode->next = NULL;
		printf("Do you want to create another node?y/n");
		scanf("%c ", &c);
		fflush(stdin);
	}
	
	return start;
}

void display(nd* start)
{
	while(start){
		printf("%d\n", start->info);
		start = start->next;
	}
}

void delete_node(nd* start)
{
	nd* temp;
	while(start){
		printf("hi\n");
		temp = start;
		start = start->next;
		free(temp);
	}
	printf("Hello all deleted\n");
}

nd* rev_node_iter(nd* node)
{
	   nd* temp;
	   nd* prev;
	   prev = NULL;
	   while(node){
			 temp = node->next;
			 node->next = prev;
			 prev = node;
			 node = temp; 
	   }
	   return prev;
}


int main()
{

	nd* temp;
	nd* start;   

	start = create_list();
	
	start = add_node(start);

	printf("Hello");

	display(start);

	start = rev_node_iter(start);

	printf("reversed.\n");

	display(start);

	delete_node(start);
}
