#include<iostream>
#include"Enemy.h"
#include"Boss.h"

using namespace std;

void testCopyConstructor(Enemy enemyCopy, Boss bossCopy);
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
	
	cout << endl << endl;
	testCopyConstructor(enemy, boss);
	
	cout << endl << endl;
	cout << "Original Enemy: " << endl;
	enemy.Taunt();
	cout << endl;
	enemy.Attack();

	cout << endl;

	cout << "Original Boss: " << endl;
	boss.Taunt();
	cout << endl;
	boss.Attack();
	boss.MegaAttack();

	return 0;
}

void testCopyConstructor(Enemy enemyCopy, Boss bossCopy)
{
	cout << "Copy Enemy: " << endl;
	enemyCopy.Taunt();
	cout << endl;
	enemyCopy.Attack();

	cout << endl;

	cout << "Copy Boss: " << endl;
	bossCopy.Taunt();
	cout << endl;
	bossCopy.Attack();
	bossCopy.MegaAttack();
}