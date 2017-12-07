#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int max_lis_length(int * array, int cap){
	int max = -1;
	for(int i = 0; i <= cap; i ++){
		if(max <= array[i]){
			max = array[i];
		}
	}
	return max;
}

void printLIS(int * array, int sizeofarray){
	int * lis_length = (int *)calloc(sizeofarray, sizeof(array[sizeofarray-1]));
	int total_elements = 0;
	for(int i = 0; i < sizeofarray; i ++){
		lis_length[i] = 1;
	}
	// optimal substructure and tabulation.
	for(int i = 1; i < sizeofarray; i ++){
		if(array[i] > array[i-1]){
			lis_length[i] = 1 + max_lis_length(lis_length, i-1);
		}
	}
	total_elements = lis_length[sizeofarray - 1];
	printf("Length of LIS: %d\n", total_elements);
	if(total_elements == 1){
		printf("The longest increasing subsequences are : ");
		for (int i = 0; i < sizeofarray; i ++) {
			printf("{%d} ", array[i]);
		}
		printf("\n");
	}else{
		printf("The longest increasing subsequence is : {");
		int j = 1;
		for(int i = 0; i < sizeofarray; i ++){
			if(lis_length[i] == j){
				printf("%d, ", array[i]);
				j ++;
			}
		}
		printf("\b\b}\n");
	}
	free(lis_length);
}

int main(){
	int n, * array;
	int i;
	scanf("%d", &n);
	array = (int *)calloc(n, sizeof(int));
	for(i = 0; i < n; i ++){
		scanf("%d", &array[i]);
	}
	// prints in the function the result
	printLIS(array, n);
	free(array);
	return (0);
}