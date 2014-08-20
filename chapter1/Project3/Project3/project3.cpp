#include<iostream>

using namespace std;
int main() {
	float firstScore, secondScore, thirdScore;
	
	cout << "Enter first score: ";
	cin >> firstScore;
	
	cout << "Enter second score: ";
	cin >> secondScore;
	
	cout << "Enter third score: ";
	cin >> thirdScore;

	cout << "Average Score: " << (firstScore + secondScore + thirdScore) / 3 << endl;
	return 0;
}