#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "proj1.h"



/*********************************
 * Problem 3 required functions  *
 *********************************/


int is_normalized ( float f ) {
	if(is_denormalized(f) == 0 && is_special(f) == 0) { //checking that f is neither denormalized or special
		return 1;
	}
	else {
		return 0;
	}
}

/***********/ 

int is_denormalized ( float f ) { //checks denormalized condition
	char * num = get_bits_float(f);
	int flag = 1;
	int i;
	for(i = 1; i < 9; i++) { //makes sure that the exp in the bit vector is all 0s
		if(num[i] != '0') {
			free(num);
			return 0; //if it isn't returns 0 (false)
		}
	}
	
	free(num);
	return flag;
}

/***********/ 

int is_special ( float f ) { //check special condition
	char * num = get_bits_float(f);
	int flag = 1;
	int i;
	for(i = 1; i < 9; i++) { //makes sure tht the exp in the bit vector is all 1s
		if(num[i] != '1') {
			free(num);
			return 0; //if it isn't returns 0 (false)
		}
	}
	
	free(num);
	return flag;
}

/***********/ 

char * get_M ( float f ) {
	char * m ; 
	if(is_special(f)) {
		m = malloc(1); //allocates the space to store M with size of char, which is 1
		return m; //returns null if f is special
	}
	char * binary = get_bits_float(f); //converts float to bit vector
	m = malloc((1)*26); //allocates the space to store M with size of char, which is 1, with 26 bits
	int i;
	for(i = 0; i<26; i++) {
		m[i]='0'; //populates the array for all 0s to work with
	}
	if(is_normalized(f)) {
		m[0] = '1'; //if normalized adds 1 to first index
	}
	m[1] = '.';
	for(i = 2; i < 26; i++) {
		m[i] = binary[7+i]; //copies the fraction part of the bit vector
	}
	
	free(binary);
	return m;
}

/***********/ 

int get_s ( float f ) {
	if(f > 0) { 
		return 0; //positive
	}
	else {
		return 1; //negative
	}
}

/***********/ 

int get_E ( float f ) {
	float temp = f;
	int counter = 0;
	if(is_normalized(f)) { //calculated E using the powers of 2
		if(temp > 1 || temp < -1) {
			while(temp/2 > 1 || temp/2 < -1) {
				temp = temp/2; //keeps on dividing the float until its between 1-0 or 0-1
				counter++; //the E value
				if(counter == 255) { //max counter
					return counter;
				}
			}	
		}
	}
	if(is_denormalized(f)) { //formula for E
		counter = 1 - 127; //127 is the bias for single precision
	}
	if(is_special(f)) {
		return 255; 
	}
    return counter;
}





/*********************************
 * Problem 4 required functions  *
 *********************************/

float get_float_from_bits( char * bits ) {
    float m = get_M_from_bits(bits);
    int e = get_E_from_bits(bits);
    int s = get_s_from_bits(bits);
    float num = pow(-1,s)*m*pow(2,e); //formula to calculate the float
    return num;
}

/***********/ 

type get_type_from_bits( char * bits ) {
    int i;
    type t = NORM;
    if(bits[1] == '0') { //checks if the bit vector is all 0s in exp
    	t = DENORM;
    	for(i = 1; i < 9; i++) {
    		if(bits[i] != '0') {
    			return NORM; //if it isn't its normalized
    		}
    	}
    	return t;
    }
    if(bits[1] == '1') { //checks if the bit vector is all 1s in exp
    	t = SPECIAL;
    	for(i = 1; i < 9; i++) {
    		if(bits[i] != '1') {
    			return NORM; //if it isn't its normalized
    		}
    	}
    	return t;
    }
    return t;
}

/***********/ 

int get_s_from_bits ( char * bits ){
	if(bits[0] == '1') { //if the sign bit is '1' then its negative
		return 1; 
	}
	else {
		return 0; 
	}
}

/***********/ 

int get_E_from_bits ( char * bits ) {
    int e = 0;
    if(get_type_from_bits(bits) == NORM) {
    	int power = 1;
    	int i;
    	for(i = 8; i > 0; i--) { //goes through binary and calculated the decimal 
    		if(bits[i] == '1') {
    			e += power; //the decimal value
    		}
    		power *= 2; //increases the power per bit
    	}
    	e = e-127; //formula for calculating E. 127 is bias for single precision. (2^(k-1)-1).
    	return e;	
    }
    else if(get_type_from_bits(bits) == DENORM) {
    	e = 1-127; //forumula denormalized E.
    	return e;
    }
    else if(get_type_from_bits(bits) == SPECIAL) {
    	e = 255;
    	return e;
    }
    return e;    
}

/***********/ 

float get_M_from_bits ( char * bits ) {
    float e = 0;
    float power = 0.5;
    int i;
    if(get_type_from_bits(bits) == SPECIAL) {
    	for(i = 9; i < 33; i++) {
        	if(bits[i] == '1') { //if there is a 1 in frac then the value is NAN.
        		if(get_s_from_bits(bits) == 1) { //checks whether its negative
        			return -NAN; 
        		}
        		return NAN;
        	}
        } 
        return INFINITY; //if its all 0s returns infinity
    }
    for(i = 9; i < 33; i++) { //calculated the binary fraction
        	if(bits[i] == '1') {
    			e += power; //the value of E
    		}
    	power /= 2; //decreases the power per bit
    }
    if(get_type_from_bits(bits) == NORM) { //M is 1.xxxxxx if normalized.
    	e += 1;
    }
    return e;
}




/********************************************************************
 * Problem 3 and 4 additional functions  
 ********************************************************************
 * 
 * Specify an additional function declarations in this section.
 ********************************************************************/


  











/********************************************************************
 * Other functions   
 ********************************************************************
 *
 * You do not have to use the following functions in your own code, 
 * but do not remove them from this file. 
 ********************************************************************/


char* get_bits_int ( int n ) {
	//allocate memory to store the string 
	int num_of_bits =  sizeof(int) * 8;  //*8 since there are 8 bits per byte 
	char * bits_of_numbers = (char*) malloc( num_of_bits + 1);
	
	short bit ; 
	
	int i;
	//convert value of n to bits 
	for ( i = 0; i < num_of_bits; i++ ) {
		bit = n & 1; //grab the last bit
		bits_of_numbers[num_of_bits-i-1] = '0' + bit;
		n = n>>1;    //remove the last bit
	}
	
	bits_of_numbers[num_of_bits] = '\0'; //end with a null character
	return bits_of_numbers; 
}

/***********/ 

char* get_bits_float ( float f ) {
	//allocate memory to store the string
	int num_of_bits =  sizeof(float) * 8;  //*8 since there are 8 bits per byte 
	char * bits_of_numbers = (char*) malloc( num_of_bits + 1);
	
	//interpret the bits as int (this is not equivalent to casting to int) 
	int  p = *((int*) (&f) );
	short bit ; 
	
	int i;
	//convert value of n to bits 
	for ( i = 0; i < sizeof(float)*8; i++ ) {
		bit = p & 1;  //grab the last bit
		bits_of_numbers[num_of_bits-i-1] = '0' + bit;
		p = p>>1;    //remove the last bit
	}
	
	bits_of_numbers[num_of_bits] = '\0'; //end with a null character
	return bits_of_numbers; 
	
}


/***********/ 

int  assert_equals_int(int a, int b){
	if (((unsigned)(a) ^ (unsigned)(b)) == 0 ){
		return 1; 
	}
	else{
		return 0; 
	}
}

/***********/ 

int assert_equals_float(float a, float b){
    unsigned * pa = (unsigned *)(&a);
    unsigned * pb = (unsigned *) (&b);
    if ( ( (*pa) ^ (*pb) ) == 0 ){
		return 1; 
	}
	else{
		return 0; 
	}
}
 
/***********/ 

int assert_equals_string(char* a, char * b){
	return ! strcmp(a,b);
}

/***********/ 














    





    

    






      



    
    
