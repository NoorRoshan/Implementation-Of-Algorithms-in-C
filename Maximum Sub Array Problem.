#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

int l_start = 0, l_end = 0, r_start = 0, r_end = 0, c_start = 0, c_end = 0, start = 0, end = 0;
int left_sum = 0, right_sum = 0, cross_sum = 0, sum = 0, m_start, m_end, m_sum;

void getElements(int * A, int n);
void maxSubCrossArray(int * A, int low, int mid, int high);
void maxSubArray(int * A, int low, int high);
void printm() { printf("m_start = %d\tm_end = %d\tm_sum = %d\n", m_start, m_end, m_sum);}
void printl() { printf("l_start = %d\tl_end = %d\tleft_sum = %d\n", l_start, l_end, left_sum);}
void printr() { printf("r_start = %d\tr_end = %d\tright_sum = %d\n", r_start, r_end, right_sum);}
void printc() { printf("c_start = %d\tc_end = %d\tcross_sum = %d\n", c_start, c_end, cross_sum);}
void print() { printf("start = %d\tend = %d\tsum = %d\n", start, end, sum);}


int main(void){
    int * A, n, i;

    printf("Enter the number of elements in the array:");
    scanf("%d", &n);
    A = (int *)calloc(n, sizeof(int));
    getElements(A, n);

    maxSubArray(A, 0, n - 1);

    printf("The maximum sub array is :\n");
    for( i = start; i <= end; i ++){
        printf("Array[%d] = %d\n", i, A[i]);
    }
    printf("With the maximum sum = %d\n", sum);

    return(0);
}

void getElements(int * A, int n) {
    int i;
    printf("Enter the elements of the array:\n");
    for( i = 0; i < n; i ++ ) {
        printf("Array[%d] = ", i);
        scanf("%d", &A[i]);
    }
}

void maxSubArray(int * A, int low, int high){
    int mid;
    if( low == high ){
        m_start = low, m_end = high, m_sum = A[low];
        printm();
    }
    else{
        mid = floor( ( high + low ) / 2 );
        printm();
        maxSubArray(A, low, mid);
        l_start = m_start, l_end = m_end, left_sum = m_sum;
        printm();
        printl();
        maxSubArray(A, mid + 1, high);
        r_start = m_start, r_end = m_end, right_sum = m_sum;
        printm();
        printr();
        maxSubCrossArray(A, low, mid, high);
        c_start = m_start, c_end = m_end, cross_sum = m_sum;
        printm();
        printc();
        if( left_sum >= sum && left_sum >= right_sum && left_sum >= cross_sum ) {
            start = l_start, end = l_end, sum = left_sum;
           // print();
        }
        //printm();
        //printm();
        else if ( right_sum >= sum && right_sum >= left_sum && right_sum >= cross_sum ) {
            start = r_start, end = r_end, sum = right_sum;
            //print();
        }
        //printm();
        else if( cross_sum >= sum && cross_sum >= left_sum && cross_sum >= right_sum ){
            start = c_start, end = c_end, sum = cross_sum;
        }
        printm();
        printl();
        printr();
        printc();
        print();
        m_start = start, m_end = end, m_sum = sum;
    }
}

void maxSubCrossArray(int * A, int low, int mid, int high) {
    int c_sum, l_sum, r_sum, i, s, e;
    c_sum = 0;
    l_sum = INT_MIN;
    r_sum = INT_MIN;
    printm();
    for( i = mid; i >= low; i -- ) {
        c_sum = c_sum + A[i];
        if( c_sum > l_sum ) {
            l_sum = c_sum;
            s = i;
        }
    }
    printm();
    c_sum = 0;
    for( i = mid + 1; i <= high; i ++ ) {
        c_sum = c_sum + A[i];
        if( c_sum > r_sum ) {
            r_sum = c_sum;
            e = i;
        }
    }
    printm();
    m_start = s, m_end = e, m_sum = l_sum + r_sum;
    printm();
}
