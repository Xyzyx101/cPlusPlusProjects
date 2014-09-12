#include<iostream>
#include"Enemy.h"
#include"Boss.h"

using namespace std;

int main()
{
	Enemy enemy;
	Boss boss;

	cout << "Enemy: " << endl;
	enemy.Taunt();
	cout << endl;
	enemy.Attack();

	cout << endl;
	
	cout << "Boss: " << endl;
	boss.Taunt();
	cout << endl;
	boss.Attack();
	boss.MegaAttack();

	return 0;
}