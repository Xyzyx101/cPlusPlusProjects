#include <iostream>
#include <string>
using namespace std;

int main()
{
	//  2  -- 7 and 3 are integers so it uses integer division
	cout << "Seven divided by three is " << 7 / 3 << endl;

	//  2.33333 -- a float cannot be divided by a int so 3 is converted to a float
	cout << "Seven divided by three is " << 7.0 / 3 << endl;

	// 2.33333  -- both numbers are floats
	cout << "Seven divided by three is " << 7.0 / 3.0 << endl;
	return 0;
}