#include "Stack.h"
#include "Node.h"
#include<iostream>

Stack::Stack() :
m_pHead(NULL)
{
}


Stack::~Stack()
{
	Clear();
}

Stack& Stack::operator=(const Stack& other)
{
	if( this == &other )
	{
		return *this;
	}
	this->Clear();
	
	Stack tempStack;
	Node* pOtherNode = other.m_pHead;
	while( pOtherNode != NULL )
	{
		tempStack.Push( pOtherNode->m_Data );
		pOtherNode = pOtherNode->m_pNext;
	}
	Node* pTempNode = tempStack.m_pHead;
	while( pTempNode != NULL )
	{
		this->Push( pTempNode->m_Data );
		pTempNode = pTempNode->m_pNext;
	}
	return *this;
}

bool Stack::IsEmpty()
{
	if( m_pHead == NULL){
		return false;
	}
	return true;
}

void Stack::Display() const
{
	if( m_pHead == NULL )
	{
		cout << "<Empty>" << endl;
	}
	Node* pNode = m_pHead;
	while( pNode != NULL )
	{
		cout << pNode->m_Data << endl;
		pNode = pNode->m_pNext;
	}
}

int Stack::Count() const
{
	int count = 0;
	Node* pNode = m_pHead;
	while( pNode != NULL )
	{
		count += 1;
		pNode = pNode->m_pNext;
	}
	return count;
}

int Stack::Top() const
{
	if( m_pHead == NULL )
	{
		return Stack::ERROR;
	}
	return m_pHead->m_Data;
}

void Stack::Push( int data )
{
	Node* pNode = new Node( data, m_pHead );
	m_pHead = pNode;
}

void Stack::Pop()
{
	if( m_pHead == NULL )
	{
		cout << "Error: Cannot Pop an empty stack";
		return;
	}
	Node* oldHead = m_pHead;
	m_pHead = oldHead->m_pNext;
	delete oldHead;
}

void Stack::Clear()
{
	Node* pNode = m_pHead;
	while( pNode != NULL )
	{
		Pop();
		pNode = m_pHead;
	}
}
