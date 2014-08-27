#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

int const HIGH_SCORE_BOARD_SIZE = 5;
void setDefaultEntries(string(&names)[HIGH_SCORE_BOARD_SIZE], int(&scores)[HIGH_SCORE_BOARD_SIZE]);
void DisplayTable(const string(&names)[HIGH_SCORE_BOARD_SIZE], const int(&scores)[HIGH_SCORE_BOARD_SIZE]);
void InsertEntry(string(&names)[HIGH_SCORE_BOARD_SIZE], int(&scores)[HIGH_SCORE_BOARD_SIZE]);

int main()
{
	string names[HIGH_SCORE_BOARD_SIZE];
	int scores[HIGH_SCORE_BOARD_SIZE];
	setDefaultEntries(names, scores);
	DisplayTable(names, scores);
	do
	{
		cout << endl << "0 - Quit" << endl;
		cout << "1 - Display table" << endl;
		cout << "2 - Insert new entry into table" << endl;
		cout << ">> ";
		int menuInput;
		cin >> menuInput;

		if( menuInput == 0 )
		{
			break;
		}
		else if( menuInput == 1 )
		{
			DisplayTable(names, scores);
		}
		else if( menuInput == 2 )
		{
			InsertEntry(names, scores);
		}
	} while( true );
	return 0;
}


void setDefaultEntries(string(&names)[HIGH_SCORE_BOARD_SIZE], int(&scores)[HIGH_SCORE_BOARD_SIZE])
{
	names[0] = "Andrew";
	scores[0] = 1000;
	for( size_t i = 1; i < HIGH_SCORE_BOARD_SIZE; ++i )
	{
		names[i] = "";
		scores[i] = 1000;
	}
}

void DisplayTable(const string(&names)[HIGH_SCORE_BOARD_SIZE], const int(&scores)[HIGH_SCORE_BOARD_SIZE])
{
	cout << "\tHIGH SCORES" << endl << endl;
	cout << "Name" << "\t\t\t" << "Score" << endl;
	int i = 0;
	do
	{
		cout << names[i] << "\t\t\t" << scores[i] << endl;
		++i;
	} while( i < HIGH_SCORE_BOARD_SIZE && !names[i].empty() );
}

void InsertEntry(string(&names)[HIGH_SCORE_BOARD_SIZE], int(&scores)[HIGH_SCORE_BOARD_SIZE])
{
	string newName;
	cout << endl << "Enter a new name : ";
	cin >> newName;
	int newScore;
	cout << endl << "Enter the new score: ";
	cin >> newScore;
	if( newScore < scores[HIGH_SCORE_BOARD_SIZE - 1] )
	{
		cout << endl << "That score is to low to get on the board" << endl << endl;
	}
	else
	{
		bool bumpHighScores = false;
		string bumpedName = "";
		int bumpedScore = 0;
		for( size_t i = 0; i < HIGH_SCORE_BOARD_SIZE; ++i )
		{
			if( bumpHighScores )
			{
				string tempName = names[i];
				int tempScore = scores[i];
				names[i] = bumpedName;
				scores[i] = bumpedScore;
				bumpedName = tempName;
				bumpedScore = tempScore;
			}
			else if( newScore > scores[i] )
			{
				bumpedName = names[i];
				bumpedScore = scores[i];
				names[i] = newName;
				scores[i] = newScore;
				bumpHighScores = true;
			}
		}
	}
}