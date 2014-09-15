#pragma once
#include "Weapon.h"
class Crossbow : public Weapon
{
public:
	Crossbow(int damage = 20, bool loaded = true);
	virtual ~Crossbow();
	void Attack();
	void Reload();
private:
	bool m_Loaded;
};

