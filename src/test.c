/* Author: Ananya Jana */
#include <stdio.h>

int g(int i)
{
	   i = i++ || i-- && i++;
	   i >> 1;
	   return i;
}


int main()
{
	   int i = 0, j = 4;
	   for(; printf("hello"), i > j ? 0 : j; i++, j--)
			 printf("%d ", g(i));
}

