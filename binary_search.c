#include <stdio.h>
#include <stdlib.h>

int binary_search(int * array, int start, int end, int key){
    int mid;
    mid = start + (end-start)/2;
    while (start <= end){
        if (array[mid] == key){
            return mid;
        } else if (array[mid] > key){
            end = mid - 1;
            mid = start + (end - start) / 2;
        } else if (array[mid] < key){
            start = mid + 1;
            mid = start + (end - start) / 2;
        }
    }
    return -1;
}

int main(){
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int key = 8;
    int index = binary_search(array, 0, 10, key);
    printf("Index is : %d\n", index);
    return 0;
}