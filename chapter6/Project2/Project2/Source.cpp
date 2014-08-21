#include<iostream>
#include <stdlib.h>
#include <time.h> 

using namespace std;

int randomNumber(int high);
int randomNumber(int low, int high);

int main()
{
	srand(time(0));
	
	cout << "Random numbers for 0 to 5\n" << endl;
	for( unsigned int i = 0; i < 10; ++i )
	{
		cout << randomNumber(6) << endl;
	}

	cout << "Random numbers from 3 to 6" << endl;
	for( unsigned int i = 0; i < 10; ++i )
	{
		cout << randomNumber(3, 6) << endl;
	}
}

int randomNumber(int high)
{
	return rand() % high;
}

int randomNumber(int low, int high)
{
	return rand() % (high - low + 1) + low;
}