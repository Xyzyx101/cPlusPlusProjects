#include "PlayerComputer.h"
#include<iostream>

PlayerComputer::PlayerComputer(string name) :
Player(name)
{
}


PlayerComputer::~PlayerComputer()
{
}

int PlayerComputer::MakeMove( const int sticksRemaining ) const
{
	int sticksToRemove;
	
	if( sticksRemaining > 11 )
	{
		sticksToRemove = sticksRemaining - 11;

	}
	else if( sticksRemaining == 11 )
	{
		sticksToRemove = 4;
	}
	else if( sticksRemaining >= 6 && sticksRemaining <= 10 )
	{
		sticksToRemove = sticksRemaining - 5;
		if( sticksToRemove > 4 )
		{
			sticksToRemove = 4;
		}
	}
	else if( sticksRemaining == 5 )
	{
		sticksToRemove = 1;
	}
	else if( sticksRemaining < 5 )
	{
		sticksToRemove = sticksRemaining;
	}

	cout << m_name << " chooses to remove " << sticksToRemove << " sticks.";
	return sticksToRemove;
}
