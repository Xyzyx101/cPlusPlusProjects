#include "Enemy.h"
#include<iostream>


Enemy::Enemy(int damage) :
m_Damage(damage)
{}

void Enemy::Attack()
{
	std::cout << "Enemy attacks for " << m_Damage << std::endl;
}

void Enemy::Taunt()
{
	std::cout << "I will defeat you.";
}