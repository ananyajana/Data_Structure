/* Author: Ananya Jana */
#include <stdio.h>
#include <stdlib.h>
#include "ins_sort.h"

int main()
{
	int i, n;
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
