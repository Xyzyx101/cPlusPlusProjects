#pragma once
#include<string>

using namespace std;

class Node;

class Tree
{
public:
	Tree();
	~Tree();
	void Init();
	void Reset();
	void Delete( Node* pNode );
	bool DisplayCurrentQuestion();
	void NextQuestion( char answer );
	void AddPerson();
	char AskYesNo( const string& question = "" );
	void SaveTree() const;
	
	static const char YES = 'y';
	static const char NO = 'n';
	
private:
	void SaveTreeNode( const Node * const pNode, ostream& fOut ) const;
	void CreateDefaultTree();
	void LoadTree(Node*& pNode, istream& fIn);
	static const char NULL_NODE = '#';
	Node* m_pRoot;
	Node* m_pCurrent;
	Node* m_pCurrentParent;
};

