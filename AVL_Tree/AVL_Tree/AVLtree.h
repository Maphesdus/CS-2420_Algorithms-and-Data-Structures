#pragma once

/*	AVL Trees

	Implement an AVL tree class that takes an integer as a data type. Including the following functions:

		•	Constructor
		•	Insert
		•	Print (tabbed print function see pages 505-506)
		•	RotateLeft
		•	RotateRight
		•	Rebalance
		•	updateHeight

	Also include a node class appropriate with this assignment.
*/

#include <iostream>
#include <iomanip>

using namespace std;

// Node:
struct Node
{
	// Constructor:
	Node(const int& init_data = int(), Node* init_left = nullptr, Node* init_right = nullptr)
	{
		data_field = init_data;
		left_child = init_left;
		right_child = init_right;
	}

	int& data() { return data_field; }
	const int& data() const { return data_field; }
	void setData(const int& new_data) { data_field = new_data; }

	Node*& left() { return left_child; }
	const Node* left() const { return left_child; }
	void setLeft(Node* new_left) { left_child = new_left; }

	Node*& right() { return right_child; }
	const Node* right() const { return right_child; }
	void setRight(Node* new_right) { right_child = new_right; }

	bool isLeaf() const { return (left_child == nullptr) && (right_child == nullptr); }
	int max(int left, int right) { if (left >= right) return left; else return right; }

	int data_field;
	int bal;
	Node *left_child;
	Node *right_child;
};

// AVL tree:
class AVLtree
{
	public:
		AVLtree(); // Constructor
		virtual ~AVLtree(); // Destructor
		void Destruct_Helper(Node*);

		void Insert(int);
		void Insert_Helper(Node*&, int);

		void Print();
		void AVLtree::Print_Helper(Node*, int);
		int NumChildren(Node*);

		Node* RotateLeft(Node*&);		// L
		Node* RotateRight(Node*&);		// R
		Node* RotateLeftRight(Node*&);	// LR
		Node* RotateRightLeft(Node*&);	// RL

		void Rebalance();
		void Rebalance_Helper(Node*&, Node*);
		bool Is_Unbalanced(Node*);

		int UpdateHeight(Node*&);
		int UpdateBalance(Node*&);

		void LeftRotation_reference(Node*&, Node*&);
		void LeftRotation_pointer(Node**, Node*);

	private:
		Node* root;
		int height;
};