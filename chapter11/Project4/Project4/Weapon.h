#pragma once
class Weapon
{
public:
	Weapon(int damage = 10);
	virtual ~Weapon();
	virtual void Attack() = 0;
protected:
	int m_Damage;
};

