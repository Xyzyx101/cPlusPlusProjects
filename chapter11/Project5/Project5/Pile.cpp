#include<iostream>
#include "Pile.h"

using namespace std;

Pile::Pile( )
{
	m_sticks = 13;
}

int Pile::GetSticks( ) const
{
	return m_sticks;
}

void Pile::RemoveSticks( int sticks )
{
	if( sticks > m_sticks )
	{
		cout << "You cannot remove " << sticks << " because there are only " << m_sticks << " left." << endl;
	}
	m_sticks -= sticks;
}
