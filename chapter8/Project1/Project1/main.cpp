#include<iostream>
#include<string>

#include"Enemy.h"

using namespace std;

void CreateEnemies( )
{
	Enemy newEnemy1;
	Enemy newEnemy2;
	Enemy::DisplayTactics( );
}

int main( )
{
	const int NUM1 = 3;
	cout << endl << "In main()" << endl;
	cout << "Creating " << NUM1 << " Enemy Objects..." << endl;
	Enemy group1[NUM1];

	//should display defensive
	Enemy::DisplayTactics( );

	//should display aggresive
	CreateEnemies( );

	cout << "Back int main()" << endl;

	//should display defensive
	Enemy::DisplayTactics( );

	return 0;
}