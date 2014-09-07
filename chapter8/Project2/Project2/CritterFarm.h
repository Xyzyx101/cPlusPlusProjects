#pragma once
class Critter;
class CritterFarm
{
public:
	CritterFarm( );
	~CritterFarm( );
	void Talk( );
	void Eat( int food = 4 );
	void Play( int fun = 4 );
	void Debug( ) const;
	void PerformTrick( );
private:
	static const int CRITTER_COUNT = 5;
	Critter* m_critters[CRITTER_COUNT];
};