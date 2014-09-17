#include "Game.h"

#include<iostream>
#include<string>
#include"Tree.h"

using namespace std;

Game::Game()
{
}

void Game::DisplayInstruction()
{
	cout << "\nWelcome to Famous and Infamous";
	cout << endl << endl;
	cout << "Think of a famous or infamous person ";
	cout << "and I'll try to guess his or her name.";
	cout << endl << endl;
}

void Game::Play()
{
	m_Tree.Reset();

	char response;
	while( m_Tree.DisplayCurrentQuestion() )
	{
		response = m_Tree.AskYesNo();
		m_Tree.NextQuestion( response );
	}

	response = m_Tree.AskYesNo();
	if( response == m_Tree.YES )
	{
		cout << "I guessed it!" << endl;
	}
	else
	{
		cout << "I give up." << endl;
		m_Tree.AddPerson();
	}
}

void Game::DisplayAllQuestions()
{
	m_Tree.DisplayQuestions();
}