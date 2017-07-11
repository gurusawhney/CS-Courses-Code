//Gurumeher Sawhney
//N13923706, gs2605

//Implement a C function called problem1 such that it achieves 
//the same functionality as the machine code of objs/problem1.o
//Note1: you need to figure out problem1()'s function signature yourself; 
//the signature is not void problem1()
//Note2: you should replace this header with the documentation
//for the function that you implement (this includes the name of its author). 
//  

//this function takes in 3 parameters and after various instructions that 
//involve binary and regular arithmetic there is an output
long problem1(long rdi, long rsi, long rdx) {
	long rcx = rsi + 3; //initializing x
	if (rsi >= 0) { //testq
		rcx = rsi; //assigned rsi to rcx
	}
	
	rcx = rcx >> 2; //shifting right by 2 (sar)
	rdi = rdi +rcx; //adding rcx to rdi
	long rax = rdx * 3; //lea, loading rdx+rdx*2
	rax = rax * 4; //shifting left so multiply by 4 (shl)
	rax = rax + rdi; //adding rdi to rax

	return rax;
}