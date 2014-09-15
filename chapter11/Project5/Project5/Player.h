#pragma once
#include<string>

using namespace std;

class Player
{
public:
	Player(string name);
	virtual ~Player();
	const string& GetName( ) const;
	virtual void GetChoice() const = 0;
private:
	string m_name;
};