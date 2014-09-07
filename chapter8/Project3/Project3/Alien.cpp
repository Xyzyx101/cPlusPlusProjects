#include<iostream>
#include "Alien.h"

using namespace std;

Alien::Alien( int health )
:
m_health( health )
{
}

void Alien::TakeDamage( )
{
	if( m_health > 0 )
	{
		cout << "Alien : Ouch!" << endl;
		--m_health;
	}
	else
	{
		cout << "Alien : Dead." << endl;
	}
}

void Alien::Regenerate( )
{
	++m_health;
	cout << "Alien : Regenerating...current health at " << m_health << endl;
}