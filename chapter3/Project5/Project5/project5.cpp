#include<iostream>
#include<string>
#include<cstdlib>
// Binary Code Breaker

#include<ctime>
using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	cout << "\t\t\tBinary Code Breaker" << endl << endl << endl;
	cout << "Try to guess the 4 digit binary number." << endl;

	const size_t SECRET_DIGITS = 4;
	string secretNumber(SECRET_DIGITS, '0');
	string playAgain;
	do
	{
		for( size_t i = 0; i < SECRET_DIGITS; ++i )
		{
			secretNumber[i] = rand() % 2 == 1 ? '1' : '0';
		}
		
		int correctDigits;
		do
		{
			string guess;
			cout << "Enter your guess : ";
			cin >> guess;
			correctDigits = 0;
			for( size_t i = 0; i < SECRET_DIGITS; ++i )
			{
				if( guess[i] == secretNumber[i] )
				{
					++correctDigits;
				}
			}
			if( correctDigits == SECRET_DIGITS )
			{
				cout << "You guessed the number" << endl;
				break;
			}
			else
			{
				cout << "Incorrect.  You did get " << correctDigits << " digits correct." << endl;
			}
		} while(true);
		
		cout << "Play again y/n : ";
		cin >> playAgain;
	} while( playAgain != "n" );
			
	return 0;
}