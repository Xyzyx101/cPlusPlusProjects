#include<iostream>
using namespace std;

int main() {
	int players;
	cout << "There are 52 cards to be divided equally." << endl;
	cout << "How many players : ";
	cin >> players;
	int extraCards = 52 % players;
	int cardsPerPlayer = (52 - extraCards) / players;
	cout << "There are " << cardsPerPlayer << " cards for each player and " << extraCards << " left over" << endl;
	return 0;
}