#pragma once
#include "Weapon.h"
class Sword : public Weapon
{
public:
	Sword(int damage = 10);
	virtual ~Sword();
	void Attack();
};

