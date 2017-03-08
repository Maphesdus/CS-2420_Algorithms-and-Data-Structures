//Disclaimer:
// I Edison have not used any code other than my own(or that in the textbook) for this project.
// I also have not used any function or data - structure from the Standard - Template Library.
// I also have not shared my code with any student in this class
// I understand that any violation of this disclaimer will result in a 0 for the project.

//Node.h File
//Purpose: Header for Node Class

//CS 2420
//Instructor: Todd Peterson
//Class: CS 2420
//Section: 001
//Name: Edison Gray Earnest
//Project: AVL Tree Project
//Date: 3/25/2016

#pragma once
class Node
{
public:
	//Default Contstructor
	//Purpose: To initialize node
	//Parameters:none
	//Returns:none
	Node();

	//Decontstructor
	//Purpose: To initialize delete node -> as of this point, this function is not used. Nodes are deleted by avl tree
	//Parameters:none
	//Returns:none
	~Node();

	//Parameterized Contstructor
	//Purpose: To initialize node and set d to nodes first value
	//Parameters:int d - the data value that is set to data
	//Returns:none
	Node(int d);

	//Update()
	//Purpose: combines UpdateHeight and UpdateBalance by taking root from AVL tree, and performing both at the same time. This is done to make it easier to use both function
	//Parameters:none
	//Returns:none
	void Update();

	//UpdateHeight()
	//Purpose: Updates the height of the nodes, starting at the current value
	//Parameters:current - the node that is passed in. This program usually only passes in the root, but can pass in other nodes. 
	//Returns:int - the value that is going to be updated at each node as it recursively calls itself. if it starts at root, then the height is the total heights of the tree
	int UpdateHeight(Node* current);

	//UpdateBalance()
	//Purpose: Is called after UpdateHeight. Once height is established, then we can that to calculate any balances that need to be made
	//Parameters:current - the node in scope - this program usually only passes the root.
	//Returns:none
	void UpdateBalance(Node* current);

	//max()
	//Purpose: Function compares the left and right int values, and returns the value that is the highest. This is useful for knowing the height
	//Parameters:int left - the height of the left tree & int right - the height of the right tree
	//Returns: int - the max balance from both nodes
	int max(int left, int right);

	//Data members are not private because they need to be accessible from my function.
	int data;
	int bal;

	Node* left;
	Node* right;

private:

};

