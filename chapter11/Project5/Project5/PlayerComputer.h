#pragma once
#include "Player.h"
class PlayerComputer : public Player
{
public:
	PlayerComputer(const string& name);
	virtual ~PlayerComputer();
	int MakeMove(const int sticksRemaining) const;
};

