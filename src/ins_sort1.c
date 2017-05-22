/* Author: Ananya Jana */
#include "ins_sort.h"

void insertion_sort(int a[], int n)
{
	int i, j, key;

	for(j = 1; j < n; ++j){
		key = a[j];
		i = j - 1;
		while(i >= 0 && a[i] < key){
			a[i + 1] = a[i];
			i = i - 1;
		}
		a[i + 1] = key;
	}
}
