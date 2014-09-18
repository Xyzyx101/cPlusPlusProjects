#pragma once
#include<string>

using namespace std;

class Player
{
public:
	Player(const string& name);
	virtual ~Player();
	const string& GetName() const;
	virtual int MakeMove(const int sticksRemaining) const = 0;
protected:
	string m_name;
};