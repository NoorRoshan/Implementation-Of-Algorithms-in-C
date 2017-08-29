/* @author: Tanisha R. Bhayani.
* Question : Describe a theta(n lg n)-time algorithm that, given a set S of n integers and another integer x, determines whether or not there exist two elements in S whose sum is exactly x.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool sum_in_array(int * array, int size_of_array, int sum_to_find);
bool divide(int * array, int low, int high, int sum_to_find);

int main(){
    int n, * array, i, x;
    bool sum;
    printf("Enter n: ");
    scanf("%d", &n);
    array = (int *)calloc(n, sizeof(int));
    printf("Enter the value of each element: ");
    for(i = 0; i < n; i ++){
        scanf("%d", &array[i]);
    }
    printf("Enter x, the sum of two elements of which is to be found in the array: ");
    scanf("%d", &x);
    sum = sum_in_array(array, n-1, x);
    printf("Result of sum in array is: %d", sum);
}

bool sum_in_array(int * a, int n, int x){
    bool result;
    result = divide(a, 0, n, x);
    return result;
}

bool divide(int * a, int l, int h, int x){
    if(h < l){
        return false;
    }
    if(h-l+1 == 2){
        return (a[l] + a[h] == x);
    }else{
        bool r1, r2;
        int m;
        m = (h-l)/2;
        r1 = divide(a, l, m, x);
        r2 = divide(a, m+1, h, x);
        return r1 | r2;
    }
}