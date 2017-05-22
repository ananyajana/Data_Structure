/* Author: Ananya Jana */
#include <stdio.h>

int a[5][5] = {
	   {1, 0, 0, 0, 0}, 
	   {1, 1, 1, 0, 0},
	   {1, 1, 0, 0, 0}, 
	   {1, 1, 1, 1, 1},
	   {0, 0, 0, 0, 0}};

int main()
{
	   int i, j;

	   for(i = 4, j = 4; i == j; --i, --j)
			 if(a[i][j] == 1)
				    break;
	   int c1 = j;
	   int r1 = i;

	   for(i = 0, j = 4; i + j == 4; ++i, --j)
			 if(a[i][j] == 1)
				    break;

	   if(c1 > j)
			 printf("%dth row\n", c1 + 1);
	   else
			 printf("%dth row\n", i + 1);
}
