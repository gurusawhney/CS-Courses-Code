#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <string>
#include <iostream>
#include <vector>

struct Node {
	Node(int data = 0, Node* link = nullptr);
	int data;
	Node* link;
};

void addEnd(int entry, Node*& headPtr);

class Polynomial {
public:
	Polynomial(); //default constructor
	Polynomial(const std::vector<int>& v); //constructor
	Polynomial(Polynomial& p); //copy constructor
	Node* getHead(); //gets the head node
	int getDegree(); //gets the degree
	int evaluate(int num); //evaluates the polynomial given an integer
	~Polynomial(); //destructor
	Polynomial& operator+= (Polynomial& p); //adds the parameter to the polynomial
	Polynomial& operator= (Polynomial& p); //assingment operator
private:
	Node* headNode = nullptr;
	int degree = 0;
	};

std::ostream& operator<<(std::ostream& os, Polynomial& p); //output operator
Polynomial operator+ (Polynomial& lhs, Polynomial& rhs); //+ operator 
bool operator==(Polynomial& lhs, Polynomial& rhs); //bool operator
bool operator!=(Polynomial& lhs, Polynomial& rhs); //bool operator

#endif POLYNOMIAL_H

