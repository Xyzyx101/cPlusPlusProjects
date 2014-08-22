#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

const int MAX_NUMBER = 100;

void welcomePlayer();
void play(int aSecretNumber);
int askNumber(int low, int high);
int randomNumber(int low, int high);

int main()
{
	//seed the rng
	srand(static_cast<unsigned int>(time(0)));
	
	//random number between 1 and 100
	int secretNumber = randomNumber(1, MAX_NUMBER);
	int tries = 0;
	int guess;
	
	do
	{
		guess = askNumber(1, MAX_NUMBER);
		if( guess > secretNumber )
		{
			cout << "Too high!" << endl << endl;
		}
		if( guess < secretNumber )
		{
			cout << "Too low" << endl << endl;
		}
		++tries;
	} while( guess != secretNumber && tries < 6 );
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

void welcomePlayer()
{
	cout << "\t Welcome to Guess My Number" << endl << endl;
	cout << "Guess my secret number between 1 and ";
	cout << MAX_NUMBER << "." << endl << endl;
}

int askNumber(int low, int high)
{
	int validNumber = 0;
	int number;
	while( !validNumber )
	{
		cout << "\nEnter a number between " << low << " and " << high << " : ";
		cin >> number;
		if( number > high )
		{
			cout << "\nYour guess must be less than " << MAX_NUMBER << ".\n";
		}
		else if( number < low )
		{
			cout << "\nYour number must be greater than " << '1' << ".\n";
		}
		else
		{
			validNumber = number;
		}
	}
	return validNumber;
}

int randomNumber(int low, int high)
{
	return rand() % (high - low + 1) + low;
}