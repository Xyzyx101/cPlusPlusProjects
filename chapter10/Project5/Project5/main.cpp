// Tower of Hanoi Game

#include<iostream>
#include"Game.h"

using namespace std;

int main()
{
	Game game;
	game.Setup();
	game.DisplayIntro();
	
	while( !game.GameOver() )
	{
		game.Display();
		game.NextTurn();
	}
	cout << "You Won!" << endl;

	return 0;
}