#pragma once
#include<string>

using namespace std;

class Player;

class Game
{
public:
	Game( const string& playerOneName, const string& playerTwoName );
	~Game( );
	void NextTurn( );
	void ClearChoices( );
	string GameOver( ); // returns winners name or nobody if the game is a draw
	static enum CHOICE
	{
		NOCHOICE = 0,
		ROCK = 1,
		PAPER = 2,
		SCISSORS = 3
	};
private:
	bool playerOnesTurn;
	Player* players[2];
};