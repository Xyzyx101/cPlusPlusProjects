#pragma once

#include"Stack.h"
#include<string>

class Game
{
public:
	Game();
	~Game();
	void DisplayIntro();
	void Setup();
	void Display() const;
	bool GameOver();
	void NextTurn();
private:
	static const int NUM_OF_PEGS = 3;
	static const string DISPLAY_STRINGS[5];

	Stack* pegs[NUM_OF_PEGS];
	void TransferDisk(Stack* from, Stack* to);
	void Game::DisplayPeg( const Stack& peg ) const;
};

