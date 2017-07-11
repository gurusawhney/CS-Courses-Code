//Gurumeher Sawhney
//N13923706, gs2605

//Implement a C function called problem3 such that it achieves 
//the same functionality as the machine code of objs/problem3.o
//Note1: you need to figure out problem3()'s function signature yourself; 
//the signature is not void problem3()
//Note2: you should replace this header with the documentation
//for the function that you implement (this includes the name of its author). 
#include <stdlib.h>   

//this function adds up random numbers n times and then divides the number by n, and
// ten returns that number. It calculates the mean.
long problem3(int edi) {
	int x; //pushing variables to the stack
	int y; 
	int z;

    x = edi; //assigning edi to r12d
	z = 0; //assigning 0
	y = 0; //assigning 0
	int a; //declaring the eax for use inside for loop
	
	for (z = 0; z < x; z++) { //comparing (jl so <) x(r12) with z
		a = rand(); 
    	y = y + a; //adding the random a(eax) to y
	}
   
	a = y; //assigning y to a
	a = a/x; //dividing a by x
	//popping of variables occurs
	return a; 
}
