#include<string>

using namespace std;

int main()
{
	string myString = "dfgdfghdf";
	string* myPointer = &myString;
	string** myOtherPointer = &myPointer;
	int size = (*myOtherPointer)->size();
}