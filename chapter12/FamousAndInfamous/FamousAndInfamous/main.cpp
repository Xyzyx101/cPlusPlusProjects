#include<iostream>
#include"Game.h"

using namespace std;

int main()
{
	Game famousInfamous;
	char again;

	famousInfamous.DisplayInstruction();

	do
	{
		famousInfamous.Play();
		cout << endl << "Play again? (y/n): ";
		cin >> again;
	} while( again == 'y' );
	
	return 0;
}