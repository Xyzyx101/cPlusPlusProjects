#include<iostream>
#include<string>

using namespace std;

class Ship
{
public:
	Ship( string name = "Enterprise", int fuel = 0 );
	void Status() const;
	void Move( int distance );
	void Refuel( int additionalFuel );
private:
	const string m_name;
	int m_fuel;
};

Ship::Ship( string name, int fuel ) :
m_name(name),
m_fuel(fuel)
{
	if( m_fuel < 0 )
	{
		m_fuel = 0;
	}
};

void Ship::Status() const
{
	cout << "The ship " << m_name << " has " << m_fuel << " fuel remaining." << endl;
}

void Ship::Move( int distance )
{
	if( distance > m_fuel )
	{
		cout << m_name << " cannot move " << distance << " because we do not have enough fuel." << endl;
	}
	else if( distance < 1 )
	{
		cout << m_name << " cannot move because moving " << distance << " distance makes no sense." << endl;
	}
	else {
		cout << m_name << " moving " << distance << "." << endl;
		m_fuel -= distance;
	}
	Status();
}

void Ship::Refuel( int additionalFuel )
{
	if( additionalFuel < 1 )
	{
		cout << m_name << " cannot refuel because adding " << additionalFuel << " additional fuel is very silly." << endl;
	}
	else
	{
		cout << m_name << " added " << additionalFuel << " additional fuel." << endl;
		m_fuel += additionalFuel;
	}
	Status();
}

int main()
{
	Ship enterprise( "Enterprise", 10 );
	enterprise.Status();
	enterprise.Move( 5 );
	enterprise.Move( 50 );
	enterprise.Move( -10 );
	enterprise.Refuel( 10 );
	enterprise.Refuel( -10 );
	return 0;
}