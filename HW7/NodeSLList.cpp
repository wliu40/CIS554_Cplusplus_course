////////////////////////////////////////////////////////////////////////////////////////
// NodeSLList.cpp
// -----------------------------------------------------------------------------------
// Course: CIS554
// HomeWork 7
// Author: Wei Liu
// Date: 4/15/2015
// -----------------------------------------------------------------------------------
// Class NodeSLList Implementation
//
// Description - This file implements a singly linked list.
////////////////////////////////////////////////////////////////////////////////////////

#include "NodeSLList.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


///////////////////////////////////////////////////////////////////////
// default constructor
///////////////////////////////////////////////////////////////////////
NodeSLList::NodeSLList()
{
	head = tail = 0;
}

///////////////////////////////////////////////////////////////////////
// copy constructor
///////////////////////////////////////////////////////////////////////
NodeSLList::NodeSLList(const NodeSLList & list)
{
	if (list.IsEmpty())
	{
		head = tail = nullptr;
	}
	else
	{
		head = new IntNode;
		head->data = list.head->data;
		head->next = list.head->next;
		tail = head;

		IntNode *tmp = list.head->next;
		while (tmp)
		{
			IntNode *newNode = new IntNode;
			newNode->data = tmp->data;
			newNode->next = tmp->next;
			tail->next = newNode;
			tail = tail->next;
			tmp = tmp->next;
		}
	}
}

///////////////////////////////////////////////////////////////////////
// destructor
///////////////////////////////////////////////////////////////////////
NodeSLList::~NodeSLList()
{
	// call destroyList() to remove all nodes
	// and reset linked list
	DestroyList();
}

///////////////////////////////////////////////////////////////////////
// IsEmpty
///////////////////////////////////////////////////////////////////////
bool NodeSLList::IsEmpty() const
{
	// if head is NULL, then the list is empty, and we will return true
	// otherwise, we will return false
	return (head == 0);
}

///////////////////////////////////////////////////////////////////////
// GetSize
///////////////////////////////////////////////////////////////////////
int NodeSLList::GetSize() const
{
	// check to see if the list is empty. if 
	// so, just return 0
	if (IsEmpty()) return 0;

	int size = 1;
	IntNode *p = head;
	// compute the number of nodes and return
	while (p != tail)
	{
		// until we reach the tail, keep counting
		size++;
		p = p->next;
	}
	return size;
}

///////////////////////////////////////////////////////////////////////
// AddToHead
///////////////////////////////////////////////////////////////////////
void NodeSLList::AddToHead(const IntNode & node)
{
	// create a new node, and make it the head. the 
	// previous head will become head->next
	IntNode * next = head;
	head = new IntNode;
	head->next = next;
	head->data = node.data;

	// if this is the first node, make the tail the 
	// same as the head
	if (tail == 0)
		tail = head;
}

///////////////////////////////////////////////////////////////////////
// DeleteFromHead
///////////////////////////////////////////////////////////////////////
IntNode NodeSLList::DeleteFromHead()
{
	IntNode temp;
	temp.data = 0;
	temp.next = NULL;
	if (IsEmpty())
	{
		cout << "*****ERROR: Can't delete from head. List is Empty" << endl;
		return temp;
	}

	// get current value of node we are about to delete, 
	// so we can return it.
	temp.data = head->data;

	IntNode *tmp = head;

	// if there is only one node, set the head and pointer tails
	// to NULL (0)
	if (head == tail)
		head = tail = 0;

	// otherwise, move the head pointer to the next node 
	// in the list
	else
		head = head->next;

	// delete head node
	delete tmp;

	// return value of node that was deleted
	return temp;
}

///////////////////////////////////////////////////////////////////////
// AddToTail
///////////////////////////////////////////////////////////////////////
void NodeSLList::AddToTail(const IntNode & node)
{
	if (IsEmpty())
	{
		head = new IntNode;
		head->data = node.data;
		head->next = nullptr;
		tail = head;
	}
	else
	{

		IntNode *tmp = new IntNode;
		tmp->data = node.data;
		tmp->next = nullptr;
		//tail->next->data = node.data;
		tail->next = tmp;
		tail = tail->next;
		////IntNode *tmp = new IntNode;
		////tail->next = tmp;
		////tail->next->data = node.data;
		////tail->next->next = nullptr;
		////tail = tail->next;
	}
}

///////////////////////////////////////////////////////////////////////
// DeleteFromTail
///////////////////////////////////////////////////////////////////////
IntNode NodeSLList::DeleteFromTail()
{
	IntNode nodeData;

	// get the current data at the tail
	nodeData.data = tail->data;


	// if there is only one node, delete the only node, and set the 
	// head and tail pointers to NULL (0) 
	if (head == tail)
	{
		delete head;
		head = tail = 0;
	}

	// otherwise, traverse to the tail node and delete it
	else
	{
		IntNode * temp;
		// traverse to tail pointer
		for (temp = head; temp->next != tail; temp = temp->next);
		delete tail;
		tail = temp;
		tail->next = 0;
	}

	return nodeData;
}


///////////////////////////////////////////////////////////////////////
// DeleteNode
///////////////////////////////////////////////////////////////////////
IntNode NodeSLList::DeleteNode(int nodeNum)
{
	if (nodeNum <= 0) nodeNum = 1;
	IntNode *prev = head, *temp = head;
	IntNode current;

	// traverse to the node
	for (int loop = 1; loop < nodeNum; loop++)
	{
		prev = temp, temp = temp->next;
		// check for case where nodeNum is > the number of 
		// nodes in the list. if we reach the tail before
		// we traverse to the node, delete the tail 
		if (temp == tail)
			return DeleteFromTail();
	}

	// if deleting the head just call 
	// the appropriate member function 
	// and don't repeat that logic here
	if (temp == head) return DeleteFromHead();

	// otherwise, delete the node we traversed to
	prev->next = temp->next;
	current.data = temp->data;

	delete temp;

	return current;
}

///////////////////////////////////////////////////////////////////////
// InsertNode
///////////////////////////////////////////////////////////////////////
void NodeSLList::InsertNode(int nodeNum, const IntNode &node)
{
	if (nodeNum <= 0)
		AddToHead(node);
	else if (nodeNum >= GetSize())
		AddToTail(node);
	else
	{
		IntNode *newNode = new IntNode;
		newNode->data = node.data;
		newNode->next = nullptr;
		IntNode *tmp = head;
		for (int i = 0; i < nodeNum - 1; i++)
		{
			tmp = tmp->next;
		}
		newNode->next = tmp->next;
		tmp->next = newNode;		
	}	

}


///////////////////////////////////////////////////////////////////////
// UpdateNode
///////////////////////////////////////////////////////////////////////
void NodeSLList::UpdateNode(int nodeNum, const IntNode &node)
{
	IntNode *tmp = head;

	// traverse to the node, or to the last node, whichever comes
	// first. if the last node is reached, then that is the node
	// that is updated
	for (int i = 1; i< nodeNum && tmp != tail; i++)
		tmp = tmp->next;

	tmp->data = node.data;
}

///////////////////////////////////////////////////////////////////////
// SortList
///////////////////////////////////////////////////////////////////////
void NodeSLList::SortList(unsigned int order)
{
	vector<IntNode> vec;
	IntNode *tmp = head;
	while (tmp != tail)
	{
		vec.push_back(*tmp);
		tmp = tmp->next;
	}		
	vec.push_back(*tmp);
	sort(vec.begin(), vec.end(), cmp);
	NodeSLList *tmpList = new NodeSLList;
	if (order == 1)
	{
		for (size_t i = 0; i < vec.size(); i++)
			tmpList->AddToTail(vec[i]);
	}
	if (order == 2)
	{
		for (size_t i = 0; i < vec.size(); i++)
			tmpList->AddToHead(vec[i]);
	}
	DestroyList();
	*this = *tmpList;
}
// construct a compare function for vector sorting
bool cmp(const IntNode &x, const IntNode &y)
{
	return x.data < y.data;
}

///////////////////////////////////////////////////////////////////////
// DestroyList
///////////////////////////////////////////////////////////////////////
void NodeSLList::DestroyList()
{
	// while the list is NOT empy
	// keep removing the head node and make
	// the next node the head node
	for (IntNode *p; !IsEmpty();)
	{
		p = head->next;
		delete head;
		head = p;
	}
	head = tail = 0;
	//cout << "the list was destroyed!" << endl;
}

///////////////////////////////////////////////////////////////////////
// PrintList
///////////////////////////////////////////////////////////////////////
void NodeSLList::PrintList() const
{
	if (!head)
		cout << "" << endl;
	else
	{
		IntNode *tmp = head;
		while (tmp != tail)
		{
			cout << tmp->data << ", ";
			tmp = tmp->next;
		}
		cout << tmp->data;
	}
	cout << endl;
}

///////////////////////////////////////////////////////////////////////
// operator=
///////////////////////////////////////////////////////////////////////
const NodeSLList & NodeSLList::operator=(const NodeSLList & list)
{
	DestroyList();
	if (list.IsEmpty())
	{
		head = tail = nullptr;
	}
	else
	{
		IntNode *tmpSource = list.head;
		while (1)
		{
			IntNode *newNode = new IntNode;
			newNode->data = tmpSource->data;
			newNode->next = tmpSource->next;
			AddToTail(*newNode);
			if (tmpSource == list.tail)
				break;
			tmpSource = tmpSource->next;
		}
	}
	return (*this);
}

///////////////////////////////////////////////////////////////////////
// operator==
///////////////////////////////////////////////////////////////////////
bool NodeSLList::operator==(const NodeSLList & list) const
{
	if ( GetSize() != list.GetSize() )
		return false;
	else
	{
		IntNode *tmp = head;
		IntNode *tmpSource = list.head;
		if (tmp->data != tmpSource->data)
			return false;
		tmp = tmp->next;
		tmpSource = tmpSource->next;
	}
	return true;
}

///////////////////////////////////////////////////////////////////////
// operator!=
///////////////////////////////////////////////////////////////////////
bool NodeSLList::operator!=(const NodeSLList & list) const
{
	return !(*(this) == list);
}

///////////////////////////////////////////////////////////////////////
// operator+
///////////////////////////////////////////////////////////////////////
NodeSLList NodeSLList::operator+(const NodeSLList & list)
{
	NodeSLList result(*this);	
	if (list.IsEmpty())
	{
		return result;
	}
	else
	{
		IntNode * tmp = list.head;
		while (true)
		{
			IntNode *newNode = new IntNode;
			newNode->data = tmp->data;
			newNode->next = tmp->next;
			result.AddToTail(*newNode);		
			if (tmp == list.tail)			
				break;
			tmp = tmp->next;
		}		
		return result;
	}

}

///////////////////////////////////////////////////////////////////////
// RetrieveNode
// 
// Description: retrieve data from a node without removing it from 
//              the list
// Input: node number (1-N; not 0-N-1)
// Output: none
// Returns: reference to node data
///////////////////////////////////////////////////////////////////////
IntNode & NodeSLList::RetrieveNode(int nodeNum) const
{
	IntNode *tmp = head;

	// traverse to the node, or to the last node, whichever comes
	// first
	for (int i = 1; i< nodeNum && tmp != tail; i++)
		tmp = tmp->next;

	return *tmp;
}
///////////////////////////////////////////////////////////////////////
// operator <<
///////////////////////////////////////////////////////////////////////
//overloading the operater <<
ostream & operator<<(ostream & output, NodeSLList & list)
{
	if (list.IsEmpty())//if the list is empty, print nothing
	{
		output << "";
		return output;
	}
	else // print the data in each Node, seperated by ', '
	{
		IntNode *tmp = list.head;
		while (tmp != list.tail)
		{
			output << tmp->data << ", ";
			tmp = tmp->next;
		}
		output << list.tail->data;
		return output;
	}
}
