//Critter Caretaker
//Simulates caring for a virtual pet

#include <iostream>
#include<string>

using namespace std;

class Critter
{
public:
	Critter( int hunger = 0, int boredom = 0 );
	void Talk( );
	void Eat( int food = 4 );
	void Play( int fun = 4 );
	void Debug( ) const;
	void PerformTrick();
private:
	int m_Hunger;
	int m_Boredom;
	static const int NUM_TRICKS = 3;
	string tricks[NUM_TRICKS];
	int GetMood( ) const;
	void PassTime( int time = 1 );
	bool m_Alive;
};

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
	if( m_Hunger > 15 || GetMood() > 32 )
	{
		m_Alive = false;
	}
}

void Critter::Talk( )
{
	if( !m_Alive )
	{
		cout << "Your critter is dead." << endl;
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

void Critter::PerformTrick()
{
	if( !m_Alive )
	{
		cout << "Your critter doesn't move." << endl;
		return;
	}
	if( GetMood() > 8 )
	{
		cout << "I don't feel like doing a trick." << endl;
	}
	else
	{
		int choice = (rand() % Critter::NUM_TRICKS);
		cout << "I will " << tricks[choice] << "." << endl;
	}

	PassTime();
}

void Critter::Debug( ) const
{
	cout << "m_Hunger: " << m_Hunger << "  m_Boredom: " << m_Boredom << "  m_Alive" << m_Alive << endl;
}

int main( )
{
	Critter crit;

	int choice = 1;  //start the critter off talking
	while( choice != 0 )
	{
		cout << "\nCritter Caretaker\n\n";
		cout << "0 - Quit\n";
		cout << "1 - Listen to your critter\n";
		cout << "2 - Feed your critter\n";
		cout << "3 - Play with your critter\n";
		cout << "4 - Ask you critter to do a trick\n\n";

		cout << "Choice: ";
		cin >> choice;

		switch( choice )
		{
		case -1:
			crit.Debug( );
			break;
		case 0:
			cout << "Good-bye.\n";
			break;
		case 1:
			crit.Talk( );
			break;
		case 2:
			crit.Eat( );
			break;
		case 3:
			crit.Play( );
			break;
		case 4:
			crit.PerformTrick( );
			break;
		default:
			cout << "\nSorry, but " << choice << " isn't a valid choice.\n";
		}
	}
	return 0;
}

