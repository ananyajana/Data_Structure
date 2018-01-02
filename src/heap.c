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

 
#include <stdio.h>
#include <stdlib.h>

#define PARENT(i)	((i - 1)/2)
#define LEFT(i)		(2*i + 1)
#define	RIGHT(i)	(2*i + 2)

void max_heapify(int a[], int i);
void build_max_heap(int a[]);
void heap_sort(int a[]);

//heap sz
int size, sz;

int main()
{
	int i;
	int *arr = NULL;
	
	//take user input: sz of the array
	printf("Enter the heap size: ");
	scanf("%d", &sz);
	size = sz;
	
	//create a dynamic array of size n
	arr = (int*)malloc(sz*sizeof(int));
	
	//take input the individual elements
	printf("Enter the heap elements:\n");
	for(i = 0; i < size; ++i){
		scanf("%d", &arr[i]);
	}
	for(i = 0; i < size; ++i){
		printf("%d ", arr[i]);
	}
	
	//perform heap sort on the array
	heap_sort(arr);
	
	//printing the sorted aray
	for(i = 0; i < size; ++i){
		printf("%d ", arr[i]);
	}
	
	//free the dynamic array
	free(arr);
}

void build_max_heap(int a[])
{
	int i;
	for(i = (sz - 1)/2; i >= 0; --i){
		printf("i = %d\n", i);
		max_heapify(a, i);
	}	
}

void max_heapify(int a[], int i)
{
	int l, r, largest, temp;
	l = LEFT(i);
	r = RIGHT(i);

	printf("%d %d\n", a[i], i);	
		
	if((l < sz) && (a[l] > a[i]))
		largest = l;
	else
		largest = i;
	if((r < sz) && ( a[r] > a[largest]))
		largest = r;
	if(largest != i){
		temp = a[largest];
		a[largest] = a[i];
		a[i] = temp;
		printf("hi\n");
		for(i = 0; i < size; ++i){
			printf("%d ", a[i]);
		}
		printf("\n");
		max_heapify(a, largest);
	}	
}

void heap_sort(int a[])
{
	int i, temp;
	
	build_max_heap(a);
	printf("The heap is\n");
	for(i = 0; i < size; ++i){
		printf("%d ", a[i]);
	}
	printf("\n");
	
	//place the biggest element which is at the root, at the end of the array
	for(i = sz - 1; (i >= 1) && (sz > 1); --i){
		temp = a[0];
		a[0] = a[i];
		a[i] = temp;

		printf("hi1\n");
		for(i = 0; i < size; ++i){
			printf("%d ", a[i]);
		}
		printf("\n");
		//reduce the size of the heap as we removed the largest element
		--sz;
	
		//create a heap out of the remaining elements in the heap
		max_heapify(a, 0);
	}
}