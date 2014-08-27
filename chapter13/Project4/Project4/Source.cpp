//Inventory System

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector<string> inventory;
	vector<string> roomContents = { "Lamp", "Bacon", "YoMoma" };

	cout << "Use the commands - look, inventory, get, drop - to manipulate you inventory.  Type quit to leave." << endl;

	do
	{
		cout << ">> ";
		string command;
		cin >> command;
		if (command == "look")
		{
			if (roomContents.size() == 0) {
				cout << "The room is empty" << endl;
			}
			else
			{
				cout << "There are items in the room: " << endl;
				for (auto it = roomContents.begin(); it != roomContents.end(); ++it)
				{
					cout << *it << endl;
				}
			}

		}
		else if (command == "inventory")
		{
			if (inventory.size() == 0) {
				cout << "Your inventory is empty" << endl;
			}
			else
			{
				cout << "Your inventory: " << endl;
				for (auto it = inventory.begin(); it != inventory.end(); ++it)
				{
					cout << *it << endl;
				}
			}
		}
		else if (command == "get")
		{
			if (roomContents.size() == 0){
				cout << "The room is empty" << endl;
			}
			else
			{
				string item;
				cout << endl << "Which item would you like to pick up? : ";
				cin >> item;
				auto itemIter = find(roomContents.begin(), roomContents.end(), item);
				if (itemIter == roomContents.end())
				{
					cout << "That item is not in the room" << endl;
				}
				else
				{
					cout << "You picked up a " << *itemIter << endl;
					inventory.push_back(*itemIter);
					roomContents.erase(itemIter);
				}
			}
		}
		else if (command == "drop")
		{
			if (inventory.size() == 0) {
				cout << "You have nothing to drop" << endl;
			}
			else
			{
				string item;
				cout << endl << "Which item would you like to drop? : ";
				cin >> item;
				auto itemIter = find(inventory.begin(), inventory.end(), item);
				if (itemIter == inventory.end())
				{
					cout << "You don't have a " << *itemIter;
				}
				else
				{
					cout << "You have dropped a " << *itemIter << endl;
					roomContents.push_back(*itemIter);
					inventory.erase(itemIter);
				}
			}
		}
		else if (command == "quit")
		{
			break;
		}
		else
		{
			cout << "That is not a valid command";
			cin.clear();
		}
	} while (true);
}
