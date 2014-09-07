#include<iostream>
#include<string>

using namespace std;

class Enemy
{
public:
	Enemy();
	~Enemy();
	static void DisplayTactics();
private:
	static int EnemyCount;
};

int Enemy::EnemyCount = 0;
Enemy::Enemy()
{
	++EnemyCount;
}
Enemy::~Enemy()
{
	--EnemyCount;
}

void Enemy::DisplayTactics()
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

void CreateEnemies()
{
	Enemy newEnemy1;
	Enemy newEnemy2;
	Enemy::DisplayTactics();
}

int main()
{
	const int NUM1 = 3;
	cout << endl << "In main()" << endl;
	cout << "Creating " << NUM1 << " Enemy Objects..." << endl;
	Enemy group1[NUM1];
	
	//should display defensive
	Enemy::DisplayTactics();
	
	//should display aggresive
	CreateEnemies();

	cout << "Back int main()" << endl;
	
	//should display defensive
	Enemy::DisplayTactics();

	return 0;
}