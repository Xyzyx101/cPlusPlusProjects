#pragma once
#include<string>
#include"Player.h"
#include"Pile.h"
using namespace std;

class Game
{
public:
	Game();
	~Game();
	void InitGame();
	void NextTurn();
	string GameOver(); // returns winners name or "" if the game is still going
private:
	bool playerOnesTurn;
	Player* player1;
	Player* player2;
	Pile pile;
};