#include <stdio.h>
#include <stdlib.h>

void build_heap_tree(int * array, int n);
void swap(int * a, int * b);
void heap_sort(int * array, int n);

int main(){
    int n, i;
    int * array;
    scanf("%d", &n);
    array = calloc(n, sizeof(int));
    for (i = 0; i < n; i ++) {
        scanf("%d", &array[i]);
    }
    heap_sort(array, n);
    for(i = 0; i < n; i ++){
        printf("%d\t", array[i]);
    }
    return(0);
}

void heap_sort(int * array, int n){
    for(int i = 0; i < n; i ++) {
        build_heap_tree(array, n - i);
        swap(&array[0], &array[n-1-i]);
    }
}

void build_heap_tree(int * array, int n){
    for (int i = 0; i < n; i ++) {
        if (i == 0) {
            continue;
        }else{
            int parent = (i-1)/2;
            if (array[parent] < array[i]){
                swap(&array[parent], &array[i]);
            }
        }
    }
}

void swap(int * a, int * b){
    int c;
    c = * a;
    * a = * b;
    * b = c;
}