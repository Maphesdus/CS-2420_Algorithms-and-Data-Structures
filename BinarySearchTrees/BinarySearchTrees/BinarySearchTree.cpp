// NAME: Adam Armstrong
// SECTION: CS 2420 - 002
// PROFESSOR: Todd S. Peterson
// Due: 3/10/2016

// DISCLAIMER:
// I, Adam Armstrong, have not used any code other than my own (or that in the textbook) for this project.
// I also have not used any function or data-structure from the Standard-Template Library.
// I also have not shared my code with any student in this class.
// I understand that any violation of this disclaimer will result in a 0 for the project.

//	Project 07: Binary Search Tree

#include "BinarySearchTree.h"

// Constructor (page 493):
/// Purpose:
/// Parameters:
/// Returns:
/// Pre-Conditions:
/// Post-Conditions:
BinarySearchTree::BinarySearchTree()
{
	Node *root_ptr;
	Node *child_ptr;

	// 1. Make root_ptr point to a new Node. Both child pointers are initially null.
	root_ptr = new Node();

	// 2. Make child_ptr point to a new node. Give it two leaves as children. Then activate root_ptr->setLeft(child_ptr);
	child_ptr = new Node();
	root_ptr->setLeft(child_ptr);

	// 3. Make child_ptr point to a new node. Give it two leaves as children. Then activate root_ptr->setRight(child_ptr);
	child_ptr = new Node();
	root_ptr->setRight(child_ptr);

	// 4. Return root_ptr. (Unnecessary since we're doing this in the constructor?)
}

// Destructor:
/// Purpose:
/// Parameters:
/// Returns:
/// Pre-Conditions:
/// Post-Conditions:
BinarySearchTree::~BinarySearchTree()
{
	// ???
}

// Size:
/// Purpose:
/// Parameters:
/// Returns:
/// Pre-Conditions:
/// Post-Conditions:
int BinarySearchTree::Size()
{
	return Size_helper(root);
}

// Size_helper:
/// Purpose:
/// Parameters:
/// Returns:
/// Pre-Conditions:
/// Post-Conditions:
int BinarySearchTree::Size_helper(Node* n)
{
	if (n == nullptr)
		return 0;

	else
		return 1 + Size_helper(n->left()) + Size_helper(n->right());
}

/*	Print(): Do the indented print that was discussed in class
		Pre-order traversal
		Print one element per line
		Indent according to the depth (See page 505) */

// Print (page 506):
/// Purpose:
/// Parameters:
/// Returns:
/// Pre-Conditions:
/// Post-Conditions:
void BinarySearchTree::Print()
{
	Print_helper(root, 0);
}

// Print Helper:
/// Purpose:
/// Parameters:
/// Returns:
/// Pre-Conditions:
/// Post-Conditions:
void BinarySearchTree::Print_helper(Node* node_ptr, int depth)
{
	cout << setw(4 * depth) << "";

	if (node_ptr == nullptr)
	{
		cout << "[EMPTY]" << endl;
	}

	else if (node_ptr->isLeaf())
	{
		cout << node_ptr->data();
		cout << " [LEAF]" << endl;
	}

	else
	{
		cout << node_ptr->data() << endl;
		Print_helper(node_ptr->right(), depth + 1);
		Print_helper(node_ptr->left(), depth + 1);
	}
}

// Find:
/// Purpose:
/// Parameters:
/// Returns:
/// Pre-Conditions:
/// Post-Conditions:
bool BinarySearchTree::Find(Node* n, int item)
{
	if (n == nullptr)
		return false;

	else
	{
		if (n->data() == item)
			return true;

		else if (n->data() != item)
		{
			Find(n->left(), item);
			Find(n->right(), item);
		}

	}
}
 
// Erase (page 525-526):
/// Purpose:
/// Parameters:
/// Returns:
/// Pre-Conditions:
/// Post-Conditions:
void BinarySearchTree::Erase(int item)
{
	//Erase_helper(root, item);
	remove(root, item);
}

// Erase Helper:
/// Purpose:
/// Parameters:
/// Returns:
/// Pre-Conditions:
/// Post-Conditions:
void BinarySearchTree::Erase_helper(Node* n, int target)
{
	Node* old_n_ptr;

	if (n == nullptr) {
		cout << "Error. Cannot erase number. Node pointer is null." << endl;
		return;
	}

	//	If Node "n" has no children (i.e. Node "n" is a leaf),
	//	just set its pointer to null and then delete Node "n".
	if (n->isLeaf())
	{
		n = nullptr;
		delete n;
	}

	//	Otherwise, if Node "n" is *NOT* a leaf (i.e. Node "n" has at least one child),
	//	and the data_field of "n" matches the target value,
	//	redirect Node n's pointer to its child, and then delete Node "n".
	else
	{
		// If the data_field of "n" matches the target value...

		// Data == target
		if (n->data() == target)
		{
			//	If Node "n" has only one child (either left or right)...
			//	If either the left or right children return a value...
			if (n->left() || n->right())
			{
				//	2b.	If the left child returns a value but the right child does not...
				if (n->left() && !n->right())
				{
					//	Redirect n's pointer to its left child
					//	by copying "n" into another pointer,
					//	setting "n" equal to its left child,
					//	and then deleting the copy of "n".
					old_n_ptr = n;
					n = n->left();
					delete old_n_ptr;
				}

				//	If the right child returns a value but the left child does not...
				if (!n->left() && n->right())
				{
					//	Redirect n's pointer to its right child
					//	by copying "n" into another pointer,
					//	setting "n" equal to its right child,
					//	and then deleting the copy of "n".
					old_n_ptr = n;
					n = n->right();
					delete old_n_ptr;
				}

				//	If Node "n" has two children,
				//	redirect its pointer to the appropreate child (always left),
				//	have the other child (always right) become the bottom-most child of that child,
				//	and then delete Node "n".

				//	If *BOTH* children return a value...
				if (n->left() && n->right())
				{
					old_n_ptr = n;
					n = n->left();

					//	If the right child of new "n" is null, set
					//	the right pointer of old_n_ptr to be the
					//	right pointer of new "n".
					if (n->right() == nullptr)
						n->right() = old_n_ptr->right();

					//	Otherwise, if the right child of new "n" is *NOT* null,
					//	do something... ?
					else
					{
						// ???
					}

					delete old_n_ptr;
				}
			} // End if (n->left() || n->right())
		} // End if (n->data == target)

		  // If the data_field of "n" does *NOT* match the target value...

		  // Data != target
		if (n->data() != target)
		{
			//	Check to see if the data_field of Node n's left child is
			//	equal to or lower than the target. If it is, run the
			//	function recursively with the left child.
			if (n->left()->data() <= target)
				Erase_helper(n->left(), target);

			//	Otherwise, if the data_field of Node n's left child
			//	is *NOT* equal to or lower than the target, run the
			//	function recursively with the right child.
			else
				Erase_helper(n->right(), target);
		}
	}
} // End Erase_helper()

// Erase 2:
/// Purpose:
/// Parameters:
/// Returns:
/// Pre-Conditions:
/// Post-Conditions:
void BinarySearchTree::Erase2(int item)
{
	//Node* child;

	/*if (n != nullptr)
	{
		child = n->data->left();
		//Erase2();

		child = n->data->right();
		//Erase2();

		delete n;
		root = nullptr;
	}*/
}


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

// Insert (page 524-525):
/// Purpose:
/// Parameters:
/// Returns:
/// Pre-Conditions:
/// Post-Conditions:
void BinarySearchTree::Insert(int item)
{
	Insert_helper(root, item);
}

// Insert Helper:
/// Purpose:
/// Parameters:
/// Returns:
/// Pre-Conditions:
/// Post-Conditions:
void BinarySearchTree::Insert_helper(Node* n, int item)
{
	if (root == nullptr)
	{
		root = new Node(item);
		return;
	}

	// data == item
	if (n->data() == item)
	{
		cout << "Error. Duplicate entry. No duplicates allowed." << endl;
		return;
	}

	// data > item
	if (n->data() > item)
	{
		if (n->left() == nullptr)
		{
			Node* new_child = new Node(item);
			n->setLeft(new_child);
			return;
		}

		else
		{
			Insert_helper(n->left(), item);
		}
	}

	// data < item
	else if (n->data() < item)
	{
		if (n->right() == nullptr)
		{
			Node* new_child = new Node(item);
			n->setRight(new_child);
			return;
		}

		else
		{
			Insert_helper(n->right(), item);
		}
	}
}


/// -------------------------------------------------------------------------------------------
//	Traversals (just print out the items, don’t worry about passing functions as parameters)
//		Pre-Order
//		In-Order
//		Post-Order
/// -------------------------------------------------------------------------------------------

// Pre-Order Print:
/// Purpose:
/// Parameters:
/// Returns:
/// Pre-Conditions:
/// Post-Conditions:
void BinarySearchTree::PreOrderPrint()
{
	// 1. Process the root.
	// 2. Process the nodes in the left subtree with a recursive call.
	// 3. Process the nodes in the right subtree with a recursive call.

	PreOrderPrint(root);
	cout << endl;
}

// In-Order Print:
/// Purpose:
/// Parameters:
/// Returns:
/// Pre-Conditions:
/// Post-Conditions:
void BinarySearchTree::InOrderPrint()
{
	// 1. Process the nodes in the left subtree with a recursive call.
	// 2. Process the root.
	// 3. Process the nodes in the right subtree with a recursive call.

	InOrderPrint(root);
	cout << endl;
}

// Post-Order Print:
/// Purpose:
/// Parameters:
/// Returns:
/// Pre-Conditions:
/// Post-Conditions:
void BinarySearchTree::PostOrderPrint()
{
	// 1. Process the nodes in the left subtree with a recursive call.
	// 2. Process the nodes in the right subtree with a recursive call.
	// 3. Process the root.

	PostOrderPrint(root);
	cout << endl;
}

void BinarySearchTree::PreOrderPrint(Node* n)
{
	if (n == nullptr)
		return;

	display(n);
	PreOrderPrint(n->left());
	PreOrderPrint(n->right());
}

void BinarySearchTree::InOrderPrint(Node* n)
{	
	if (n == nullptr)
		return;

	InOrderPrint(n->left());
	display(n);
	InOrderPrint(n->right());
}

void BinarySearchTree::PostOrderPrint(Node* n)
{
	if (n == nullptr)
		return;

	PostOrderPrint(n->left());
	PostOrderPrint(n->right());
	display(n);
}

void BinarySearchTree::display(Node* n)
{
	cout << n->data() << " ";
}

// Remove (pages 526-528):
/// Purpose:
/// Parameters:
/// Returns:
/// Pre-Conditions:
/// Post-Conditions:
void BinarySearchTree::remove(Node*& root_ptr, int& target)
{
	if (root_ptr == nullptr)
		return;

	else
	{
		if (target < root_ptr->data())
			remove(root_ptr->left(), target);

		else if (root_ptr->data() < target)
			remove(root_ptr->right(), target);

		else if (target == root_ptr->data())
		{
			// Zero children:
			if (root_ptr->isLeaf())
			{
				delete root_ptr;
				root_ptr = nullptr;
			}

			// Two children:
			else if (root_ptr->left() != nullptr && root_ptr->right() != nullptr)
			{
				// find largest number on left
				Node*& greatest = find_greatest(root_ptr->left());

				root_ptr->setData(greatest->data());				
				remove(greatest, greatest->data());
			}

			// One child:
			else
			{
				/* if (left == null)
						child = n->rightchild;
					else
						child = n->leftchild; */

				Node* child = root_ptr->left() ? root_ptr->left() : root_ptr->right();
				delete root_ptr;
				root_ptr = child;
			}
		}
	} // End else statement
}


Node*& BinarySearchTree::find_greatest(Node*& n)
{
	if (n->right())
		return find_greatest(n->right());

	else
		return n;
}

// Page 526-528
void BinarySearchTree::remove_comments(Node* root_ptr, int& target)
{
	//	1.	The binary serach tree could be empty, indicated by a root pointer that is NULL.
	//		If there's nothing in the tree, then there's nothing to remove, and the function returns with no work.
	if (root_ptr == nullptr)
		return;

	else
	{
		//	2.	The tree could be non-empty, with the target LESS THAN the root entry.
		//		In this case, make a recursive call to delete the target from the left subtree, like this:
		///			remove(root_ptr->left(), target;
		//		This recursive call works correctly because root_ptr->left() is the root pointer for a smaller binary search tree (that is, the left subtree).
		if (target < root_ptr->data())
			remove(root_ptr->left(), target);

		//	3.	The tree could be non-empty, with the root entry LESS THAN the target. Again, make a recursive call, using the pointer to the right subtree.
		else if (root_ptr->data() < target)
			remove(root_ptr->right(), target);

		//	4.	The tree could be non-empty, with the target EQUAL TO the root entry. We have found a copy of the target and must somehow remove it from the tree.
		//		But be careful! We can't simply delete this node, because it may have children and we don't want those children to be disconnected from the rest of
		//		the tree. To avoid orphaning those children, we'll deal with Case 4 in two seperate cases: 4a and 4b.
		else if (target == root_ptr->data())
		{
			//	4a.	The root node has no left child. In this case, the root data is equal to the target, and the root node has no left child.
			//		Here we can delete the root entry and make the right child the new root node. To actually implement this root shift requires three steps:
			///			oldroot_ptr = root_ptr;
			///			root_ptr = root_ptr->right();
			///			delete oldroot_ptr;
			//		The variable oldroot_ptr is a local variable that we make point to the old root (the root that we are about to get rid of). We then move the actual root
			//		pointer down to its right child. And finally we execute delete old_root_ptr, which returns the old root node to the heap. This scheme works correctly even
			//		if there is no right child. With no right child, the statement "root_ptr = root_ptr->right()" will set the root pointer to NULL, indicating that there are
			//		no nodes left in this particular tree.
			if (root_ptr->left() == nullptr)
			{
				Node* oldroot_ptr = root_ptr;
				root_ptr = root_ptr->right();
				delete oldroot_ptr;
			}

			//	4b.	The root node does have a left child. In this case, the root node does have a left child, so we can't simply move the root pointer to the right (as we did in case 4a).
			//		We could check whether there is a right child, and if not, we could certainly move the root pointer left -- but we have a more general plan in mind. The plan is to find some
			//		entry in the non-empty left subtree, and move this entry up to the root. But Which entry?

			//		Here's an example to help you figure out which entry should be taken from the left subtree to replace the root entry.
			//		In this example, we are deleting Pittsburgh from this subtree:
			///			(see page 528)
			//		The plan is to replace the root with one of the three entries from the left sub-tree. Which of these entries can safely be moved to the root? Not Atlanta, because
			//		the remaining entries in the left subtree (Chicago and Denver), would be larger than the new root (Atlanta). Not Chicago, because that would leave the larger string
			//		Denver in the left subtree. What about Denver? Yes, that will do, since none of the entries that remain in the left subtree are larget than Denver.
			//		Here is the resulting subtree after removing Denver from the left subtree and placing it at the root:
			///			(see page 528)
			//		The string Denver is the correct choice because it is the LARGEST ENTRY IN THE LEFT SUBTREE. Any other choice from the left subtree will violate the binary search tree storage rules.
			//		So, how do we delete the largest item from the left subtree,  and place this same item at the root? We can use our own remove_max function, with the call:
			///			remove_max(root_ptr->left(), root_ptr->data());
			//		Now you know why we proposed the remove_max function. Used in this way, it removes the largest item from the tree with root_ptr->left() as its root pointer, and it places this
			//		largest item in the root's data field.

			else if (root_ptr->left() != nullptr)
				remove_max(root_ptr->left(), root_ptr->data());
		}
	} // End else statement
}

// Remove_Max (pages 528-529):
/// Purpose:
/// Parameters:
/// Returns:
/// Pre-Conditions:
/// Post-Conditions:
void BinarySearchTree::remove_max(Node* root_ptr, int& removed)
{
	//	We'll leave this as an excercise in recursive thinking, with just two cases:

	//	(1)	The base case occurs if there is no right child. In this case, the largest item is at the root, so you can set
	//		"removed" equal to the data from the root, move the root pointer down to the left, and delete the root node.
	if (root_ptr->right() == nullptr)
	{
		Node* oldroot_ptr = root_ptr;

		removed = oldroot_ptr->data();
		root_ptr = root_ptr->left();
		delete oldroot_ptr;
	}

	//	(2)	On the other hand, if there is a right child, then there are larger items in the right subtree.
	//		In this case, make a recursive call to delete the largest item from the right subtree.
	else if (root_ptr->right() != nullptr)
		remove_max(root_ptr->right(), root_ptr->data());
}