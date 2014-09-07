#include<iostream>
#include<string>

#include "Game.h"

using namespace std;

int main( )
{
	cout << "\tWelcome to Rock Paper Scissors" << endl << endl;

	string playerOneName, playerTwoName;
	cout << "Player 1 enter your name : ";
	cin >> playerOneName;
	cout << endl << "Player 2 enter your name : ";
	cin >> playerTwoName;

	Game game( playerOneName, playerTwoName );

	string playAgain;
	while( playAgain != "q" )
	{
		game.ClearChoices( );
		game.NextTurn( );
		game.NextTurn( );
		cout << game.GameOver( ) << " wins!" << endl << endl;
		cout << "Enter q to quit or anything else to play again : ";
		cin >> playAgain;
	}

	return 0;
};