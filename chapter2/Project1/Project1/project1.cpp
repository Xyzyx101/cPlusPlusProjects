#include<iostream>
using namespace std;

int main()
{
	int score;
	cout << "Enter your score: ";
	cin >> score;
	if( score >= 9999 )
	{
		cout << "Very impressive";
	}
	else if( score < 9999 && score >= 1000)
	{
		cout << "Good score";
	}
	else if ( score < 1000 && score >= 0)
	{
		cout << "Nothing to brag about";
	}
	else
	{
		cout << "Not a valid score";
	}
}