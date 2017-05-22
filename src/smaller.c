/* Author: Ananya Jana */
#include <stdio.h>

int main()
{
	   int x = 9, y = 24;

	   int min;

	   min = y ^ ((x ^ y) & -(x < y));

	   printf("min = %d\n", min);
}
