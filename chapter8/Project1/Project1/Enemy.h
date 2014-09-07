#ifndef ENEMY_H
#define ENEMY_H

class Enemy
{
public:
	Enemy( );
	~Enemy( );
	static void DisplayTactics( );
private:
	static int EnemyCount;
};

#endif