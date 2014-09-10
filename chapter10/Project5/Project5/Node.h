#pragma once

#include<string>

using namespace std;

class Node
{

	friend class Stack;

public:
	Node( const int& data, Node* nextNode);
	~Node();

private:
	int m_Data;
	Node* m_pNext;
};

