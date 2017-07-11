// Homework1.cpp : Defines the entry point for the console application.
//This program conducts a caesar cipher after reading a given text file 

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void decryptletter(char& letter,const int& shift)  //this function decodes each letter individually
{	
	if ((letter - shift) < 'a') { //this if-statement allows for the shift to loop from a-z
		letter = (letter - shift + 26);
	}
	else {
		letter = letter - shift;
	}
}

void decryptlines(vector<string>& vecoflines,const int& shift) //this function goes through every line in the vector, decodes it and prints it 
{
	for (size_t i = vecoflines.size(); i > 0; i--) {
		for (int j = 0; j < vecoflines[i - 1].size(); j++) { //this nested for loop goes through every character of the line
			if (vecoflines[i - 1][j] >='a' && vecoflines[i - 1][j]<= 'z') {
				decryptletter(vecoflines[i - 1][j], shift); //this takes the character and puts it into the letter decoder function
			}
		}
	}
}


int main()
{
	ifstream ifs("C:\\Users\\Gurumeher\\Documents\\Visual Studio 2015\\Projects\\Homework1\\encrypted.txt");
	if (!ifs) {
		cout << "Could not open file\n";
		exit(0);
	} //this if statement checks that the file is accessed 
	
	int shiftnumber;
	ifs >> shiftnumber; //this assigns the number on the first line to a variable 
	shiftnumber = shiftnumber % 26;

	string line;
	vector<string> vecoflines;
	while (getline(ifs, line)) { //this while loop stores every line into a vector
		vecoflines.push_back(line);
	}
	
	decryptlines(vecoflines, shiftnumber);

	for (size_t i = vecoflines.size(); i > 0; i--) {
		cout << vecoflines[i - 1] << endl; //this print statement outputs each line after being decoded
	}

}