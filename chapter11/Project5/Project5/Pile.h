#pragma once
class Pile
{
public:
	Pile( );
	int GetSticks( ) const;
	void RemoveSticks( int sticks );
private:
	int m_sticks;
};