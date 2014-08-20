#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
	const int MAX_NUMBER = 100;


	//random number between 1 and 100
	int secretNumber;
	int tries = 0;
	int guess;
	int highestGuess = MAX_NUMBER + 1;
	int lowestGuess = 0;
	int menuChoice;
	enum choice {
			TOO_HIGH = 1, 
			TOO_LOW = 2, 
			CORRECT = 3};

	cout << "\t Welcome to Guess Your Number" << endl << endl;
	cout << "Pick a secret number between 1 and ";
	cout << MAX_NUMBER << " and I will try to guess" << endl;

	cin >> secretNumber;
	do
	{
		guess = (highestGuess - lowestGuess) / 2 + lowestGuess;
		cout << "I guess " << guess << endl;
		cout << "Is my guess:" << endl;
		cout << "1) Too high" << endl;
		cout << "2) Too low" << endl;
		cout << "3) Correct" << endl;
		cout << "Enter Selection: ";
		cin >> menuChoice;
		if( menuChoice == choice::TOO_HIGH )
		{
			highestGuess = guess;
		}
		else if( menuChoice == choice::TOO_LOW )
		{
			lowestGuess = guess;
		}
		tries++;
	} while( menuChoice != choice::CORRECT );
	cout << "I won in " << tries << " ties.";
	return 0;
}