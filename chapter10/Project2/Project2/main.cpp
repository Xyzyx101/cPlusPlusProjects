// Fox, Chicken, and Grain - classic puzzle 
// Main function

#include <iostream>
#include "List.h"

using namespace std;

void TestCopyConstructor( List list );

int main()
{
    List list1, list2;
    
	list1.Add( "fox" );
	list1.Add( "chicken" );
	list1.Add( "grain" );
    
	cout << "List1" << endl;
	list1.Display();

	// testing overloaded = operator to mkae a deep copy of the list
	list2 = list1;
	
	
	list2.Remove( "chicken" );
	cout << endl << "List2" << endl;
	list2.Display( );
	
	cout << endl << "List1" << endl;
	list1.Display();
	
	

    return 0;
}
