#pragma once
class Enemy
{
public:
	Enemy(int damage = 10);
	void Attack();
	void Taunt();
protected:
	int m_Damage;
};

