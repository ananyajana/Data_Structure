/* Implementing Max-heap, Min-heap 
Routines for Max-heap
Max-Heapify - O(log n)
Build Max-heap - linear
Heap sort - O(nlog n)
Max-heap insert, 
Heap-extract max
Heap-increase-key
Heap-maximum - O(log n)
*/

// creating a rudimentary heap(
 
#include <stdio.h>
#include <stdlib.h>

#define PARENT(i)	(i/2)
#define LEFT(i)		(2*i)
#define	RIGHT(i)	(2*i + 1)

void max_heapify(int a[], int n, int i);
void build_max_heap(int a[], int n);	


int main()
{
	int n, i;
	int *arr = NULL;
	
	//take user input: size of the array
	printf("Enter the heap size: ");
	scanf("%d", &n);
	
	//create a dynamic array of size n
	arr = (int*)malloc(n*sizeof(int));
	
	//take input the individual elements
	printf("Enter the heap elements:\n");
	for(i = 0; i < n; ++i){
		scanf("%d", &arr[i]);
	}
	for(i = 0; i < n; ++i){
		printf("%d ", arr[i]);
	}
	
	//build max heap with the user input elements
	build_max_heap(arr, n);	
	
	free(arr);
}

void build_max_heap(int a[], int n)
{
	int i;
}