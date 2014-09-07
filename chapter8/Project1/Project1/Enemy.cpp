#include<iostream>
#include<string>

#include"Enemy.h"

using namespace std;

int Enemy::EnemyCount = 0;

Enemy::Enemy( )
{
	++EnemyCount;
}
Enemy::~Enemy( )
{
	--EnemyCount;
}

void Enemy::DisplayTactics( )
{
	string tactic;
	if( EnemyCount < 5 )
	{
		tactic = "Defensive";
	}
	else
	{
		tactic = "Aggresive";
	}
	cout << "There are " << EnemyCount << " enemies." << tactic << " tactics set." << endl;
}