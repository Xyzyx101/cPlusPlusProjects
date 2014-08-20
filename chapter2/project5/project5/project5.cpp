#include<iostream>
using namespace std;

int main()
{
	const int MAX_NUMBER = 100;
	//random number between 1 and 100
	cout << "\tWelcome to Nim" << endl << endl;
	cout << "The game starts with 13 sticks.  Each player removes between 1 and 4 sticks until they are gone. ";
	cout << "The player whole removes the last stick wins." << endl << endl;

	enum player { ONE, TWO };
	player currentPlayer = ONE;
	int sticks = 13;
	do
	{
		int sticksToRemove;
		cout << "There are " << sticks << " sticks left and it is player";
		if( currentPlayer == ONE )
		{
			cout << " ones turn.";
		}
		else
		{
			cout << " twos turn.";
		}
		cout << " How many sticks would you like to remove? : ";
		bool validSelection = false;
		do
		{
			cin >> sticksToRemove;
			if( sticksToRemove < 5 && sticksToRemove > 0 )
			{
				validSelection = true;
			}
			else
			{
				cout << endl << "Choose a number between 1 and 4 : ";
			}

		} while( !validSelection );

		sticks -= sticksToRemove;

		if( sticks > 0 )
		{
			if( currentPlayer == ONE )
			{
				currentPlayer == TWO;
			}
			else
			{
				currentPlayer == ONE;
			}
		}

	} while( sticks > 0 );
	if( currentPlayer == ONE )
	{
		cout << endl << "Player one wins.";
	}
	else
	{
		cout << endl << "Player two wins.";
	}
	return 0;
};