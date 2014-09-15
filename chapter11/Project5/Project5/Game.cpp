#include<iostream>
#include "Game.h"

using namespace std;

Game::Game( const string& playerOneName, const string& playerTwoName )
{
	player1 = Player( playerOneName );
	player2 = Player( playerTwoName );
	pile = Pile( );

	//it starts false because it is flipped at the begining of each turn and I want 1 to go first
	playerOnesTurn = false;
}

void Game::NextTurn( )
{
	playerOnesTurn = !playerOnesTurn;

	string currentPlayerName = playerOnesTurn ? player1.GetName( ) : player2.GetName( );
	cout << "There are " << pile.GetSticks( ) << " sticks left." << endl;

	bool validValue = false;
	int sticksToRemove;
	while( !validValue )
	{
		cout << endl;
		cout << "It is " << currentPlayerName << "'s turn." << endl;
		cout << "How many sticks do you want to remove? : ";
		cin >> sticksToRemove;
		if( sticksToRemove > 0 &&
			sticksToRemove <= 4 &&
			sticksToRemove <= pile.GetSticks( ) )
		{
			validValue = true;
		}
		else
		{
			cout << sticksToRemove << " is not a valid number. Choose a number between 1 to 4." << endl;
		}
	}
	pile.RemoveSticks( sticksToRemove );
}

string Game::GameOver( )
{
	if( pile.GetSticks( ) == 0 )
	{
		return playerOnesTurn ? player1.GetName( ) : player2.GetName( );
	}
	return "";
}