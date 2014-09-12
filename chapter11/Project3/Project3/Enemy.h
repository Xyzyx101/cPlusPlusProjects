#pragma once
class Enemy
{
public:
	Enemy(int damage = 10);
	~Enemy();
	Enemy(const Enemy&);
	void Attack();
	void Taunt();
protected:
	int* m_pDamage;
};

