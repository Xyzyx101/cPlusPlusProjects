#include "Game.h"
#include "Player.h"
#include<iostream>

const enum Game::CHOICE& Player::GetChoice( ) const
{
	return m_choice;
}

Game::Game( const string& playerOneName, const string& playerTwoName )
{
	players[0] = new Player( playerOneName );
	players[1] = new Player( playerTwoName );

	//it starts false because it is flipped at the begining of each turn and I want 1 to go first
	playerOnesTurn = false;
}

Game::~Game( )
{
	delete players[0];
	players[0] = NULL;
	delete players[1];
	players[1] = NULL;
}

void Game::ClearChoices( )
{
	players[0]->SetChoice( NOCHOICE );
	players[1]->SetChoice( NOCHOICE );
}

void Game::NextTurn( )
{
	playerOnesTurn = !playerOnesTurn;

	Player* currentPlayer = playerOnesTurn ? players[0] : players[1];

	bool validValue = false;
	int choice;
	while( !validValue )
	{
		cout << string( 100, '\n' );
		cout << "It is " << currentPlayer->GetName( ) << "'s turn." << endl;
		cout << "1 - Rock" << endl;
		cout << "2 - Paper" << endl;
		cout << "3 - Scissors" << endl;
		cout << "Choose : ";
		cin >> choice;
		if( choice > 0 &&
			choice <= 3 )
		{
			validValue = true;
		}
		else
		{
			cout << "Choose a number between 1 and 3." << endl;
		}
	}
	CHOICE enumChoice = static_cast<CHOICE>(choice);
	currentPlayer->SetChoice( enumChoice );
}

string Game::GameOver( )
{
	if( players[0]->GetChoice( ) == players[1]->GetChoice( ) )
	{
		cout << "Nobody";
		return "";
	}
	if( players[0]->GetChoice( ) == ROCK )
	{
		if( players[1]->GetChoice( ) == PAPER )
		{
			return players[1]->GetName( );
		}
		else if( players[1]->GetChoice( ) == SCISSORS )
		{
			return players[0]->GetName( );
		}
	}
	if( players[0]->GetChoice( ) == PAPER )
	{
		if( players[1]->GetChoice( ) == SCISSORS )
		{
			return players[1]->GetName( );
		}
		else if( players[1]->GetChoice( ) == ROCK )
		{
			return players[0]->GetName( );
		}
	}
	if( players[0]->GetChoice( ) == SCISSORS )
	{
		if( players[1]->GetChoice( ) == ROCK )
		{
			return players[1]->GetName( );
		}
		else if( players[1]->GetChoice( ) == PAPER )
		{
			return players[0]->GetName( );
		}
	}
	return "";
}