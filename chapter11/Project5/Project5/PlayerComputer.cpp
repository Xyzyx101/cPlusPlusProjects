#include "PlayerComputer.h"
#include<iostream>

PlayerComputer::PlayerComputer(const string& name) :
Player(name)
{}

PlayerComputer::~PlayerComputer()
{}

int PlayerComputer::MakeMove(const int sticksRemaining) const
{
	int sticksToRemove;

	if( sticksRemaining > 10 )
	{
		sticksToRemove = sticksRemaining - 10;
	}
	else if( sticksRemaining == 10 )
	{
		sticksToRemove = 1;
	}
	else if( sticksRemaining > 5 && sticksRemaining < 10 )
	{
		sticksToRemove = sticksRemaining - 5;
	}
	else if( sticksRemaining == 5 )
	{
		sticksToRemove = 1;
	}
	else if( sticksRemaining < 5 )
	{
		sticksToRemove = sticksRemaining;
	}

	cout << m_name << " chooses to remove " << sticksToRemove << " sticks." << endl;
	return sticksToRemove;
}
