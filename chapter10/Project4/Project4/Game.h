#pragma once

#include"Stack.h"

class Game
{
public:
	Game();
	~Game();
	void DisplayIntro();
	void Setup();
	void Display();
	bool GameOver();
	void NextTurn();
private:
	static const int NUM_OF_PEGS = 3;
	Stack* pegs[NUM_OF_PEGS];
	void TransferDisk(Stack* from, Stack* to);
};

