#include "Tree.h"

#include<iostream>
#include<fstream>
#include<string>
#include"Node.h"

using namespace std;

Tree::Tree() :
m_pRoot(nullptr),
m_pCurrent(nullptr),
m_pCurrentParent(nullptr)
{
}

Tree::~Tree()
{
	Delete( m_pRoot );
}

void Tree::Init()
{
	ifstream fIn;
	fIn.open("tree_data.txt", ifstream::in);
	if( fIn.fail() )
	{
		cout << "Tree data not found.  Building default tree." << endl;
		CreateDefaultTree();
	}
	else
	{
		cout << "Loading tree from disk." << endl;
		LoadTree(m_pRoot, fIn);
		fIn.close();
	}
}

void Tree::LoadTree(Node*& pNode, istream& fIn)
{
	char question[256];
	fIn.getline(question, 256);
	if( question[0] == NULL_NODE )
	{
		pNode = nullptr;
	}
	else
	{
		pNode = new Node();
		pNode->m_Question = question;
		LoadTree(pNode->m_pYes, fIn);
		LoadTree(pNode->m_pNo, fIn);
	}
}

void Tree::CreateDefaultTree()
{
	Node* pNodeGandi = new Node( "Are you thinking of Gandhi?", NULL, NULL );
	Node* pNodeSanta = new Node( "Are you thinking of Santa Claus?", NULL, NULL );
	Node* pNodeQuestion = new Node( "Is/was the person real?", pNodeGandi, pNodeSanta );
	m_pRoot = pNodeQuestion;
	m_pCurrent = m_pRoot;
	m_pCurrentParent = NULL;
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

void Tree::SaveTree() const
{
	ofstream fOut;
	fOut.open("tree_data.txt", ofstream::out);
	SaveTreeNode( m_pRoot , fOut);
}

void Tree::SaveTreeNode(const Node * const pNode, ostream& fOut) const
{
	if( pNode == nullptr )
	{
		return;
	}
	
	fOut << pNode->m_Question << endl;
	
	if( pNode->m_pYes != nullptr )
	{
		SaveTreeNode( pNode->m_pYes, fOut );
	}
	else
	{
		fOut << NULL_NODE << endl;
	}
	if( pNode->m_pNo != nullptr )
	{
		SaveTreeNode( pNode->m_pNo, fOut );
	}
	else
	{
		fOut << NULL_NODE << endl;
	}
	
}