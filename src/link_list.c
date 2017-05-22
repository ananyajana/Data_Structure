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
	int c, val;
	nd* newnode;
	printf("Do you want to create a node? ");
	scanf("%d ", &c);
	if(c == 'y'){
		newnode = (nd*)malloc(sizeof(nd));
		if(!start){
			newnode->next = start;
			start = newnode;
		}
		printf("enter data: ");
		scanf("%d ", &val);
		newnode->info  = val;
		newnode->next = NULL;
	}


	printf("hello");

	while((c = getchar()) != 'n'){
		printf("enter data: ");
		scanf(" %d", &val);
		newnode->next = (nd*)malloc(sizeof(nd));
		newnode = newnode->next;
		newnode->info = val;
		newnode->next = NULL;
		printf("Do you want to create another node?y/n");
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



int main()
{
	nd* start;

	start = create_list();
	
	start = add_node(start);

	printf("%d\n", start->info);
	printf("Hello");

	display(start);

	delete_node(start);
}
