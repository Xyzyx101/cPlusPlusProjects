#include<iostream>
#include "Player.h"
#include "Alien.h"

using namespace std;

Player::Player( int ammo )
: m_ammo( ammo )
{
}

void Player::Blast( Alien& anAlien )
{
	if( m_ammo == 0 )
	{
		cout << "Player : Cannot blast because you have no ammo!" << endl;
	}
	else
	{
		cout << "Player : Blam!" << endl;
		anAlien.TakeDamage( );
		--m_ammo;
	}
}

void Player::Reload( )
{
	++m_ammo;
	cout << "Player : Reloading...current ammo at " << m_ammo << endl;
}
