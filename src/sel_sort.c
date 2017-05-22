/* Author: Ananya Jana */
#include "sel_sort.h"

void selection_sort(int a[], int n)
{
	int i, j, temp;

	for(j = 0; j < n - 1; ++j){
		for(i = j + 1; i < n; ++i){
			if(a[j] > a[i]){
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
