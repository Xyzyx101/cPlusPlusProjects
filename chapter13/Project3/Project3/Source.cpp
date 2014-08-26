#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;

bool isNumber(string str);

int main()
{
	int const HIGH_SCORE_BOARD_SIZE = 5;

	vector<int> scores = {
		1000
	};

	do
	{
		cout << "\tHIGH SCORES" << endl << endl;
		cout << "\t" << "Score" << endl;
		int i = 0;
		for( auto it = scores.begin(); it != scores.end(); ++it )
		{
			cout << "\t\t\t" << scores[i] << endl;
			++i;
		}

		string input;
		do
		{
			cout << endl << "Enter the new score or (q)uit: ";
			cin >> input;
		} while( !isNumber(input) && input != "q" );
		if( input == "q" )
		{
			break;
		}

		int newScore = atoi(input.c_str());
		if( newScore < *(scores.end() - 1) )
		{
			cout << endl << "That score is to low to get on the board" << endl << endl;
		}
		else
		{
			scores.push_back(newScore);
			sort(scores.begin(), scores.end(), greater<int>());
		}
	} while( true );
	return 0;
}

bool isNumber(string str)
{
	for( size_t i = 0; i < str.length(); ++i)
	{
		if( !isdigit(str[i]))
		{
			return false;
		}
	}
	return true;
}