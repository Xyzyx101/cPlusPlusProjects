#include "Node.h"

Node::Node() :
m_Question(""),
m_pYes(nullptr),
m_pNo(nullptr)
{
}

Node::Node( const string& question, Node* pYes, Node* pNo ) :
m_Question( question ),
m_pYes( pYes ),
m_pNo( pNo )
{
}

Node::~Node()
{
}

bool Node::IsFinalQuestion() const
{
	return (m_pYes == nullptr && m_pNo == nullptr);
}