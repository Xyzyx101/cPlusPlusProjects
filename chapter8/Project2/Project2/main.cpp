//Critter Farm
//Simulates caring for a bunch of virtual pets

#include<iostream>
#include<string>
#include<time.h>

#include "CritterFarm.h"
#include "Critter.h"

using namespace std;

int main( )
{
	CritterFarm critterFarm;

	int choice = 1;  //start the critter off talking
	while( choice != 0 )
	{
		cout << "\nCritter Farm Caretaker\n\n";
		cout << "0 - Quit\n";
		cout << "1 - Listen to your critters\n";
		cout << "2 - Feed your critters\n";
		cout << "3 - Play with your critters\n";
		cout << "4 - Ask you critters to do tricks\n\n";

		cout << "Choice: ";
		cin >> choice;

		switch( choice )
		{
		case -1:
			critterFarm.Debug( );
			break;
		case 0:
			cout << "Good-bye.\n";
			break;
		case 1:
			critterFarm.Talk( );
			break;
		case 2:
			critterFarm.Eat( );
			break;
		case 3:
			critterFarm.Play( );
			break;
		case 4:
			critterFarm.PerformTrick( );
			break;
		default:
			cout << "\nSorry, but " << choice << " isn't a valid choice.\n";
		}
	}
	return 0;
}
