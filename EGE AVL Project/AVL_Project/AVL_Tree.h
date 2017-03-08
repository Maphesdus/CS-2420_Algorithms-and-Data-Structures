//Disclaimer:
// I Edison have not used any code other than my own(or that in the textbook) for this project.
// I also have not used any function or data - structure from the Standard - Template Library.
// I also have not shared my code with any student in this class
// I understand that any violation of this disclaimer will result in a 0 for the project.

//AVL_Tree.h File
//Purpose: Header File for the AVL Tree Class

//CS 2420
//Instructor: Todd Peterson
//Class: CS 2420
//Section: 001
//Name: Edison Gray Earnest
//Project: AVL Tree Project
//Date: 3/25/2016


#include "Node.h";
#include <iostream>
#pragma once


//Declar Constants - these are used to give reference as to how many children a node has
const int NO_CHILD = 0;
const int LEFT_ONLY = 1;
const int RIGHT_ONLY = 2;
const int LEFT_AND_RIGHT = 3;

const int TWO = 2;

//Constant is used for spacing purposes.
const int FOUR = 4;

class AVL_Tree
{
public:
	//Default Contstructor
	//Purpose: To initialize program
	//Parameters:none
	//Returns:none
	AVL_Tree();

	//DeConstructor
	//Purpose:to set in motion the delete helper function, which deletes all the remaining nodes from the heap
	//Parameters:none
	//Returns:none
	~AVL_Tree();

	//DeleteHelper Function
	//Purpose:Deletes in order of Left, Right, Root. This function recursively calls itself to delete all remaining nodes on Tree
	//Parameters: root - new root that may have children
	//Returns:none
	void DeleteHelper(Node* root);

	//Size Function
	//Purpose:Calls Size helper Function to recursively go through nodes to count the size
	//Parameters:none
	//Returns:int - size that is calculated in the helper function
	int Size();

	//Size Helper Function
	//Purpose:Helper function that counts itself as it travels through each node's left and right 
	//Parameters:root - the current node that may have children & s - the current counted size of the function
	//Returns:int - size that is calculated through recursion
	int SizeHelper(Node* root, int s);

	//Print Function
	//Purpose:Print calls helper function that individual goes through the depth on the nodes, and indents & lables applicable nodes "empty" or "leaf" as printing occurs
	//Parameters:none
	//Returns:none
	void Print();

	//PrintHelper Function
	//Purpose:recursively calls itself, cout's the data at that specific node, indents and labels "empty" or "leaf" as printing occurs
	//Parameters:node_ptr - pointer for current node & depth - the current depth of the node which indents the node at the correct porportion
	//Returns:none
	void PrintHelper(Node* node_ptr, int depth);

	//Insert Function
	//Purpose:This function calls a helper function if there is already a Binary Tree created, which places the value d in a strategic place on the binary tree
	//Parameters:int d - the value being added on the Binary Tree
	//Returns: none
	void Insert(int d);

	//InsertHelper Function
	//Purpose:This function recursively sorts through the Binary tree for a spot to place the value d that is passed in
	//Parameters:root - the temporary node that is being looked at currently & d = the value that is being looked for
	//Returns:none
	void InsertHelper(Node* & current, int d);


	//RotateLeftLeft() Function
	//Purpose: rotates specifically if a left left is needed
	//Parameters: Node current - current node that is going to be reconnected somewhere else
	//Returns:temp node - the node that is replacing currents spot
	Node* RotateLeftLeft(Node*& current);

	//RotateRightRight() Function
	//Purpose: rotates specifically if a right right is needed
	//Parameters: Node current - current node that is going to be reconnected somewhere else
	//Returns:temp node - the node that is replacing currents spot
	Node* RotateRightRight(Node*& current);

	//RotateLeftRight() Function
	//Purpose: rotates specifically if a left right is needed
	//Parameters: Node current - current node that is going to be reconnected somewhere else
	//Returns:temp node - the node that is replacing currents spot
	Node* RotateLeftRight(Node*& current);

	//RotateRightLeft() Function
	//Purpose: rotates specifically if a right left is needed
	//Parameters: Node current - current node that is going to be reconnected somewhere else
	//Returns:temp node - the node that is replacing currents spot
	Node* RotateRightLeft(Node*& current);

	//Rebalance() Function
	//Purpose: Function decides if it needs to have the tree balanced. If it does, then the program will balance the tree and update the node balances afterwards
	//Parameters: None
	//Returns:void
	void Rebalance();

	//HelpRebalance() Function
	//Purpose: Helper Function that finds the specific node, and decides what to do with that node in terms of balancing
	//Parameters: Node* current - the current node that recusion is calling & Node* previous - the previous node
	//Returns:void
	void HelpRebalance(Node* & current, Node* previous);

	//BalanceBool() Function
	//Purpose: Returns a true/falses if the tree needs to be balanced or not
	//Parameters: Node* current - the current node that recusion is calling
	//Returns:bool - true if tree needs rebalancing, false if it doesn't
	bool BalanceBool(Node* current);

	//Erase Function
	//Purpose: Erase calls Erase Helper, which determines whether or not the value "d" is on this Binary Tree
	//Parameters: int d - the value that the program is looking to remove from the the Binary Tree
	//Returns:bool - return true if data was found, or false if data isn't on Binary Tree (or if it hasn't been made)
	void Erase(int d);

	//EraseHelper Fuction
	//Purpose: Helper Function recursively searches through Binary Tree for possible spots for value D. If value is not found, then Function does not make any changes. If value is found, then EraseCurrent is called to erase current Node
	//Parameters: current_root - current node during search & int d - data that program is searching for & previous - node that points to previous node
	//Returns:bool - will return true if the data was found, letting the user know that the data will be deleted or wasn't found
	bool EraseHelper(Node* current_root, int d, Node* previous);

	//Erase Current
	//Purpose:This function is called when there is a value that needs to be erased from the Binary Tree. Function determines how to delete node given the amount and placement of the children of that node if any.
	//Parameters:current_node - node that is going to be deleted & previous - node that the the current node connects from (unless nullptr which means that the root is to be deleted)
	//Returns: none
	void EraseCurrent(Node* current_node, Node* previous);

	//ChildrenCalc Function (is basically an isleaf() function in a probably a less efficient way)
	//Purpose:returns a value 0-4 which determines how many and where the children nodes are connected to on this current node. 0 = no children, 1 = single left, 2 = single right, 3 = both left and right has children
	//Parameters:root - the current node that may have children
	//Returns:int - a value that is between 0-3 that determines the identity and locatino of the children nodes in relation to this node
	int ChildrenCalc(Node* root);

	//InOrder Function
	//Purpose: Initial Function that displays the raw data in the Binary in InOrder Form
	//Parameters:none
	//Returns:none
	void InOrder();

	//InOrderHelper Function
	//Purpose:InOrder Helper Function is programed to display node data in a InOrder sequence
	//Parameters:root - the current node that is being looked at
	//Returns:none
	void InOrderHelper(Node* current);

private:
	Node* root;
	int height;
};

