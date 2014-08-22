// Word Jumble
// Player must guess a jumbled word

#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(0)));

	//possible words to jumble

	const int NUM_WORDS = 5;
	const string WORDS[NUM_WORDS] =
	{
		"wall",
		"glasses",
		"labored",
		"persistent",
		"jumble"
	};
	const string HINTS[NUM_WORDS] =
	{
		"Sides of a room",
		"these help you see:",
		"difficult",
		"over and over",
		"all mixed up"
	};

	//random index number
	int choice = (rand() % NUM_WORDS);

	//word player must guess
	string secretWord = WORDS[choice];

	string jumbled = secretWord;
	size_t length = jumbled.size();
	for( size_t i = 0; i < length; ++i )
	{
		//swap letter at index i with letter at random index 
		size_t randomIndex = (rand() % length); //rand num, 0 thru length - 1
		char temp = jumbled[i];
		jumbled[i] = jumbled[randomIndex];
		jumbled[randomIndex] = temp;
	}

	cout << "\t\t\tWelcome to Word Jumble!" << endl << endl;
	cout << "Unscramble the letters to make a word." << endl;
	cout << "Enter 'quit' to quit the game." << endl << endl;
	cout << "The jumble is: " << jumbled;

	//guess loop
	string guess;
	do
	{
		cout << endl << endl << endl << "Your guess: ";
		cin >> guess;
		if( guess == "hint" )
		{
			cout << endl << HINTS[choice] << endl;
		}
		else if( (guess != secretWord) && (guess != "quit") )
		{
			cout << "Sorry, that's not it";
		}
	} while( (guess != secretWord) && (guess != "quit") );

	//do loop can end without correct guess, so check guess
	if( guess == secretWord )
	{
		cout << endl << "That's it! You guessed it!" << endl;
	}
	cout << endl << "Thanks for playing." << endl;

	return 0;
}