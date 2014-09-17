#pragma once
#include<string>

using namespace std;

class Node
{

	friend class Tree;

public:
	Node( const string& question, Node* pYes, Node* pNo );
	~Node();
	bool IsFinalQuestion() const;
private:
	string m_Question;
	Node* m_pYes;
	Node* m_pNo;
};

