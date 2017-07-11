//Gurumeher Sawhney
//N13923706, gs2605

//Implement a C functions called problem5 and comp5 such that they achieve
//the same functionality as the machine code of objs/problem5.o
//Note1: you need to figure out the function signatures yourself; 
//the signatures are not void comp5() and void problem5()
//Note2: you should replace this header with the documentation
//for the functions that you implement (this includes the name of its author). 
  

#include <stdlib.h> 
#include <stdio.h>

//function takes in the array, multiplies each index by 201, and then saves that 
//as the new value in that index.
void comp5(long *rcx, int esi) {
	int x = 0; //assigns 0 (for eax)
	long y;

	for(x = 0; x < esi; x++) { //compares x with esi
		y = rcx[x]; //x is saved in rdx and then addressed for r8
		y = y * 201; //the accumulated leaqs give rdx*201 from 5*5*8+1
		rcx[x] = y; //assigns the total rdx to the dereference of rcx
	}
}

//allocated memory for an array of edi length and once initializing values in the 
//array it calls comp5 and then returns the array
long * problem5(int edi) {
	long x; //pushing variables onto stack
	long *y;

	x = edi; //assigning edi to x
	y = (long *) malloc(8*(x)); //malloc called with shl of 3 which is 8.
								//rax and rbx register used to store values in *y
	if(y != NULL) { //testing itself (rax register)
		int i;	//edx, initialized at 0 and incremented
		for(i = 0; i < x; i++) { //for loop comparing edx with x
			y[i] = i; 
		}
		comp5(y,edi); //comp5 is called
	}

	return y;
}
