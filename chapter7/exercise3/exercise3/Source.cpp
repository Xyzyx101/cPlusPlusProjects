#include<iostream>

using namespace std;

int main()
{
	// a is a regular int variable - &a is its memory address
	int a = 10;

	// b is an alias to a so it also has the same memory address
	int& b = a;

	// c is a pointer that is initialized with the same memory address as a and b
	int* c = &b;

	//all three lines will print the same value
	cout << &a << endl;
	cout << &b << endl;
	cout << &(*c) << endl;
}





