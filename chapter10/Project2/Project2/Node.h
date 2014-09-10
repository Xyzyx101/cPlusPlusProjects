#pragma once

#include<string>

using namespace std;

class Node
{

	friend class List;

public:
	Node(const string& data);
	~Node();

private:
	string m_Data;
	Node* m_pNext;
};

