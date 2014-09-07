#pragma once
class Alien;
class Player
{
public:
	Player( int ammo = 3 );
	void Blast( Alien& anAlien );
	void Reload( );
private:
	int m_ammo;
};