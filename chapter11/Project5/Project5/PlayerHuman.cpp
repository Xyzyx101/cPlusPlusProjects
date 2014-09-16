#include "PlayerHuman.h"
#include<iostream>

PlayerHuman::PlayerHuman(string name) :
Player(name)
{}

PlayerHuman::~PlayerHuman()
{}

int PlayerHuman::MakeMove( const int sticksRemaining ) const
{
	bool validValue = false;
	int sticksToRemove;
	while( !validValue )
	{
		cin >> sticksToRemove;
		if( sticksToRemove > 0 &&
			sticksToRemove <= 4 &&
			sticksToRemove <= sticksRemaining )
		{
			validValue = true;
		}
		else
		{
			cout << sticksToRemove << " is not a valid number. Choose a number between 1 to 4." << endl;
		}
	}
	return sticksToRemove;
}