//Gurumeher Sawhney
//N13923706, gs2605

//Implement a C functions called problem4 and comp4 such that they achieve
//the same functionality as the machine code of objs/problem4.o
//Note1: you need to figure out the function signatures yourself; 
//the signatures are not void comp4() and void problem4()
//Note2: you should replace this header with the documentation
//for the functions that you implement (this includes the name of its author). 
  
//this function multiplies an argument by itself esi times. Like a power function. 
long comp4(int *rdi, int esi) {
	int x = 0; //assigns 0
    int y = 1; //assigns 1

    for(x = 0; x < esi; x++) { //comparing x with esi
		y = y * (*rdi); //multiplying the dereference of rdi which goes to rcx with y
	}
	return y;
}
//this function adds up all of the results of comp4, which in this case since k=3 are cubes,
// and returns that number.
long problem4(long rsp, int esi) {
	int x; //initializing push variables
	long y;
	int z;

	x = esi; //assigns esi to x
	z = (int) rsp; //assigns rsp to x
	y = 0; //assigns 0 to y

	for(z = (int) rsp; z <= x; z++) { //comparing (jle so <=) z with x
		esi = 3; //assigning 3 to esi;
		y = y + comp4(&z,esi); //adds the result of function comp4
	}	

	return y;
}
