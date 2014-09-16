#include<iostream>
#include<string>

#include"Game.h"

using namespace std;

int main()
{
	cout << "\tWelcome to Nim" << endl << endl;
	cout << "The game starts with 13 sticks.  Each player removes between 1 and 4 sticks until they are gone. ";
	cout << "The player whole removes the last stick wins." << endl << endl;

	Game* bacon = new Game;
	delete bacon;

	Game game;
	game.InitGame();

	while( game.GameOver() == "" )
	{
		game.NextTurn();
	}
	cout << game.GameOver() << " wins!" << endl << endl;
	return 0;
};