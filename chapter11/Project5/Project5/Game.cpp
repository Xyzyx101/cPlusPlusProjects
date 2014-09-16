#include<iostream>
#include "Game.h"
#include"PlayerHuman.h"
#include"PlayerComputer.h"

using namespace std;

Game::Game(  )
{
	player1 = nullptr;
	player2 = nullptr;
	pile = Pile( );

	//it starts false because it is flipped at the begining of each turn and I want 1 to go first
	playerOnesTurn = false;
}

void Game::InitGame()
{
	string playerOneName, playerTwoName;
	bool playerOneIsAI, playerTwoIsAI;
	int input;

	cout << "Player 1 enter your name : ";
	cin >> playerOneName;
	cout << "Is " << playerOneName << " (1)Computer controlled or (2)Human Controlled : ";
	cin >> input;
	playerOneIsAI = input == 1;

	cout << endl;
	cout << "Player 2 enter your name : ";
	cin >> playerTwoName;
	cout << "Is " << playerTwoName << " (1)Computer controlled or (2)Human Controlled : ";
	cin >> input;
	playerTwoIsAI = input == 1;
	
	if( playerOneIsAI )
	{
		player1 = new PlayerComputer( playerOneName );
	}
	else
	{
		player1 = new PlayerHuman( playerOneName );
	}
	if( playerTwoIsAI )
	{
		player2 = new PlayerComputer( playerTwoName );
	}
	else
	{
		player2 = new PlayerHuman( playerTwoName );
	}
}

Game::~Game()
{
	/* I didn't want to put player input in the constructor so there 
	the if statements are required in case InitGame is never run.
	*/
	if( player1 )
	{
		delete player1;
	}
	if( player2 )
	{
		delete player2;
	}
}

void Game::NextTurn( )
{
	playerOnesTurn = !playerOnesTurn;

	string currentPlayerName = playerOnesTurn ? player1->GetName( ) : player2->GetName( );
	cout << "There are " << pile.GetSticks( ) << " sticks left." << endl;
	cout << endl;
	cout << "It is " << currentPlayerName << "'s turn." << endl;
	cout << "How many sticks do you want to remove? : ";

	int sticksToRemove;
	if( playerOnesTurn )
	{
		sticksToRemove = player1->MakeMove( pile.GetSticks() );
	}
	else
	{
		sticksToRemove = player2->MakeMove( pile.GetSticks( ) );
	}
	pile.RemoveSticks( sticksToRemove );
}

string Game::GameOver( )
{
	if( pile.GetSticks( ) == 0 )
	{
		return playerOnesTurn ? player1->GetName( ) : player2->GetName( );
	}
	return "";
}