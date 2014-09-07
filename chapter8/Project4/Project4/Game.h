#pragma once
#include<string>
#include"Player.h"
#include"Pile.h"
using namespace std;

class Game
{
public:
	Game( const string& playerOneName, const string& playerTwoName );
	void NextTurn( );
	string GameOver( ); // returns winners name or "" if the game is still going
private:
	bool playerOnesTurn;
	Player player1;
	Player player2;
	Pile pile;
};