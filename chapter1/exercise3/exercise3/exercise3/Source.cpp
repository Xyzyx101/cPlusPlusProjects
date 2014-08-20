#include <iostream>
#include <string>
using namespace std;

int main()
{
	float first, second, third;
	cout << "Enter a number : ";
	cin >> first;

	cout << "Enter another number : ";
	cin >> second;

	cout << "Enter one more number : ";
	cin >> third;

	cout << "The average of the three numbers is : " << (first + second + third) / 3.0;
	return 0;
}