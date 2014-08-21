#include<iostream>
#include<string>

using namespace std;

int askNumber(int low, int high);

int main()
{
	int validNumber = askNumber(1, 10);
	cout << "The valid number is " << validNumber;
	return 0;
}

int askNumber(int low, int high)
{
	int validNumber = 0;
	int number;
	while( !validNumber )
	{
		cout << "\nEnter a number between " << low << " and " << high << " : ";
		cin >> number;
		if( number > high )
		{
			cout << "\nThat number is too high.\n";
		}
		else if(number < low )
		{
			cout << "\nThat number is too low.\n";
		}
		else
		{
			validNumber = number;
		}
	}
	return validNumber;
}