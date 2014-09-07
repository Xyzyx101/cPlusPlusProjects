#include "Player.h"

Player::Player( string name )
:
m_name( name )
{
}

const string& Player::GetName( ) const
{
	return m_name;
}

void Player::SetChoice( enum Game::CHOICE choice )
{
	m_choice = choice;
}
