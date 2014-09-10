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
		cout << "<Empty>";
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
}

int Stack::Top() const
{
	return m_pHead->m_Data;
}

void Stack::Push( int data )
{
	Node* pNode = new Node( data, m_pHead );
	m_pHead = pNode;
}

void Stack::Pop()
{
	Node* oldHead = m_pHead;
	m_pHead = oldHead->m_pNext;
	delete oldHead;
}


void Pop( );
void Clear( );