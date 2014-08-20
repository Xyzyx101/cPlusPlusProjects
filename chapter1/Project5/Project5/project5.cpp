#include<iostream>
#include<string>
using namespace std;

int main() {
	string name, noun;
	unsigned int spells, hours;

	cout << "	Welcome to the test" << endl << endl;
	cout << "Please enter the following for a personalozed story." << endl << endl;
	
	cout << "Enter your last name: ";
	cin >> name;

	cout << "Enter a positive number: ";
	cin >> spells;

	cout << "Enter another positive number: ";
	cin >> hours;

	cout << "Enter a noun: ";
	cin >> noun;
	
	cout << "Story story " << name << " blah blah studied " << spells << " spells for " 
		<< hours << " hours each for a total of " << spells * hours << " hours and then " << noun << endl;
	return 0;
}