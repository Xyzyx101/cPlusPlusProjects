#include "Player.h"

Player::Player(const string& name)
:
m_name(name)
{}

Player::~Player()
{

}

const string& Player::GetName() const
{
	return m_name;
}

