#pragma once
class Enemy
{
public:
	Enemy(int damage = 10);
	void Attack();
protected:
	int m_Damage;
};

