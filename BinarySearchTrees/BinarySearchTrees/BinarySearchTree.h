#pragma once
#include <iostream>
#include <iomanip> // setw
using namespace std;

/* Create a Binary Search Tree Class (don’t allow duplicates)

	Member variables
		root

	Constructor

	Destructor

	Size(): Returns the number of elements in the tree

	Print(): Do the indented print that was discussed in class
		Pre order traversal
		Print one element per line
		Indent according to the depth (See page 505)

	Erase(int item): Erase the occurrence of the item in the tree (there should be 1 or 0 occurrences).
		Resulting tree should still be a BST

	Insert(int item): Insert the item into the BST. Don’t allow duplicate numbers.

	Traversals (just print out the items, don’t worry about passing functions as parameters)
		Pre-Order
		In-Order
		Post-Order

	Create a Driver
		Create an interactive driver similar to the ones used in the sequence projects
			Feel free to start with one of those and adapt it to this.

		Test all public functions
			You can test the destructor by having the destructor call another function called destroy,
			which should erase all of the elements in the tree by adapting one of the traversals to do this. */

/// page 486 for Node implementation

class Node
{
	public:
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

	private:
		int data_field;
		Node *left_child;
		Node *right_child;
};



class BinarySearchTree
{
	public:
		BinarySearchTree();
		virtual ~BinarySearchTree();

		int Size();
		void Print();
		void Erase(int);
		void Insert(int);

		void Erase2(int);

		void PreOrderPrint();
		void InOrderPrint();
		void PostOrderPrint();

		void PreOrderPrint(Node*);
		void InOrderPrint(Node*);
		void PostOrderPrint(Node*);

		void remove(Node*&, int&);
		void remove_max(Node*, int&);
		void remove_comments(Node*, int&);

		Node*& find_greatest(Node*&);
		void display(Node*);

	private:
		Node* root;

		int Size_helper(Node*);
		void Print_helper(Node*, int);
		void Insert_helper(Node*, int);
		void Erase_helper(Node*, int);
		bool Find(Node*, int);
};

/* Documentation (10 pts)
	Student name, Section and Disclaimer				______/5
	Proper function and class headers					______/5

BST Class (45 pts)
	Appropriate private data members					______/5

	Class Functions:
		Constructor/Destructor/							______/10
		Size/Count										______/5
		Print											______/5
		Erase											______/10
		Insert											______/5
		3 Traversals									______/5

Node Class (5 points)
	Data, left and right pointers and constructor		______/5


Driver (20 pts)
	Interactive driver
		Output displayed correctly						______/10
		All functions used								______/10 */


/// page 518-536


/// page 513

/*template <class Item>
void tree_clear(Node<Item>*& root_ptr)
{
	Node<Item>* child;

	if (root_ptr == nullptr)
	{
		child = root_ptr->left();
		tree_clear(child);
		child = root_ptr->right();
		tree_clear(child);
		delete root_ptr;
		root_ptr = nullptr;
	}
}

template <class Item>
void tree_copy(const Node* root_ptr)
{
	Node<Item> *l_ptr;
	Node<Item> *r_ptr;

	if (root_ptr == nullptr)
		return nullptr;

	else
	{
		l_ptr = tree_copy(root_ptr->left());
		r_ptr = tree_copy(root_ptr->right());

		return new Node<Item>(root_ptr->getValue(), l_ptr, r_ptr);
	}
};*/





/*bool remove(Node*& root_ptr, const int& target)
{
	Node *oldroot_ptr;

	if (root_ptr == NULL) {
		return false;
	}

	if (target < root_ptr->data()) {
		return remove(root_ptr->left(), target);
	}

	if (target > root_ptr->data()) {
		return remove(root_ptr->right(), target);
	}

	if (root_ptr->left() == nullptr) {
		oldroot_ptr = root_ptr;
		root_ptr = root_ptr->right();
		delete oldroot_ptr;
		return true;
	}

	remove_max(root_ptr->left(), root_ptr->data());
	return true;
}*/



///	-------------------------------------------------------------------------------
//	Code from website (https://www.cs.colorado.edu/~main/chapter10/bag6.template):
///	-------------------------------------------------------------------------------


//	Precondition:
//		root_ptr is a root pointer of a binary search tree
//		(or may be NULL for an empty tree).

//	Postcondition:
//		If target was in the tree, then one copy of target has been removed,
//		and root_ptr now points to the root of the new (smaller) binary search tree.
//		In this case the function returns true.
//		If target was not in the tree, then the tree is unchanged
//		(and the function returns false).
/*template <class Item>
bool bst_remove(binary_tree_node<Item>*& root_ptr, const Item& target)
{
	binary_tree_node<Item> *oldroot_ptr;

	if (root_ptr == NULL)
	{   // Empty tree
		return false;
	}

	if (target < root_ptr->data())
	{   // Continue looking in the left subtree
		// Note: Any change made to root_ptr->left by this recursive
		// call will change the actual left pointer (because the return
		// value from the left() member function is a reference to the
		// actual left pointer.
		return bst_remove(root_ptr->left(), target);
	}

	if (target > root_ptr->data())
	{   // Continue looking in the right subtree
		// Note: Any change made to root_ptr->right by this recursive
		// call will change the actual right pointer (because the return
		// value from the right() member function is a reference to the
		// actual right pointer.
		return bst_remove(root_ptr->right(), target);
	}

	if (root_ptr->left() == NULL)
	{   // Target was found and there is no left subtree, so we can
		// remove this node, making the right child be the new root.
		oldroot_ptr = root_ptr;
		root_ptr = root_ptr->right();
		delete oldroot_ptr;
		return true;
	}

	// If code reaches this point, then we must remove the target from
	// the current node. We'll actually replace this target with the
	// maximum item in our left subtree.
	// Note: Any change made to root_ptr->left by bst_remove_max
	// will change the actual left pointer (because the return
	// value from the left() member function is a reference to the
	// actual left pointer.
	bst_remove_max(root_ptr->left(), root_ptr->data());
	return true;
}*/

/// bst_remove_max
//	Precondition:
//		root_ptr is a root pointer of a non-empty binary search tree.

//	Postcondition:
//		The largest item in the binary search tree has been removed, and
//		root_ptr now points to the root of the new (smaller) binary search tree.
//		The reference parameter, removed, has been set to a copy of the removed item.
/*template <class Item>
void bst_remove_max(binary_tree_node<Item>*& root_ptr, Item& removed)
{	
	**STUDENT WORK***
	This recursive function should be implemented by the student,
	as discussed on page 528 of the fourth edition of the textbook.

	The base case occurs when there is no right child of the root_ptr node.
	
	In this case, the root_ptr should be moved down to its left child and
	then the original root node must be deleted.
	
	There is also a recursive case, when the root does have a right child.
	In this case, a recursive call can be made using root_ptr->right() as
	the first parameter.
	
	Please notice in bintree.h, the return value from root_ptr->right()
	has been changed from the first printing of the book.
	
	The new version of the right() function has the prototype:

		binary_tree_node<Item>*&

	The & symbol in the return type means that the return value is
	a reference to the actual right pointer in the node.
	
	Any changes	made to this pointer in the recursive call will
	directly change the right pointer in the root_ptr's node.
}*/