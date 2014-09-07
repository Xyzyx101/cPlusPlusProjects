#pragma once

#include "CritterFarm.h"
#include<string>

using namespace std;

class Critter
{
	friend void CritterFarm::Debug( ) const;

public:
	Critter( int hunger = 0, int boredom = 0 );
	void Talk( );
	void Eat( int food = 4 );
	void Play( int fun = 4 );
	void PerformTrick( );
private:
	int m_Hunger;
	int m_Boredom;
	static const int NUM_TRICKS = 3;
	string tricks[NUM_TRICKS];
	int GetMood( ) const;
	void PassTime( int time = 1 );
	bool m_Alive;
};
