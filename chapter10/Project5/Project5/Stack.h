#pragma once

#include "Node.h"
#include <vector>

class Stack
{
public:
	Stack();
	~Stack();
	Stack& operator=(const Stack& other);
	bool IsEmpty();
	void Display() const;
	int Count() const;
	int Top() const;
	void Push( int data );
	void Pop();
	void Clear();
private:
	static const int ERROR = -1;
	Node* m_pHead;
};

