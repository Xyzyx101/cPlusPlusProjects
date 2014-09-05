
#include <iostream>
#include<string>

using namespace std;

class Handheld
{
public:
	Handheld();
	void TogglePower();
	void DisplayGames() const;
	void Play() const;
	void SetGameNumber( int newGameNumber );
	void RaiseVolume();
	void LowerVolume();
private:
	static const int NUM_GAMES = 3;
	static const int MIN_VOLUME = 0;
	static const int MAX_VOLUME = 10;
	static const int NO_GAME = -1;
	static const string GAMES[];
	bool m_IsOn;
	int m_GameNumber;
	int m_Volume;
};

const string Handheld::GAMES[] = { "Generic Mascot Platformer",
                                   "Overly Cute Kart Racer",
								   "Derivative Block Puzzler" };
Handheld::Handheld()
{
	m_IsOn = false;
	m_GameNumber = Handheld::NO_GAME; //-1 is no game selected
	m_Volume = 5;
}

void Handheld::TogglePower()
{
	m_IsOn = !m_IsOn;
	if( m_IsOn )
	{
		cout << "The device is now on." << endl;
	}
	else
	{
		cout << "The device is now off." << endl;
	}
}

void Handheld::DisplayGames() const
{
	for( size_t i = 0; i < Handheld::NUM_GAMES; ++i )
	{
		cout << "\t" << i << " )\t" << Handheld::GAMES[i] << endl;
	}
}

void Handheld::Play() const
{
	if( !m_IsOn )
	{
		cout << "The device is not on." << endl;
	}
	else if( m_GameNumber == Handheld::NO_GAME )
	{
		cout << "Select a game to play first." << endl;
	}
	else
	{
		cout << "Yippee..." << Handheld::GAMES[m_GameNumber] << " is fun." << endl;
	}
}

void Handheld::SetGameNumber( int newGameNumber )
{
	if( m_IsOn )
	{
		if( newGameNumber < 0 || newGameNumber > Handheld::NUM_GAMES - 1 )
		{
			cout << "That is an invalid game number" << endl;
		}
		else
		{
			m_GameNumber = newGameNumber;
		}
	}
	else
	{
		cout << "The device is not on." << endl;
	}
}

void Handheld::RaiseVolume()
{
	if( m_Volume < Handheld::MAX_VOLUME )
	{
		++m_Volume;
		cout << "Volume level " << m_Volume << endl;
	}
	else
	{
		cout << "It is at full volume already." << endl;
	}
}

void Handheld::LowerVolume()
{
	if( m_Volume > 0)
	{
		--m_Volume;
		cout << "Volume level " << m_Volume << endl;
	}
	else
	{
		cout << "It is at the lowest volume already." << endl;
	}
}

int main()
{
	Handheld handheld;

	int choice = -1 ,gameChoice;
	while( choice != 0 )
	{
		cout << "\nHandheld Game Whatsit\n";
		cout << "0 - Quit\n";
		cout << "1 - Toggle System Power\n";
		cout << "2 - Select Game\n";
		cout << "3 - Raise Volume\n";
		cout << "4 - Lower Volume\n";
		cout << "5 - Play the Game\n\n";

		cout << "Choice: ";
		cin >> choice;

		switch( choice )
		{
		case 0:
			cout << "Bye" << endl;
			break;
		case 1:
			handheld.TogglePower();
			break;
		case 2:
			handheld.DisplayGames();
			cout << "Which game would you like to play :> ";
			cin >> gameChoice;
			cout << endl;
			handheld.SetGameNumber( gameChoice );
			break;
		case 3:
			handheld.RaiseVolume();
			break;
		case 4:
			handheld.LowerVolume();
			break;
		case 5:
			handheld.Play();
			break;
		default:
			cout << "\nSorry, but " << choice << " isn't a valid choice.\n";
		}
	}
	return 0;
}

