#include "Boss.h"
#include<iostream>

Boss::Boss(int damage, int megaMultiplier) :
m_DamageMultiplier(megaMultiplier)
{
	this->m_Damage = damage;
}

void Boss::MegaAttack()
{
	std::cout << "Enemy does mega attack for " << m_Damage * m_DamageMultiplier << std:: endl;
}

void Boss::Taunt()
{
	Enemy::Taunt();
	std::cout << "  And laugh heartily.";
}