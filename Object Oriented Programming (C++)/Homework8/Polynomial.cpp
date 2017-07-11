#include "Polynomial.h"
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

Node::Node(int data, Node* link) : data(data), link(link) {}

void addEnd(int entry, Node*& headPtr) { //adds the node to the end of the linked list
	if (headPtr == nullptr) { //checks if linked list is empty
		headPtr = new Node(entry);
	}
	else {
		Node* p = headPtr;
		while (p->link != nullptr) { //finds end
			p = p->link;
		} 
		p->link = new Node(entry);
	}	
}

Polynomial::Polynomial() {}

Polynomial::Polynomial(const vector<int>& v = {0}) {
	int headdata = v[0];
	degree = 0;
	Node* n = new Node(headdata);
	headNode = n;
	if (v.size() > 0) {
		for (size_t i = 1; i < v.size(); i++) { //goes through vector
			int tempdata = v[i];
			addEnd(tempdata, headNode); //adds linked list from greatest to least
			degree++; //adds degree level
		}
	}
}

Polynomial::~Polynomial() {
	Node* temp = headNode;
	while (temp != nullptr) {
		Node* next = temp->link;
		delete temp; //deletes the node
		temp = next; //assigns temp node to the next node in the link
	}
	headNode = nullptr;
}

Node* Polynomial::getHead() {
	return headNode;
}

int Polynomial::getDegree() {
	return degree;
}

int Polynomial::evaluate(int num) {
	Node* tempNode = headNode;
	int tempdegree = degree;
	int result = 0; //base result
	while (tempNode != nullptr) {
		if (tempdegree >= 1) {
			result += (tempNode->data)*(pow(num,tempdegree)); //adds the value of each linked list to the result
		}
		else if (tempdegree == 0) { //since there are no x's this adds the last number
			result += tempNode->data; 
		}
		tempNode = tempNode->link;
		tempdegree--; //decreases the degree for operation purposes
	}
	return result; //ending result
}

Polynomial& Polynomial::operator= (Polynomial& p) { 
	if (this != &p) { //if they are not the same
		Node* temp = headNode;
		while (temp != nullptr) { //deletes the original data
			Node* next = temp->link;
			delete temp;
			temp = next;
		}
		headNode = nullptr;

		degree = p.getDegree(); //copies the parameter's data
		Node* selftemp = new Node(p.getHead()->data);
		headNode = selftemp;
		Node* copytemp = p.getHead();
		if (degree > 0) {
			while (copytemp->link != nullptr) {
				Node* temp = new Node(copytemp->link->data);
				selftemp->link = temp;
				copytemp = copytemp->link;
				selftemp = selftemp->link;
			}
		}
	}
	return *this;
}

Polynomial& Polynomial::operator+= (Polynomial& p) { 
	int degdiff = degree - p.getDegree(); //the difference between the degrees
	if (degree >= p.getDegree()) { 
		Node* selftemp = headNode;
		Node* addtemp = p.getHead();
		for (size_t i = 0; i < degdiff; i++) { //allows me to skip the nodes in which the degree is higher
			selftemp = selftemp->link;
		}
		while (selftemp != nullptr) {
			selftemp->data += addtemp->data; //adds the data of the respective degree until the end
			selftemp = selftemp->link;
			addtemp = addtemp->link;
		}
	}
	else if (p.getDegree() > degree) {
		Polynomial temp(*this); //stores the lower value
		*this = p; //assigns the higher value
		Node* selftemp = headNode;
		Node* addtemp = temp.getHead();
		for (size_t i = 0; i < (degdiff*-1); i++) {
			selftemp = selftemp->link; //this and below is the same function of adding as the previous circumstance
		}
		while (selftemp != nullptr) {
			selftemp->data += addtemp->data;
			selftemp = selftemp->link;
			addtemp = addtemp->link;
		}
	}
	return *this;
}

Polynomial::Polynomial(Polynomial& p) {
	degree = p.getDegree(); //copy constructor
	Node* selftemp = new Node(p.getHead()->data); //build headNode
	headNode = selftemp;
	Node* copytemp = p.getHead();
	if (degree > 0) {
		while (copytemp->link != nullptr) {
			Node* temp = new Node(copytemp->link->data); //builds the list
			selftemp->link = temp;
			copytemp = copytemp->link;
			selftemp = selftemp->link;
		}
	}
}


Polynomial operator+(Polynomial& lhs, Polynomial& rhs)
{
	Polynomial temp(lhs);
	temp += rhs; //uses the += operator
	return temp;
}

ostream& operator<<(ostream& os, Polynomial& p) {
	Node* tempNode = p.getHead();
	int tempdegree = p.getDegree();
	while (tempNode != nullptr) { //iterates through the linked list
		if (tempNode->data != 0) os << showpos << tempNode->data; //prints out the coefficient
		if (tempdegree > 1) {
			os << "x^" << noshowpos << tempdegree; //prints out the variable with its degree
		}
		else if (tempdegree == 1 && tempNode->data != 0) { //since there is no degree just print out the x.
			os << "x";
		}
		tempNode = tempNode->link;
		tempdegree--; //decrease the degree for operation purposes
	}
	return os;
}

bool operator==(Polynomial& lhs, Polynomial& rhs) {
	if (lhs.getDegree() == rhs.getDegree()) {
		Node* left = lhs.getHead();
		Node* right = rhs.getHead();
		for (size_t i = 0; i <= lhs.getDegree(); i++) { //go through the polynomials
			if (left->data == right->data) {
				left = left->link;
				right = right->link;
			}
			else return false;
		}
		return true; //if everything is equal returns false but when not in any case returns true
	}
	else return false;
}
bool operator!=(Polynomial& lhs, Polynomial& rhs) { //same as == but outputs opposite bool values
	if (lhs.getDegree() == rhs.getDegree()) {
		Node* left = lhs.getHead();
		Node* right = rhs.getHead();
		for (size_t i = 0; i <= lhs.getDegree(); i++) {
			if (left->data == right->data) {
				left = left->link;
				right = right->link;
			}
			else return true;
		}
		return false;
	}
	else return true;
}



