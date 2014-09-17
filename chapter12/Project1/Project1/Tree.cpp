#include "Tree.h"

#include<iostream>
#include<string>
#include"Node.h"

using namespace std;

Tree::Tree()
{
	Node* pNodeGandi = new Node( "Are you thinking of Gandhi?", NULL, NULL );
	Node* pNodeSanta = new Node( "Are you thinking of Santa Claus?", NULL, NULL );
	Node* pNodeQuestion = new Node( "Is/was the person real?", pNodeGandi, pNodeSanta );
	m_pRoot = pNodeQuestion;
	m_pCurrent = m_pRoot;
	m_pCurrentParent = NULL;
}


Tree::~Tree()
{
	Delete( m_pRoot );
}

void Tree::Reset()
{
	m_pCurrent = m_pRoot;
	m_pCurrentParent = nullptr;
}

void Tree::Delete( Node* pNode )
{
	{
		if( pNode != nullptr )
		{
			Delete( pNode->m_pYes );
			Delete( pNode->m_pNo );
			delete pNode;
			pNode = nullptr;
		}
	}
}

bool Tree::DisplayCurrentQuestion()
{
	if( m_pCurrent == nullptr )
	{
		return false;
	}
	cout << m_pCurrent->m_Question;
	return (!m_pCurrent->IsFinalQuestion());
}

void Tree::NextQuestion( char answer )
{
	if( m_pCurrent == nullptr )
	{
		return;
	}

	if( m_pCurrent->IsFinalQuestion() )
	{
		return;
	}

	m_pCurrentParent = m_pCurrent;
	if( answer == YES )
	{
		m_pCurrent = m_pCurrent->m_pYes;
	}
	else
	{
		m_pCurrent = m_pCurrent->m_pNo;
	}
}

void Tree::AddPerson()
{
	cout << "Who are you thinking of?: ";
	string name;
	cin.ignore();
	getline( cin, name );

	cout << "What question would distinguish these two people?:" << endl;
	string question;
	getline( cin, question );

	Node* pNodePerson = new Node( "Are you thinking of " + name + "?", nullptr, nullptr );
	Node* pNodeQuestion = new Node( question, nullptr, nullptr );

	char answer = AskYesNo( "What would the answer be for " + name + "?" );

	if( answer == YES )
	{
		pNodeQuestion->m_pYes = pNodePerson;
		pNodeQuestion->m_pNo = m_pCurrent;
	}
	else
	{
		pNodeQuestion->m_pYes = m_pCurrent;
		pNodeQuestion->m_pNo = pNodePerson;
	}

	//insert new question into tree
	if( m_pCurrentParent->m_pYes == m_pCurrent )
	{
		m_pCurrentParent->m_pYes = pNodeQuestion;
	}
	else
	{
		m_pCurrentParent->m_pNo = pNodeQuestion;
	}
}

char Tree::AskYesNo( const string& question )
{
	char response;
	do
	{
		cout << question;
		cout << " (" << YES << "/" << NO << "): ";
		cin >> response;
	} while( response != YES && response != NO );
	return response;
}

void Tree::DisplayQuestions()
{
	DisplayQuestions( m_pRoot );
}

void Tree::DisplayQuestions(const Node * const pNode) const
{
	if( pNode == nullptr )
	{
		return;
	}
	cout << pNode->m_Question << endl;
	if( pNode->m_pYes != nullptr )
	{
		DisplayQuestions( pNode->m_pYes );
	}
	if( pNode->m_pNo != nullptr )
	{
		DisplayQuestions( pNode->m_pNo );
	}
}