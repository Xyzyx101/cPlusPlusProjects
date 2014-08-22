// Word Jumble
// Player must guess a jumbled word

#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

string randomWord(); // returns a random word
string mixUp(const string& aWord); // returns a jumbled word
void welcomePlayer(const string& aJumble);
void play(const string& aWord);

int main()
{
	srand(static_cast<unsigned int>(time(0)));
		
	string secretWord = randomWord();
	string jumbled = mixUp(secretWord);
	welcomePlayer(jumbled);
	play(secretWord);
		
	return 0;
}

void play(const string& aWord)
{
	//guess loop
	string guess;
	do
	{
		cout << endl << endl << endl << "Your guess: ";
		cin >> guess;
		if( (guess != aWord) && (guess != "quit") )
		{
			cout << "Sorry, that's not it";
		}
	} while( (guess != aWord) && (guess != "quit") );

	//do loop can end without correct guess, so check guess
	if( guess == aWord )
	{
		cout << endl << "That's it! You guessed it!" << endl;
	}
	cout << endl << "Thanks for playing." << endl;
}

string randomWord()
{
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

	//random index number
	int choice = (rand() % NUM_WORDS);

	//word player must guess
	return WORDS[choice];
}

string mixUp(const string& aWord)
{
	string jumbled = aWord;
	size_t length = jumbled.size();
	for( size_t i = 0; i < length; ++i )
	{
		//swap letter at index i with letter at random index 
		size_t randomIndex = (rand() % length); //rand num, 0 thru length - 1
		char temp = jumbled[i];
		jumbled[i] = jumbled[randomIndex];
		jumbled[randomIndex] = temp;
	}
	return jumbled;
}

void welcomePlayer(const string& aWord)
{
	cout << "\t\t\tWelcome to Word Jumble!" << endl << endl;
	cout << "Unscramble the letters to make a word." << endl;
	cout << "Enter 'quit' to quit the game." << endl << endl;
	cout << "The jumble is: " << aWord;
}