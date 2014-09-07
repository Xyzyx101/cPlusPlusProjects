#include<iostream>
#include<string>

using namespace std;

class Alien;
class Player
{
public:
	Player( int ammo = 3 );
	void Blast( Alien& anAlien );
	void Reload();
private:
	int m_ammo;
};

class Alien
{
public:
	Alien( int health = 5 );
	void TakeDamage();
	void Regenerate();
private:
	int m_health;
};

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

void Player::Reload()
{
	++m_ammo;
	cout << "Player : Reloading...current ammo at " << m_ammo << endl;
}

Alien::Alien( int health )
:
m_health( health )
{
}

void Alien::TakeDamage()
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

void Alien::Regenerate()
{
	++m_health;
	cout << "Alien : Regenerating...current health at " << m_health << endl;
}

int main()
{
	Player player;
	Alien alien;

	player.Blast( alien );
	player.Blast( alien );
	player.Blast( alien );
	player.Blast( alien );

	alien.Regenerate();

	player.Reload();
	player.Reload( );
	player.Reload( );
	player.Reload( );

	player.Blast( alien );
	player.Blast( alien );
	player.Blast( alien );
	player.Blast( alien );

	return 0;
}