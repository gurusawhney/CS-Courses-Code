/*
 * author: 
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "proj3.h"

// Implement a C function called level_1_opt. It should perform the same 
// task as the implemented level_1 function. 
// In the comments for the function describe why your changes make the
// function more cache friendly. 
//
// Note: your function needs to compute the entire matrix C,
// not only its x entry. 

long level_1(long * B, long * A, int x)
{
    long * C = (long * ) malloc (N*sizeof(long) );
    if (!C) return 0; 
    
    int c, r; 

    for(c = 0; c < N; c++)
        for(r = 0; r < N; r++)
            C[ r ] += B[ r*N + c ] + A[ c*N + r ] ;

    long ret = C[x];
    free (C); C = 0; 
    return ret;
}



long level_1_opt(long * B, long * A, int x)
{
    // DO NOT modify the following declarations 
    long * C = (long * ) malloc (N*sizeof(long) );
    if (!C) return 0; 
    
    // enter your code here 
    int c, r; 

    //traversing through the row first in a nested forloop is more cache friendly
    for(r = 0; r < N; r++)
        for(c = 0; c < N; c++)
            C[ r ] += B[ r*N + c ]; ///multiplies N by r

    for(c = 0; c < N; c++)
        for(r = 0; r < N; r++)
            C[ r ] += A[ c*N + r ]; //multiplies N by c
    
    //DO NOT modify the rest of this function 
    long ret = C[x];
    free (C); C = 0; 
    return ret;
}


