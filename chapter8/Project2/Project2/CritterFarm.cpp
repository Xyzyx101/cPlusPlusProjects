#include "CritterFarm.h"
#include "Critter.h"
#include<iostream>
#include<string>
#include<time.h>

using namespace std;

CritterFarm::CritterFarm( )
{
	srand( (unsigned int)time( NULL ) );

	int hunger, boredom;
	for( int i = 0; i < CRITTER_COUNT; ++i )
	{
		hunger = rand( ) % 10;
		boredom = rand( ) % 10;
		m_critters[i] = new Critter( hunger, boredom );
	}
}
CritterFarm::~CritterFarm( )
{
	for( int i = 0; i < CRITTER_COUNT; ++i )
	{
		delete m_critters[i];
		m_critters[i] = 0;
	}
}
void CritterFarm::Talk( )
{
	for( int i = 0; i < CRITTER_COUNT; ++i )
	{
		m_critters[i]->Talk( );
		cout << endl;
	}
}

void CritterFarm::Eat( int food )
{
	for( int i = 0; i < CRITTER_COUNT; ++i )
	{
		m_critters[i]->Eat( );
	}
}

void CritterFarm::Play( int fun )
{
	for( int i = 0; i < CRITTER_COUNT; ++i )
	{
		m_critters[i]->Play( );
	}
}

void CritterFarm::Debug( ) const
{
	for( int i = 0; i < CRITTER_COUNT; ++i )
	{
		cout << "m_Hunger: " << m_critters[i]->m_Hunger << "  m_Boredom: " << m_critters[i]->m_Boredom << "  m_Alive: " << m_critters[i]->m_Alive << endl;
	}
}

void CritterFarm::PerformTrick( )
{
	for( int i = 0; i < CRITTER_COUNT; ++i )
	{
		m_critters[i]->PerformTrick( );
		cout << endl;
	}
}
