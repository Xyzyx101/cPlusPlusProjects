#pragma once
#include "Enemy.h"
class Boss : public Enemy
{
public:
	Boss(int damage = 30, int megaMultiplier = 3);
	void MegaAttack();
	void Taunt();
private:
	int m_DamageMultiplier;
};

