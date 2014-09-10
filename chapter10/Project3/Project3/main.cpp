#include<iostream>
#include"Stack.h"

using namespace std;

int main()
{
	Stack stack;
	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	
	stack.Display();

	stack.Pop();

	cout << "Count: " << stack.Count() << endl;
	cout << "Top: " << stack.Top() << endl;

	stack.Clear();
	stack.Display(); //should display <empty>
	cout << endl;

	stack.Pop(); //should display error
	cout << endl;

	return 0;
}