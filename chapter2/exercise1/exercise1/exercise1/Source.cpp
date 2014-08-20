#include<iostream>
#include<string>

using namespace std;
int main()
{
	enum DIFFICULTY_LEVEL {EASY = 1,NORMAL = 2,HARD = 3};
	cout << "Difficulty Level\n\n";
	cout << "1 - Easy\n";
	cout << "2 - Normal\n";
	cout << "3 - Hard\n";

	int choice;
	cout << "Choice: ";
	cin >> choice;

	switch( choice )
	{
	case EASY:
		cout << "You picked Easy.\n";
		break;
	case NORMAL:
		cout << "You picked Normal.\n";
		break;
	case HARD:
		cout << "You picked Hard.\n";
		break;
	default:
		break;
	}
	return 0;
}

