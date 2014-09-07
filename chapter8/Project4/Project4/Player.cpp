#include "Player.h"

Player::Player( )
{
}

Player::Player( string name )
:
m_name( name )
{
}

const string& Player::GetName( ) const
{
	return m_name;
}

