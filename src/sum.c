#include "sum.h"

int sum(int a[], int n)
{
    //If the array is empty 
    if (n == 0) {
        return 0;
        //If the array is of length n
    } else if (n > 0) {
        //taking the sum of each array element
        return a[n - 1] + sum(a, n - 1);
    } 
}