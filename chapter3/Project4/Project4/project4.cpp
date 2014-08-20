#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
	int const HIGH_SCORE_BOARD_SIZE = 5;
	string names[HIGH_SCORE_BOARD_SIZE] = {
		"Andrew",
		"",
		"",
		"",
		""
	};
	int scores[HIGH_SCORE_BOARD_SIZE] = {
		1000,
		1000,
		1000,
		1000,
		1000
	};

	do
	{
		cout << "\tHIGH SCORES" << endl << endl;
		cout << "Name" << "\t\t\t" << "Score" << endl;
		int i = 0;
		do
		{
			cout << names[i] << "\t\t\t" << scores[i] << endl;
			++i;
		} while( i < HIGH_SCORE_BOARD_SIZE && !names[i].empty() );
		
		string newName;
		cout << endl << "Enter a new name or type 'exit' to quit: ";
		cin >> newName;
		if( newName == "exit" )
		{
			break; //end the main loop and exit program
		}
		else
		{
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
				for( i = 0; i < HIGH_SCORE_BOARD_SIZE; ++i )
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
	} while( true );
	return 0;
}