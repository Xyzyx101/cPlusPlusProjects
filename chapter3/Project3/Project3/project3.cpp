#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
	const int RANKS = 13;
	const int SUITS = 4;
	string rank[RANKS] = {
		"A",
		"2",
		"3",
		"4",
		"5",
		"6",
		"7",
		"8",
		"9",
		"10",
		"J",
		"Q",
		"K"
	};
	char suit[SUITS] = {
		'c',
		'h',
		's',
		'd'
	};
	// row starts at 1 because I have aces in the first location but they should be displayed above kings
	for( size_t row = 1; row < RANKS; ++row )
	{
		for( size_t col = 0; col < SUITS; ++col )
		{
			cout << rank[row] << suit[col] << "\t";
		}
		cout << endl;
	}
	
	//the ace row is displayed as a special case
	int acesHigh = 0;
	for( size_t col = 0; col < SUITS; ++col )
	{
		cout << rank[acesHigh] << suit[col] << "\t";
	}
	cout << endl;
	return 0;
}