#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(){
    int n, * array, i, j, max, so_far_max;
    int start, end, sum_final;

    printf("Enter the size of array:\n");
    scanf("%d", &n);

    array = (int *)calloc(n, sizeof(int));

    printf("Enter the value of each element of the array.\n");

    for(i = 0; i < n; i ++){
        scanf("%d", &array[i]);
    }
    
    max = INT_MIN;
    so_far_max = INT_MIN;
    start = 0;
    end = 0;

    for(i = 0 ; i < n; i ++){
        max = array[i];
        if(so_far_max < max){
            so_far_max = max;
            start = i;
            end = i;
        }
        for(j = i + 1; j < n; j ++){
            max = max + array[j];
            if(so_far_max < max){
                so_far_max = max;
                end = j;
            }
        }
    }

    printf("start: %d, end: %d, sum: %d\n", start, end, so_far_max);

    free(array);

    return (0);
}