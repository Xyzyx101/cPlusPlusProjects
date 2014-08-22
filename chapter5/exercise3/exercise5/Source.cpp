#include<iostream>
#include<string>

using namespace std;

int getNumberUsingDefault(const string& prompt = " :> ");

int getNumberUsingOverLoading();
int getNumberUsingOverLoading(const string& prompt);

int main()
{
	cout << endl << getNumberUsingDefault() << endl;
	cout << endl << getNumberUsingDefault("NotTheDefault:> ") << endl;
	
	cout << endl << getNumberUsingOverLoading() << endl;
	string prompt = "OverloadedPrompt:> ";
	cout << endl << getNumberUsingOverLoading(prompt) << endl;
	
	return 0;
}

int getNumberUsingDefault(const string& prompt)
{
	int number;
	cout << prompt;
	cin >> number;
	return number;
}

int getNumberUsingOverLoading()
{
	cout << endl << ":> ";
	int number;
	cin >> number;
	return number;
}

int getNumberUsingOverLoading(const string& prompt)
{
	cout << endl << prompt;
	int number;
	cin >> number;
	return number;
}