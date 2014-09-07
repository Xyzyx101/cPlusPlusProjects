#pragma once
class Alien
{
public:
	Alien( int health = 5 );
	void TakeDamage( );
	void Regenerate( );
private:
	int m_health;
};