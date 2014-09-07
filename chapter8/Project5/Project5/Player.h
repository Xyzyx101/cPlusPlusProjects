#pragma once
#include<string>
#include"Game.h"
using namespace std;

class Player
{
public:
	Player( string name );
	const string& GetName( ) const;
	void SetChoice( enum Game::CHOICE choice );
	const enum Game::CHOICE& GetChoice( ) const;
private:
	string m_name;
	Game::CHOICE m_choice;
};