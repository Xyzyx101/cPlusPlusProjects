#include "Boss.h"
#include<iostream>

Boss::Boss(int damage, int megaMultiplier) :
Enemy(damage)
{
	m_pDamageMultiplier = new int(megaMultiplier);
}

Boss::~Boss()
{
	delete m_pDamageMultiplier;
}

Boss::Boss(const Boss& other) :
Enemy(other)
{
	int otherDamageMultiplier = *(other.m_pDamageMultiplier);
	m_pDamageMultiplier = new int(otherDamageMultiplier);
}

void Boss::MegaAttack()
{
	std::cout << "Enemy does mega attack for " << (*m_pDamage) * (*m_pDamageMultiplier) << std:: endl;
}

void Boss::Taunt()
{
	Enemy::Taunt();
	std::cout << "  And laugh heartily.";
}