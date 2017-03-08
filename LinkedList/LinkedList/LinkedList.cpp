#include "LinkedList.h"

void main() {
	DLink_List* dList = new DLink_List();
	dList->Link_Front(new Node());
	//dList -> Link_End(new Node());
	delete dList;
	dList = nullptr;
	system("pause");
}

// _________________________________________

// Constructor:
DLink_List::DLink_List(void)
{
	_headPtr = nullptr;
	_endPtr = nullptr;
	cout << "DLink_List Default Constructor." << endl;
}

// Destructor:
DLink_List::~DLink_List(void)
{
	delete _headPtr;
	_headPtr = _endPtr = nullptr;
	cout << "DLink_List Destructor." << endl;
}

// Link Front:
void DLink_List::Link_Front(Node* newNode)
{
	if (_headPtr == nullptr && _endPtr == nullptr)
	{
		_headPtr = newNode;
		_endPtr = newNode;
	}
}

// Link End:
void DLink_List::Link_End(Node* newNode)
{
	if (_headPtr == nullptr && _endPtr == nullptr)
	{
		_headPtr = newNode;
		_endPtr = newNode;
	}
}

// _________________________________________

// Constructor:
Node::Node(int nCount)
{
	_frontNode = nullptr;
	_rearNode == nullptr;
	_nodeNumber = nCount;
	cout << "Node Default Constructor." << endl;
}

// Destructor:
Node::~Node()
{
	delete _frontNode;
	_frontNode = _rearNode = nullptr;
	cout << "Node Destructor." << endl;
}

// LinkFront:
void Node::LinkFront(Node* newNode)
{
	if (_headPtr == nullptr && _endPtr == nullptr)
	{
		_headPtr = newNode;
		_endPtr = newNode;
	}
	else
	{
		newNode->LinkFront(_headPtr);
		_headPtr->LinkRear(newNode);
		_headPtr = newNode;
	}
}

// LinkRear:
void Node::LinkRear(Node *)
{
}