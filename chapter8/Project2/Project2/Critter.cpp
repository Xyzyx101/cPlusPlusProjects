#include<iostream>
#include<string>
#include "Critter.h"

using namespace std;

Critter::Critter( int hunger, int boredom ) :
m_Hunger( hunger ),
m_Boredom( boredom )
{
	m_Alive = true;
	tricks[0] = "play dead";
	tricks[1] = "do a backflip";
	tricks[2] = "roll over";
}

inline int Critter::GetMood( ) const
{
	return (m_Hunger + m_Boredom);
}

void Critter::PassTime( int time )
{
	m_Hunger += time;
	m_Boredom += time;
	if( m_Hunger > 15 || GetMood( ) > 32 )
	{
		m_Alive = false;
	}
}

void Critter::Talk( )
{
	if( !m_Alive )
	{
		cout << "Your critter is dead.";
		return;
	}

	string hungryString, boredomString;
	cout << "I'm a critter and I feel ";
	if( m_Boredom > 12 )
	{
		boredomString = "miserable";
	}
	else if( m_Boredom > 8 )
	{
		boredomString = "bored";
	}
	else if( m_Boredom > 4 )
	{
		boredomString = "indifferent";
	}
	else
	{
		boredomString = "happy";
	}

	if( m_Hunger > 12 )
	{
		hungryString = "starving";
	}
	else if( m_Hunger > 8 )
	{
		hungryString = "hungry";
	}
	else if( m_Hunger > 4 )
	{
		hungryString = "slightly hungry";
	}
	else
	{
		hungryString = "full";
	}
	cout << boredomString << " and " << hungryString;

	PassTime( );
}

void Critter::Eat( int food )
{
	if( !m_Alive )
	{
		cout << "Your critter will not eat." << endl;
		return;
	}
	cout << "Brruppp.\n";
	m_Hunger -= food;
	if( m_Hunger < 0 )
	{
		m_Hunger = 0;
	}

	PassTime( );
}

void Critter::Play( int fun )
{
	if( !m_Alive )
	{
		cout << "Your critter will not play." << endl;
		return;
	}
	cout << "Wheee!\n";

	m_Boredom -= fun;
	if( m_Boredom < 0 )
	{
		m_Boredom = 0;
	}

	PassTime( );
}

void Critter::PerformTrick( )
{
	if( !m_Alive )
	{
		cout << "Your critter doesn't move." << endl;
		return;
	}
	if( GetMood( ) > 8 )
	{
		cout << "I don't feel like doing a trick." << endl;
	}
	else
	{
		int choice = (rand( ) % Critter::NUM_TRICKS);
		cout << "I will " << tricks[choice] << "." << endl;
	}

	PassTime( );
}