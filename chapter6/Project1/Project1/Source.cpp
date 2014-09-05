#include<iostream>
#include<string>

using namespace std;

class Ship
{
public:
	Ship( string name = "Enterprise", int fuel = 0 );
	void Status() const;
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

int main()
{
	Ship vessel1;
	vessel1.Status();

	Ship vessel2( "Voyager", 10 );
	vessel2.Status();

	Ship vessel3( "Millenium Falcon", -10 );
	vessel3.Status();
	
	return 0;
}