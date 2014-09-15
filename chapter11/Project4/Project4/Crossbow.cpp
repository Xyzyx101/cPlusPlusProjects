#include "Crossbow.h"
#include<iostream>

using namespace std;

Crossbow::Crossbow(int damage, bool loaded) :
Weapon(damage),
m_Loaded(loaded)
{}


Crossbow::~Crossbow()
{}

void Crossbow::Attack()
{
	if( m_Loaded )
	{
		cout << "Crossbow attacks for " << m_Damage << " points of damage." << endl;
		m_Loaded = false;
	}
	else
	{
		cout << "Crossbow is not loaded and cannot shoot." << endl;
	}
}

void Crossbow::Reload()
{
	if( m_Loaded )
	{
		cout << "Crossbow is already loaded." << endl;
	}
	else
	{
		cout << "Crossbow reloaded." << endl;
		m_Loaded = true;
	}
}