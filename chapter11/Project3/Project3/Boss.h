#pragma once
#include "Enemy.h"
class Boss : public Enemy
{
public:
	Boss(int damage = 30, int megaMultiplier = 3);
	~Boss();
	Boss(const Boss&);
	void MegaAttack();
	void Taunt();

	int* m_pDamageMultiplier;

private:
	
};

