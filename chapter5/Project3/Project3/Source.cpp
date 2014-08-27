// Inventory
// Manages a player's inventory

#include<iostream>
#include<string>

using namespace std;

void Initialize(const string* container[], int capacity);
bool isFull(const string* const container[], int capacity);
bool isEmpty(const string* const container[], int capacity);
bool Contains(const string* const pItem, const string* container[], int capacity);
void Display(const string* const container[], int capacity);
void Add(const string* const pItem, const string* container[], int capacity);
void Remove(const string* const pItem, const string* container[], int capacity);

int main()
{
	cout << "\tWelcome to Inventory!" << endl;

	//items
	const int NUM_ITEMS = 5;
	const string items[NUM_ITEMS] = { 
		"sword",
		"axe",
		"shield",
		"gold",
		"potion" };

	//inventory
	const int INVENTORY_CAPACITY = 3;
	const string* inventory[INVENTORY_CAPACITY];
	Initialize(inventory, INVENTORY_CAPACITY);

	int choice;
	int itemNumber;

	do
	{
		cout << endl << "Inventory" << endl;
		cout << "---------" << endl << endl;
		cout << "0 - Quit" << endl;
		cout << "1 - Display items in the inventory" << endl;
		cout << "2 - Add an item to the inventory" << endl;
		cout << "3 - Remove an item from the inventory" << endl;
		cout << endl << "Choice: ";
		cin >> choice;
		cout << endl;

		switch( choice )
		{
		case 0:
			cout << "Good-bye." << endl;
			break;
		case 1:
			cout << "Inventory:" << endl;
			Display(inventory, INVENTORY_CAPACITY);
			break;
		case 2:
			for( int i = 0; i < NUM_ITEMS; ++i )
			{
				cout << i << " - " << items[i] << endl;
			}

			do
			{
				cout << "Enter the number of the item to add: ";
				cin >> itemNumber;
			} while( itemNumber < 0 || itemNumber >= NUM_ITEMS );

			//pass address of element items[itemNumber]
			Add(&items[itemNumber], inventory, INVENTORY_CAPACITY);
			break;
		case 3:
			for( int i = 0; i < NUM_ITEMS; ++i )
			{
				cout << i << " - " << items[i] << endl;
			}

			do
			{
				cout << "Enter the number of the item to remove: ";
				cin >> itemNumber;
			} while( itemNumber < 0 || itemNumber >= NUM_ITEMS );

			//pass address of element items[itemNumber]
			Remove(&items[itemNumber], inventory, INVENTORY_CAPACITY);
			break;
		}
	} while( choice != 0 );
	return 0;
}

void Initialize(const string* container[], int capacity)
{
	for( int i = 0; i < capacity; ++i )
	{
		container[i] = NULL;
	}
}

bool isFull(const string* const container[], int capacity)
{
	bool full = true;
	int i = 0;
	while( full && i < capacity )
	{
		//if there's at least one empty slot..
		if( container[i] == NULL )
		{
			//then the container isn't full
			full = false;
		}
		++i;
	}
	return full;
}

bool isEmpty(const string* const container[], int capacity)
{
	bool empty = true;
	int i = 0;

	while( empty && i < capacity )
	{
		//if a slot isn't empty
		if( container[i] != NULL )
		{
			//then the container isn't empty
			empty = false;
		}
		++i;
	}
	return empty;
}

bool Contains(const string* const pItem, const string* container[], int capacity)
{
	bool has = false;
	int i = 0;
	while( !has && i < capacity )
	{
		if( container[i] == pItem )
		{
			has = true;
		}
		++i;
	}
	return has;
}

void Display(const string* const container[], int capacity)
{
	if( isEmpty(container, capacity) )
	{
		cout << "<Empty>" << endl;
		return;
	}
	for( int i = 0; i < capacity; ++i )
	{
		if( container[i] != NULL )
		{
			cout << *(container[i]) << endl;
		}
	}
}

void Add(const string* const pItem, const string* container[], int capacity)
{
	if( pItem == NULL )
	{
		return;
	}
	if( Contains(pItem, container, capacity) )
	{
		cout << "Item already present. Can't add.";
		cout << endl;
		return;
	}
	if( isFull(container, capacity) )
	{
		cout << "Container full.  Can't add." << endl;
		return;
	}

	bool found = false;
	int i = 0;
	while( !found && i < capacity )
	{
		if( container[i] == NULL )
		{
			container[i] = pItem;
			found = true;
		}
		++i;
	}
}

void Remove(const string* const pItem, const string* container[], int capacity)
{
	if( pItem == NULL )
	{
		return;
	}

	bool found = false;
	int i = 0;
	while( !found && i < capacity){
		if( container[i] == pItem )
		{
			container[i] = NULL;
			found = true;
		}
		++i;
	}
	if( !found )
	{
		cout << "Item not found. Can't remove." << endl;
	}
}
