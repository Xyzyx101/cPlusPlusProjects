#include<iostream>
#include<string>

#include"Game.h"

using namespace std;

int main( )
{
	cout << "\tWelcome to Nim" << endl << endl;
	cout << "The game starts with 13 sticks.  Each player removes between 1 and 4 sticks until they are gone. ";
	cout << "The player whole removes the last stick wins." << endl << endl;

	string playerOneName, playerTwoName;
	cout << "Player 1 enter your name : ";
	cin >> playerOneName;
	cout << endl << "Player 2 enter your name : ";
	cin >> playerTwoName;

	Game game( playerOneName, playerTwoName );

	while( game.GameOver( ) == "" )
	{
		game.NextTurn( );
	}
	cout << game.GameOver( ) << " wins!" << endl << endl;
	return 0;
};