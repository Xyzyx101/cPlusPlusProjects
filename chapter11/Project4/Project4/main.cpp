#include"Sword.h"
#include"Crossbow.h"

int main()
{
	Sword sword;
	Crossbow crossbow;

	sword.Attack();
	sword.Attack();

	crossbow.Attack();
	crossbow.Attack();
	crossbow.Reload();
	crossbow.Reload();
	crossbow.Attack();

	return 0;
}