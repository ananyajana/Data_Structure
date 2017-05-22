/* Author: Ananya Jana */
#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int a[], int n);

int main()
{
	int i;
	int a[6];
	
	printf("Enter %d numbers.\n", 6);
	for(i = 0; i < 6; ++i)
		scanf(" %d", &a[i]);
	
	insertion_sort(a, 6);

	printf("The sorted array is:\n");
	for(i = 0; i < 6; ++i)
		printf(" %d",a[i]);

	exit(0);
}

void insertion_sort(int a[], int n)
{
	int i, j, key;

	for(j = 1; j < n; ++j){
		key = a[j];
		i = j - 1;
		while(i >= 0 && a[i] > key){
			a[i + 1] = a[i];
			i = i - 1;
		}
		a[i + 1] = key;
	}
}
