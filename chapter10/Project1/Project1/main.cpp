// Fox, Chicken, and Grain - classic puzzle 
// Main function

#include <iostream>
#include "List.h"

using namespace std;


void TestCopyConstructor( List list );

int main()
{
    List list1;
    
	list1.Add( "fox" );
	list1.Add( "chicken" );
	list1.Add( "grain" );
    
	cout << "List1" << endl;
	list1.Display();

	TestCopyConstructor( list1 );
	
	// Without a copy constructor this will cause a crash because the lists are shllow copies.
	// When chicken is removed from the second list the first list still has a reference to the deleted variable on the heap.
	// The copy contructor makes a deep copy and the original list is unaffected by changes to the new list.
	cout << endl << "List1" << endl;
	list1.Display();
		
    return 0;
}

void TestCopyConstructor( List list )
{
	list.Remove( "chicken" );
	cout << endl << "List2" << endl;
	list.Display();
}
