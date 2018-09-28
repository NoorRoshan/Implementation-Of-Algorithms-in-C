#include <stdio.h>
#include <stdlib.h>

void merge_array(int * array, int start, int mid, int end){

    int i = start, j = mid+1, k = 0;
    int sub_array[end-start+1];

    while (k < end-start+1 & i <= mid & j <= end) {
        if (array[i] < array[j] & i <= mid) {
            sub_array[k] = array[i];
            k = k + 1;
            i = i + 1;
        } else if (array[i] >= array[j] & j <= end) {
            sub_array[k] = array[j];
            k = k + 1;
            j = j + 1;
        }
    }

    while (i <= mid) {
        sub_array[k] = array[i];
        k = k + 1;
        i = i + 1;
    }

    while (j <= end) {
        sub_array[k] = array[j];
        k = k + 1;
        j = j + 1;
    }

    for (k = 0; k <= end-start; k ++) {
        array[start+k] = sub_array[k];
    }
}

void merge_sort(int * array, int start, int end){
    if (start == end){
        return;
    }else{
        int i;
        int mid = start + (end - start)/2;
        merge_sort(array, start, mid);
        merge_sort(array, mid + 1, end);
        merge_array(array, start, mid, end);
    }
}

int main(){
    int arr[] = {1, -1, 2, -5, 5};
    int i;
    merge_sort(arr, 0, 4);
    for (i = 0; i < 5; i ++) {
        printf("%d\n", arr[i]);
    }
    return 0;
}