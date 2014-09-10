#include "Node.h"
#include<iostream>

using namespace std;

Node::Node( const int& data, Node* nextNode) :
	m_Data(data),
	m_pNext(nextNode)
{
}

Node::~Node()
{}
