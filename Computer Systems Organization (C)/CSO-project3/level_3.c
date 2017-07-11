/*
 * author: 
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "proj3.h"

// Implement a C function called level_3_opt. It should perform the same 
// task as the implemented level_3 function. 
// In the comments for the function describe why your changes make the
// function more cache friendly. 
// Note that this function does not return any value. It modifies the array
// that is passed to it, instead. 

void level_3 (int *A, int n)
{
    int  i, j;
    for (i = 0; i < n; i++) 
    for (j = 0; j < n; j++)
        A[j*n + i] = A[j*n + i] || A[i*n + j];
}


void level_3_opt (int *A, int n)
{
    int  i, j;
    for (j = 0; j < n; j++)  //traversing through the row first in a nested forloop is more cache friendly
    	for (i = 0; i < n; i++)
    		A[j*n + i] = A[j*n + i] || A[i*n + j]; //updating a value, nothing is returned
}




