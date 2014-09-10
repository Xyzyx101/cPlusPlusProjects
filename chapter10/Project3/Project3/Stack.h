#pragma once

#include "Node.h"

class Stack
{
public:
	Stack();
	~Stack();
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

