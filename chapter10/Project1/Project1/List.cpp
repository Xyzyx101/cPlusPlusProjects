#include "List.h"

#include <iostream>
#include <string>
#include "node.h"

using namespace std;

List::List() :
    m_pHead(NULL),
    m_pTail(NULL)
{}

List::~List()
{
	Clear();
}

bool List::Contains(const string& data) const
{
	bool found = false;
	Node* pNode = m_pHead;

	while( !found && pNode != NULL )
	{
		if( pNode->m_Data == data )
		{
			found = true;
		}
		pNode = pNode->m_pNext;
	}
	return found;
}

int List::Count() const
{
	Node* pNode = m_pHead;
	int total = 0;

	while( pNode != NULL )
	{
		++total;
		pNode = pNode->m_pNext;
	}
	return total;
}

void List::Display() const
{
	if( m_pHead == NULL )
	{
		cout << "<Empty>" << endl;
		return;
	}
	Node* pNode = m_pHead;
	while( pNode != NULL )
	{
		cout << pNode->m_Data << endl;
		pNode = pNode->m_pNext;
	}
}

void List::Add(const string& data)
{
	Node* pNode = new Node(data);
	if( m_pTail != NULL )
	{
		m_pTail->m_pNext = pNode;
		m_pTail = m_pTail->m_pNext;
	}
	else
	{
		m_pHead = pNode;
		m_pTail = pNode;
	}
}

bool List::Remove(const string& data)
{
	Node* pNode = m_pHead;
	Node* pPrevious = NULL;

	while( pNode != NULL && pNode->m_Data != data )
	{
		pPrevious = pNode;
		pNode = pNode->m_pNext;
	}
	if( pNode == NULL )
	{
		return false;
	}

	srggsdfgsd continue here

}