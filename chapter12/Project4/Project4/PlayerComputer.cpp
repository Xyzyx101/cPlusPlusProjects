#include "PlayerComputer.h"
#include<iostream>

PlayerComputer::PlayerComputer(const string& name) :
Player(name)
{}

PlayerComputer::~PlayerComputer()
{}

int PlayerComputer::MakeMove(const int sticksRemaining) const
{
	int sticksToRemove = 1;
	bool willWin = false;
	while( !willWin && sticksToRemove < 5 )
	{
		willWin = TestChoice((sticksRemaining - sticksToRemove), false);
		++sticksToRemove;
	}
	cout << m_name << " chooses to remove " << sticksToRemove << " sticks." << endl;
	return sticksToRemove;
}

bool PlayerComputer::TestChoice(int sticksRemaining, bool myTurn) const
{
	if( sticksRemaining <= 4 )
	{
		if( myTurn )
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	bool willWin = false;
	int sticks = 1;
	while( !willWin && sticks < 5 )
	{
		willWin = TestChoice((sticksRemaining - sticks), !myTurn);
		++sticks;
	}
	return willWin && myTurn;
}