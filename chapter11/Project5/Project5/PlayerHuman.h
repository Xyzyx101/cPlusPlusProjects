#pragma once
#include "Player.h"
class PlayerHuman :	public Player
{
public:
	PlayerHuman(string name);
	virtual ~PlayerHuman();
	int MakeMove( const int sticksRemaining ) const;
};
