#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
	//seed the rng
	srand(static_cast<unsigned int>(time(0)));

	const int MAX_NUMBER = 100;

	//random number between 1 and 100
	int secretNumber = (rand() % MAX_NUMBER) + 1;
	int tries = 0;
	int guess;

	cout << "\t Welcome to Guess My Number" << endl << endl;
	cout << "Guess my secret number between 1 and ";
	cout << MAX_NUMBER << "." << endl << endl;

	do
	{
		cout << "Enter a guess: ";
		cin >> guess;
		
		if( guess > secretNumber )
		{
			cout << "Too high!" << endl << endl;
		}
		if( guess < secretNumber )
		{
			cout << "Too low" << endl << endl;
		}
		++tries;
	} while( guess != secretNumber && tries < 6);
	cout << endl;
	if( guess == secretNumber )
	{
		cout << "You win! You got it in " << tries << " tries!";
	}
	else
	{
		cout << "You suck" << endl;
	}


	return 0;
}