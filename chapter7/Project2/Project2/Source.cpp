//Critter Farm
//Simulates caring for a bunch of virtual pets

#include<iostream>
#include<string>
#include<time.h>

using namespace std;

class Critter;

class CritterFarm
{
public:
	CritterFarm();
	~CritterFarm();
	void Talk();
	void Eat( int food = 4 );
	void Play( int fun = 4 );
	void Debug() const;
	void PerformTrick();
private:
	static const int CRITTER_COUNT = 5;
	Critter* m_critters[CRITTER_COUNT];
};

class Critter
{
	friend void CritterFarm::Debug() const;

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
CritterFarm::~CritterFarm()
{
	for( int i = 0; i < CRITTER_COUNT; ++i )
	{
		delete m_critters[i];
		m_critters[i] = 0;
	}
}
void CritterFarm::Talk()
{
	for( int i = 0; i < CRITTER_COUNT; ++i )
	{
		m_critters[i]->Talk();
		cout << endl;
	}
}

void CritterFarm::Eat(int food)
{
	for( int i = 0; i < CRITTER_COUNT; ++i )
	{
		m_critters[i]->Eat( );
	}
}

void CritterFarm::Play(int fun)
{
	for( int i = 0; i < CRITTER_COUNT; ++i )
	{
		m_critters[i]->Play( );
	}
}

void CritterFarm::Debug() const
{
	for( int i = 0; i < CRITTER_COUNT; ++i )
	{
		cout << "m_Hunger: " << m_critters[i]->m_Hunger << "  m_Boredom: " << m_critters[i]->m_Boredom << "  m_Alive: " << m_critters[i]->m_Alive << endl;
	}
}

void CritterFarm::PerformTrick()
{
	for( int i = 0; i < CRITTER_COUNT; ++i )
	{
		m_critters[i]->PerformTrick( );
		cout << endl;
	}
}

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

int main( )
{
	CritterFarm critterFarm;

	int choice = 1;  //start the critter off talking
	while( choice != 0 )
	{
		cout << "\nCritter Farm Caretaker\n\n";
		cout << "0 - Quit\n";
		cout << "1 - Listen to your critters\n";
		cout << "2 - Feed your critters\n";
		cout << "3 - Play with your critters\n";
		cout << "4 - Ask you critters to do tricks\n\n";

		cout << "Choice: ";
		cin >> choice;

		switch( choice )
		{
		case -1:
			critterFarm.Debug( );
			break;
		case 0:
			cout << "Good-bye.\n";
			break;
		case 1:
			critterFarm.Talk( );
			break;
		case 2:
			critterFarm.Eat( );
			break;
		case 3:
			critterFarm.Play( );
			break;
		case 4:
			critterFarm.PerformTrick( );
			break;
		default:
			cout << "\nSorry, but " << choice << " isn't a valid choice.\n";
		}
	}
	return 0;
}

