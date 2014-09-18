#include<iostream>
#include"Game.h"

using namespace std;

int main()
{
	Game famousInfamous;
	famousInfamous.InitTree();

	famousInfamous.DisplayInstruction();

	char again;
	do
	{
		famousInfamous.Play();
		cout << endl << "Play again? (y/n): ";
		cin >> again;
	} while( again == 'y' );
	
	cout << endl;
	famousInfamous.SaveTree();

	return 0;
}