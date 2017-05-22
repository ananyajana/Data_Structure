/* Author: Ananya Jana */
#include <stdio.h>
#include <string.h>

void permutations(int depth, char* permutation, int* used, char* original)
{
	int length = strlen(original);
	if(depth == length){
		printf("%s", permutation);
	}
	else{
		for(int i = 0; i < length; ++i){
			if(!used[i]){
				used[i] = 1;
				permutation[depth] = original[i];
				permutations(depth + 1, permutations, used, original);
				used[i] = 0;
			}
		}
	}
}

int main()
{
	char orig[6] = "abcde";
	char perm[6];
	int used[6];
	permutations(0, perm, used, orig);
}
