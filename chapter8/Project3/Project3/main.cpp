#include<iostream>
#include<string>
#include"Player.h"
#include"Alien.h"

using namespace std;

int main( )
{
	Player player;
	Alien alien;

	player.Blast( alien );
	player.Blast( alien );
	player.Blast( alien );
	player.Blast( alien );

	alien.Regenerate( );

	player.Reload( );
	player.Reload( );
	player.Reload( );
	player.Reload( );

	player.Blast( alien );
	player.Blast( alien );
	player.Blast( alien );
	player.Blast( alien );

	return 0;
}