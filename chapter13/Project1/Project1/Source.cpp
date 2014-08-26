// Word Jumble
// Player must guess a jumbled word

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<string> words;
	//possible words to jumble
	words.push_back("wall");
	words.push_back("glasses");
	words.push_back("labored");
	words.push_back("persistent");
	words.push_back("jumble");
		
	std::random_shuffle(words.begin(), words.end());

	//word player must guess
	string secretWord = words[0];

	string jumbled = secretWord;
	std::random_shuffle(jumbled.begin(), jumbled.end());
	
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
		if( (guess != secretWord) && (guess != "quit") )
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