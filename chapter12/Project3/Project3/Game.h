#pragma once

#include<string>
#include"Tree.h"

using namespace std;

class Game
{
public:
	Game();
	~Game();
	void DisplayInstruction();
	void InitTree();
	void Play();
	void SaveTree();
private:
	Tree* m_Tree;
};
