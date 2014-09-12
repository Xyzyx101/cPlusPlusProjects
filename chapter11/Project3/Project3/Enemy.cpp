#include "Enemy.h"
#include<iostream>


Enemy::Enemy(int damage) 
{
	m_pDamage = new int(damage);
}

Enemy::~Enemy()
{
	delete m_pDamage;
}

Enemy::Enemy(const Enemy& other)
{
	int otherDamage = *(other.m_pDamage);
	m_pDamage = new int(otherDamage);
}

void Enemy::Attack()
{
	std::cout << "Enemy attacks for " << *m_pDamage << std::endl;
}

void Enemy::Taunt()
{
	std::cout << "I will defeat you.";
}