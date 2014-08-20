#include<iostream>
using namespace std;

int main()
{
	const int BONUS_CIVILIAN_SAVED = 100;
	const int BONUS_ALIEN_DESTROYED = 50;

	int civiliansSaved = 0;
	int aliensDestroyed = 0;
	cout << "Enter the number of civilians saved: ";
	cin >> civiliansSaved;
	cout << "Enter the number of aliens destroyed: ";
	cin >> aliensDestroyed;
	int pointsEarned =
		civiliansSaved * BONUS_CIVILIAN_SAVED +
		aliensDestroyed * BONUS_ALIEN_DESTROYED;
	cout << "Total points earned: " << pointsEarned << endl;
	return 0;
}