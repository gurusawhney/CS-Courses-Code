//Gurumeher Sawhney
//N13923706, gs2605

//Implement a C function called problem2 such that it achieves 
//the same functionality as the machine code of objs/problem2.o
//Note1: you need to figure out problem2()'s function signature yourself; 
//the signature is not void problem2()
//Note2: you should replace this header with the documentation
//for the function that you implement (this includes the name of its author). 
  
//this function performs the rol assembly instruction that shifts the bits
//and moves the pushed bits to the other end. It is then casted and returned.
int problem2(int edi) {
	int eax = edi; //intializing eax
	eax = (eax << 4) | (eax >> 4); //rol instruction using 4
	short al = (short) eax; //storing it as al
	return al;
}
