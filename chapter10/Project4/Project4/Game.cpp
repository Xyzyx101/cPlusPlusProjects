#include "Game.h"
#include<iostream>

Game::Game()
{
	for( int i = 0; i < NUM_OF_PEGS; ++i )
	{
		pegs[i] = new Stack();
	}
}

Game::~Game()
{
	for( int i = 0; i < NUM_OF_PEGS; ++i )
	{
		delete pegs[i];
	}
}

void Game::DisplayIntro()
{
	cout << "Tower of Hanoi" << endl;
	cout << "The object of the game is to move the stack of disks from the first peg to the last peg." << endl;
	cout << " - you may only move one disk at a time" << endl;
	cout << " - you may only move the top disk on a peg" << endl;
	cout << " - you may not place a larger disk on top of a smaller one" << endl << endl;
}

void Game::Setup()
{
	pegs[0]->Push(4);
	pegs[0]->Push(3);
	pegs[0]->Push(2);
	pegs[0]->Push(1);
}

void Game::Display()
{
	cout << "Peg 1:" << endl;
	pegs[0]->Display();
	cout << endl;

	cout << "Peg 2:" << endl;
	pegs[1]->Display();
	cout << endl;

	cout << "Peg 3:" << endl;
	pegs[2]->Display();
	cout << endl;
}

bool Game::GameOver()
{
	return pegs[2]->Count() == 4;
}

void Game::NextTurn()
{
	int from, to;
	cout << "Which peg do you want to move a disk from? ";
	cin >> from;
	if( from < 1 || 3 < from )
	{
		cout << "You must choose a peg from 1 to 3" << endl;
		return;
	}
	cout << endl << "Which peg do you want to move the disk to? ";
	cin >> to;
	if( to < 1 || 3 < to )
	{
		cout << "You must choose a peg from 1 to 3" << endl;
		return;
	}
	
	--from; --to; //correct for base 0
	
	// checks that disk is small than the top of the stack
	// -1 is an empty peg and any disk can go there
	if( pegs[to]->Top() != -1 &&
		pegs[from]->Top() > pegs[to]->Top() )
	{
		cout << "You may not place a larger disk on a smaller one" << endl;
		return;
	}
	TransferDisk(pegs[from], pegs[to]);
}

void Game::TransferDisk(Stack* from, Stack* to)
{
	to->Push(from->Top());
	from->Pop();
}
