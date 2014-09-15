#include "Sword.h"
#include<iostream>

using namespace std;

Sword::Sword(int damage) :
Weapon(damage)
{}

Sword::~Sword()
{}

void Sword::Attack()
{
	cout << "Sword inflicts " << m_Damage << " points of damage." << endl;
}