/* Agnetha Baltz
This program uses a recrusive function that searches the integer array a for the element x.
*/
#include "search.h"
#include <stdbool.h>

bool search(int a[], int n, int x)
{   //If the array consists of elements, at the searched element has been found
    if(n > 0 && a[n - 1] == x) {
        return true;
     //If the array consists element, but the searched element hasn't been found jet.
    } else if (n > 0 && a[n - 1] != x) {
        return search(a, n - 1, x);
     //If there are no elements in the array
    } else if (n == 0){
        return false;
    }    
}