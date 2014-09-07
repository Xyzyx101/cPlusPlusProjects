#include<iostream>
#include<string>
using namespace std;

class Pile
{
public:
	Pile();
	int GetSticks() const;
	void RemoveSticks(int sticks);
private:
	int m_sticks;
};

class Player
{
public:
	Player();
	Player( string name );
	const string& GetName() const;
private:
	string m_name;
};

class Game
{
public:
	Game( const string& playerOneName, const string& playerTwoName );
	void NextTurn();
	string GameOver(); // returns winners name or "" if the game is still going
private:
	bool playerOnesTurn;
	Player player1;
	Player player2;
	Pile pile;
};


Player::Player()
{

}

Player::Player(string name )
:
m_name(name)
{
}

const string& Player::GetName() const
{
	return m_name;
}

Pile::Pile()
{
	m_sticks = 13;
}

int Pile::GetSticks() const
{
	return m_sticks;
}

void Pile::RemoveSticks( int sticks )
{
	if( sticks > m_sticks )
	{
		cout << "You cannot remove " << sticks << " because there are only " << m_sticks << " left." << endl;
	}
	m_sticks -= sticks;
}

Game::Game( const string& playerOneName, const string& playerTwoName )
{
	player1 = Player( playerOneName );
	player2 = Player( playerTwoName );
	pile = Pile();

	//it starts false because it is flipped at the begining of each turn and I want 1 to go first
	playerOnesTurn = false; 
}

void Game::NextTurn()
{
	playerOnesTurn = !playerOnesTurn;

	string currentPlayerName = playerOnesTurn ? player1.GetName() : player2.GetName();
	cout << "There are " << pile.GetSticks() << " sticks left." << endl;
	
	bool validValue = false;
	int sticksToRemove;
	while( !validValue )
	{
		cout << endl;
		cout << "It is " << currentPlayerName << "'s turn." << endl;
		cout << "How many sticks do you want to remove? : ";
		cin >> sticksToRemove;
		if( sticksToRemove > 0 &&
			sticksToRemove <= 4 &&
			sticksToRemove <= pile.GetSticks() )
		{
			validValue = true;
		}
		else
		{
			cout << sticksToRemove << " is not a valid number." << endl;
		}
	}
	pile.RemoveSticks( sticksToRemove );
}

string Game::GameOver()
{
	if( pile.GetSticks() == 0 )
	{
		return playerOnesTurn ? player1.GetName( ) : player2.GetName( );
	}
	return "";
}

int main( )
{
	cout << "\tWelcome to Nim" << endl << endl;
	cout << "The game starts with 13 sticks.  Each player removes between 1 and 4 sticks until they are gone. ";
	cout << "The player whole removes the last stick wins." << endl << endl;

	string playerOneName, playerTwoName;
	cout << "Player 1 enter your name : ";
	cin >> playerOneName;
	cout << endl << "Player 2 enter your name : ";
	cin >> playerTwoName;

	Game game( playerOneName, playerTwoName );

	while( game.GameOver() == "" )
	{
		game.NextTurn();
	}
	cout << game.GameOver() << " wins!" << endl << endl;
	return 0;
};