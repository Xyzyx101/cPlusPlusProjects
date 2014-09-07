#pragma once
#include<string>

using namespace std;

class Player
{
public:
	Player( );
	Player( string name );
	const string& GetName( ) const;
private:
	string m_name;
};