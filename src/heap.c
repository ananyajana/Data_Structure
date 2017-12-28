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

#define PARENT(i)	((i - 1)/2)
#define LEFT(i)		(2*i + 1)
#define	RIGHT(i)	(2*i + 2)

void max_heapify(int a[], int i);
void build_max_heap(int a[]);	

//heap size
int size;

int main()
{
	int i;
	int *arr = NULL;
	
	//take user input: size of the array
	printf("Enter the heap size: ");
	scanf("%d", &size);
	
	//create a dynamic array of size n
	arr = (int*)malloc(size*sizeof(int));
	
	//take input the individual elements
	printf("Enter the heap elements:\n");
	for(i = 0; i < size; ++i){
		scanf("%d", &arr[i]);
	}
	for(i = 0; i < size; ++i){
		printf("%d ", arr[i]);
	}
	
	//build max heap with the user input elements
	build_max_heap(arr);	
	
	free(arr);
}

void build_max_heap(int a[])
{
	int i;
	for(i = (size - 1)/2; i >= 0; --i)
		max_heapify(a, i);
}

void max_heapify(int a[], int i)
{
	int l, r, largest, temp;
	l = LEFT(i);
	r = RIGHT(i);
	
	if((l < size) && (a[l] > a[i]))
		largest = l;
	else
		largest = i;
	if((r < size) && ( a[r] > a[largest]))
		largest = r;
	if(largest != i){
		temp = a[largest];
		a[largest] = a[i];
		a[i] = temp;
	}
	
	max_heapify(a, largest);
}