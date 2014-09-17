#pragma once
#include<string>

using namespace std;

class Node;

class Tree
{
public:
	Tree();
	~Tree();
	void Reset();
	void Delete( Node* pNode );
	bool DisplayCurrentQuestion();
	void NextQuestion( char answer );
	void AddPerson();
	char AskYesNo( const string& question = "" );
	void DisplayQuestions();
	void DisplayQuestions( const Node * const pNode ) const;
	static const char YES = 'y';
	static const char NO = 'n';
private:
	Node* m_pRoot;
	Node* m_pCurrent;
	Node* m_pCurrentParent;
};

