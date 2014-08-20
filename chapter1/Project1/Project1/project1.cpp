
#include<iostream>
using namespace std;

int main()
{
	cout << "	Game Menu" << endl;
	cout << "1. One Player" << endl;
	cout << "2. Two Player" << endl;
	cout << "3.	Quit" << endl;
	int choice;
	bool selected;
	do {
		cin >> choice;
		selected = true;
		if (choice == 1) {
			cout << "You selected one player" << endl;
		}
		else if (choice == 2) {
			cout << "You selected two player" << endl;
		}
		else if (choice == 3) {
			cout << "You selected quit" << endl;
		}
		else {
			cout << "You selected a wrong value" << endl;
			selected = false;
		}
	} while (!selected);
	return 0;
}