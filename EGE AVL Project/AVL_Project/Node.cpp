//Disclaimer:
// I Edison have not used any code other than my own(or that in the textbook) for this project.
// I also have not used any function or data - structure from the Standard - Template Library.
// I also have not shared my code with any student in this class
// I understand that any violation of this disclaimer will result in a 0 for the project.

//Node.cpp File
//Purpose: implementation for Node Class

//CS 2420
//Instructor: Todd Peterson
//Class: CS 2420
//Section: 001
//Name: Edison Gray Earnest
//Project: AVL Tree Project
//Date: 3/25/2016

#include "Node.h"


//default constructor
Node::Node()
{
	//set data and balance to 0
	data = 0;
	bal = 0;
	//set right and left to nullptr
	right = nullptr;
	left = nullptr;
}

//parameterized constructor - initializes variables and sets data to passed in value
Node::Node(int d)
{
	data = d;
	bal = 0;

	right = nullptr;
	left = nullptr;
}

//Is being used as a shortcut to update height and balance of the avl tree
void Node::Update()
{
	int temp = UpdateHeight(this);
	UpdateBalance(this);
}

//updates the height of each node, which is stored in balance. Height represents the node height from the leafs
int Node::UpdateHeight(Node* current)
{
	if (current == nullptr)
		return 0;
	current->bal = 1 + max(UpdateHeight(current->left), UpdateHeight(current->right));
	return current->bal;
}

//updates the balance, which is read from bal and then stored back into bal. Balance represents the left vs right node differences.
void Node::UpdateBalance(Node* current)
{
	//temp left and right values
	int templeft;
	int tempright;

	//if left is nullptr, then set it to 0
	if (current->left == nullptr)
		templeft = 0;
	//else, get the left balance
	else
		templeft = current->left->bal;

	//if right is nullptr, then set it to 0
	if (current->right == nullptr)
		tempright = 0;
	//else, get the right balance
	else
		tempright = current->right->bal;

	//current balance is the difference between those 2 balances
	current->bal = templeft - tempright;

	//in order for this function to work, this starts at the root and works itself to the most left, then the most right.

	if (current->left != nullptr)
		UpdateBalance(current->left);
	if (current->right != nullptr)
		UpdateBalance(current->right);
}

//compares the left and right, and returns the highest of the two
int Node::max(int left, int right)
{
	if (left >= right)
		return left;
	else
		return right;
}

//deconstructor not used
Node::~Node()
{
}
