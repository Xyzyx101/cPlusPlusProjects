//Inventory System

#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	vector<string> inventory;
	vector<string> roomContents;

	cout << "Use the commands - look, inventory, get, drop - to manipulate you inventory.  Type quit to leave." << endl;
	
	do
	{
		cout << ">> ";
		string command;
		cin >> command;
		if( command == "look" )
		{

		}
		else if( command == "inventory" )
		{

		}
		else if( command == "get" )
		{

		}
		else if( command == "drop" )
		{

		}
		else if( command == "quit" )
		{
			break;
		}
		else
		{
			cout << "That is not a valid command";
			cin.clear();
		}
	} while( true );
}
