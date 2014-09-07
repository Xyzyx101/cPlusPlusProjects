#include<iostream>
#include<string>
using namespace std;

class Player;
class Game
{
public:
	Game( const string& playerOneName, const string& playerTwoName );
	~Game();
	void NextTurn();
	void ClearChoices( );
	string GameOver(); // returns winners name or nobody if the game is a draw
	static enum CHOICE
	{
		NOCHOICE = 0,
		ROCK = 1,
		PAPER = 2,
		SCISSORS = 3
	};
private:
	bool playerOnesTurn;
	Player* players[2];
};

class Player
{
public:
	Player( string name );
	const string& GetName() const;
	void SetChoice( enum Game::CHOICE choice );
	const enum Game::CHOICE& GetChoice() const;
private:
	string m_name;
	Game::CHOICE m_choice;
};

Player::Player( string name )
:
m_name( name )
{
}

const string& Player::GetName() const
{
	return m_name;
}

void Player::SetChoice( enum Game::CHOICE choice )
{
	m_choice = choice;
}

const enum Game::CHOICE& Player::GetChoice() const
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

Game::~Game()
{
	delete players[0];
	players[0] = NULL;
	delete players[1];
	players[1] = NULL;
}

void Game::ClearChoices()
{
	players[0]->SetChoice( NOCHOICE );
	players[1]->SetChoice( NOCHOICE );
}

void Game::NextTurn()
{
	playerOnesTurn = !playerOnesTurn;

	Player* currentPlayer = playerOnesTurn ? players[0] : players[1];

	bool validValue = false;
	int choice;
	while( !validValue )
	{
		cout << string( 100, '\n' );
		cout << "It is " << currentPlayer->GetName() << "'s turn." << endl;
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

string Game::GameOver()
{
	if( players[0]->GetChoice() == players[1]->GetChoice() )
	{
		cout << "Nobody";
		return "";
	}
	if( players[0]->GetChoice() == ROCK )
	{
		if( players[1]->GetChoice() == PAPER )
		{
			return players[1]->GetName();
		}
		else if( players[1]->GetChoice() == SCISSORS )
		{
			return players[0]->GetName();
		}
	}
	if( players[0]->GetChoice() == PAPER )
	{
		if( players[1]->GetChoice() == SCISSORS )
		{
			return players[1]->GetName();
		}
		else if( players[1]->GetChoice() == ROCK )
		{
			return players[0]->GetName();
		}
	}
	if( players[0]->GetChoice( ) == SCISSORS)
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

int main()
{
	cout << "\tWelcome to Rock Paper Scissors" << endl << endl;

	string playerOneName, playerTwoName;
	cout << "Player 1 enter your name : ";
	cin >> playerOneName;
	cout << endl << "Player 2 enter your name : ";
	cin >> playerTwoName;

	Game game( playerOneName, playerTwoName );

	string playAgain;
	while( playAgain != "q" )
	{
		game.ClearChoices();
		game.NextTurn();
		game.NextTurn();
		cout << game.GameOver( ) << " wins!" << endl << endl;
		cout << "Enter q to quit or anything else to play again :";
		cin >> playAgain;
	}
	
	return 0;
};