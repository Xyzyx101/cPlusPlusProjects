#pragma once

#include<string>
#include"Tree.h"

using namespace std;

class Game
{
public:
	Game();
	void DisplayInstruction();
	void Play();
private:
	Tree m_Tree;
};
