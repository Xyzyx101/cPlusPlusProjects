#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	vector<string> videoGames;
	do
	{
		cout << endl << endl << "\t\tMy Video Game List" << endl;
		for( auto it = videoGames.begin(); it != videoGames.end(); ++it )
		{
			cout << distance(videoGames.begin(), it) << ")\t\t" << *it << endl;
		}
		cout << "Would you like to (A)dd, (R)emove, or (Q)uit : ";
		string action;
		cin >> action;
		if( action == "A" || action == "a" )
		{
			string newGame;
			cout << endl << "Enter the name of the game : ";
			cin >> newGame;
			videoGames.push_back(newGame);
		}
		else if( action == "R" || action == "r" )
		{
			int gameIndex;
			cout << endl << "Enter the index number of the game to remove : ";
			cin >> gameIndex;
			videoGames.erase(videoGames.begin() + gameIndex);
		}
		else if( action == "Q" || action == "q" )
		{
			break;
		}
		else
		{
			cout << endl << "You must press a, r or q";
		}
	} while( true );
	return 0;
}

