//Disclaimer:
// I Edison have not used any code other than my own(or that in the textbook) for this project.
// I also have not used any function or data - structure from the Standard - Template Library.
// I also have not shared my code with any student in this class
// I understand that any violation of this disclaimer will result in a 0 for the project.

//AVL_Tree.cpp File
//Purpose: Implementation File for the AVL Tree Class

//CS 2420
//Instructor: Todd Peterson
//Class: CS 2420
//Section: 001
//Name: Edison Gray Earnest
//Project: AVL Tree Project
//Date: 3/25/2016

#include "AVL_Tree.h"
#include <iomanip>
using namespace std;

//constructor for avl tree
AVL_Tree::AVL_Tree()
{
	root = nullptr;
	height = 0;
}

//deconstructor
AVL_Tree::~AVL_Tree()
{
	if (root != nullptr)
		DeleteHelper(root);
}


//Delete helper uses recursion to delete the nodes in the same fashion as the deconstructor pseudo-code has
void AVL_Tree::DeleteHelper(Node* current)
{
	//if this is nullptr, then program is out of scope and needs to return back to other nodes
	if (current == nullptr)
		return;

	//delete all left nodes first
	DeleteHelper(current->left);
	//delete all right nodes second
	DeleteHelper(current->right);

	//delete current root finally
	delete current;
	current = nullptr;
}

//Erase Function
void AVL_Tree::Erase(int d)
{
	//if there is a root, then call helper function to search for the data member
	if (root != nullptr)
		EraseHelper(root, d, nullptr);
}

//Erase Helper Function
bool AVL_Tree::EraseHelper(Node* current_root, int d, Node* previous)
{
	//if the data we are searching for is the same as the one on this node, then call function to delete this node
	if (current_root->data == d)
	{
		//call erase current function to finish erasing member once found
		EraseCurrent(current_root, previous);
		return true;
	}

	//if the data that we are searching for is LESSER than the data on this node, then recursively call this function AS LONG as there actually is a left node. If there isn't then data must not be on this Binary Tree at all
	else if (d < current_root->data && current_root->left != nullptr)
		EraseHelper(current_root->left, d, current_root);

	//if the data that we are searching for is GREATER than the data on this node, then recursively call this function AS LONG as there actually is a right node. If there isn't then data must not be on this Binary Tree at all
	else if (d > current_root->data && current_root->right != nullptr)
		EraseHelper(current_root->right, d, current_root);

	//if case doesn't fit either, then d is not on the binary list and cannot be erased. return false
	return false;
}

//Erase Current - Function that calculates how to erase a specific node given the place of the node, and the children - Function is not recursive
void AVL_Tree::EraseCurrent(Node* current_node, Node* previous)
{
	//determine the amount/location of children - Nodes have to be deleted different ways depending on this.
	int children = ChildrenCalc(current_node);

	//CASE#1: NO CHILDREN
	//if no children exist for the node that is going to be deleted, then determine if this is the root (previous should be nullptr)
	if (children == NO_CHILD)
	{
		//if this is the root of the binary tree, and there is no children, then this is the last node and we can delete entire root and set it back to nullptr
		if (previous == nullptr)
		{
			delete root;
			root = nullptr;
		}
		//else, this is not a root but there isn't any children. Look at previous node, and disassociate this node with that node by setting it to null, and then delete this current node.
		else
		{
			//if deleted node is the left node on the previous node, then set the previous's left to nullptr
			if (previous->left == current_node)
				previous->left = nullptr;
			//if deleted node is the right node on the previous node, then set the previous's right to nullptr
			else if (previous->right == current_node)
				previous->right = nullptr;

			//delete current nod and set it to nullptr
			delete current_node;
			current_node == nullptr;
		}
	}
	//CASE#2: A SINGLE LEFT CHILD
	//If only a single left child node is attachted to the one we are about to delete, then connect that child to the soon-to-be delete's previous node in place
	else if (children == LEFT_ONLY)
	{
		//if this is the root of the binary tree, AND there is a single left child, then make the single left child the new root and delete this node
		if (previous == nullptr)
		{
			Node* temp = root;
			root = root->left;
			delete temp;
			temp = nullptr;
		}
		//if this a just another node inside the binary tree AND there is a single left child, then replace the soon-to-be delete's spot on it's previous node with their single left child.
		else
		{
			//if the previous position was from the left, then move the left child to the left spot of the previous node's address
			if (previous->left == current_node)
				previous->left = current_node->left;
			//if the previous position was from the right, then move the left child to the right spot of the previous node's address
			else if (previous->right == current_node)
				previous->right = current_node->left;

			//current node can be deleted after node has been moved safely
			delete current_node;
			current_node = nullptr;
		}
	}
	//CASE#3: A SINGLE RIGHT CHILD
	//If only a single right child node is attachted to the one we are about to delete, then connect that child to the soon-to-be delete's previous node in place
	else if (children == RIGHT_ONLY)
	{
		//if this is the root of the binary tree, AND there is a single right child, then make the single right child the new root and delete this node
		if (previous == nullptr)
		{
			Node* temp = root;
			root = root->right;
			delete temp;
			temp = nullptr;
		}
		//if this a just another node inside the binary tree AND there is a single right child, then replace the soon-to-be delete's spot on it's previous node with their single right child.
		else
		{
			//if the previous position was from the left, then move the right child to the left spot of the previous node's address
			if (previous->left == current_node)
				previous->left = current_node->right;
			//if the previous position was from the right, then move the right child to the right spot of the previous node's address
			else if (previous->right == current_node)
				previous->right = current_node->right;

			//current node can be deleted after node has been moved safely
			delete current_node;
			current_node == nullptr;
		}
	}
	//CASE#4: BOTH LEFT AND RIGHT CHILDREN
	//If both children are on the Binary List, then the node has to be stratigically picked and replaced carefully
	else if (children == LEFT_AND_RIGHT)
	{
		//in the case of two children, then access the left spot of the current node
		Node* shift_node = current_node->left;
		//previous node of the current shift node will be calculated in case it is necessary
		Node* shift_previous = current_node;

		//shift the node all the way to the right. The data member that this lands on will be the the closest value on this portion of the binary tree, but will always be smaller. 
		//This shift node will currently replace the current node by transferring data. previous node will follow the next nodes as they shift through the while loop until there are no more right movements.
		while (shift_node->right != nullptr)
		{
			shift_previous = shift_node;
			shift_node = shift_node->right;
		}

		//once we found the appropriate match to swap the current delete with, check to see if there is a child connected to this
		if (shift_node->left == nullptr)
		{
			//if there is no left child, then it is okay to delete. Set the current_node's data and replace it with the shift's data
			current_node->data = shift_node->data;

			//go to shift previous, and deassociate the replaced node so that it no longer points to the node. Delete the shift, which is just an extra unattatched node
			//deassociate the previous left if that is what the node was connected to
			if (shift_previous->left == shift_node)
				shift_previous->left = nullptr;
			//deassociate the previous right if that is what the node was connected to
			else if (shift_previous->right == shift_node)
				shift_previous->right = nullptr;

			//program is now safe to delete the extra node. Data on this node was already manually replaced on the current node that would have been deleted otherwise
			delete shift_node;
		}

		//If there is a left child attactched the the match that we will replace the current node with
		else
		{
			//swap data from shift to current manually
			//current should still be pointing to the same places
			//in this case there is a left. Attach the left of shift_previous to the left of shift
			//delete shift because access should be prevented form obtaining shift at this point


			//transfer the shift's data to the new location
			current_node->data = shift_node->data;

			//find out if the previous shift was connected to the left or the right node

			//if left, then attatch the previous left's node to the current shift's left node so that no nodes are lost
			if (shift_previous->left == shift_node)
				shift_previous->left = shift_node->left;
			//if right, then attatch the previous right's node to the current shift's left node so that no nodes are lost
			else if (shift_previous->right == shift_node)
				shift_previous->right = shift_node->left;

			//current shift will never have a right node, as this is the most right. We can now delete this node as the other data has been safely transferred and saved.
			delete shift_node;
		}
	}
}




//size returns a 0 if there is no root, and otherwise will call helper function if a root has been created
int AVL_Tree::Size()
{
	int size = 0;

	//call helperfunction to recursively call through each of the nodes in this object
	if (root != nullptr)
		size = SizeHelper(root, 0);

	//return size of the binary tree
	return size;
}

//Helper function for size
int AVL_Tree::SizeHelper(Node* root, int s)
{
	//count root, then left,  then right
	++s;

	if (root->left != nullptr)
		s = SizeHelper(root->left, s);
	if (root->right != nullptr)
		s = SizeHelper(root->right, s);
	//return size after node has been complete counted. Final node will contain the true size once returned.
	return s;
}

//insert function - calls recursive function if we need to strategically sort and place a new node
void AVL_Tree::Insert(int d)
{
	//if root is null, then this is now the new root
	if (root == nullptr)
	{
		Node* temp = new Node(d);
		root = temp;
		height = root->UpdateHeight(root);
	}
	//else go through and insert the value passed in
	else
	{
		InsertHelper(root, d);
		Rebalance();
	}
}

void AVL_Tree::InsertHelper(Node* & current, int d)
{
	//return if roots value is the same
	if (d == current->data)
		return;
	//Search to see if d is smaller than data's value
	if (d < current->data)
	{
		//is d is smaller, check left node for nullptr. 
		//create a new left node for root if no left node exists else recursively call left node as root
		if (current->left == nullptr)
		{
			Node* temp = new Node(d);
			current->left = temp;
		}
		else
			InsertHelper(current->left, d);
	}
	//if d is bigger, then it is added to the right side
	//check to see if if right side has a node already
	else
	{
		//if right is nullptr, then create a new node and set it at the right passing in value for d
		if (current->right == nullptr)
		{
			Node* temp = new Node(d);
			current->right = temp;
		}
		//if there is a node at the right, recursively call using the right side as the new root
		else
		{
			InsertHelper(current->right, d);
		}
	}
}

//Print Function calls helper function to recursively search through Binary Tree and prints Binary Tree with indents and specific labels
void AVL_Tree::Print()
{
	//before helper function is called, a binary tree object must have data
	if (root != nullptr)
	{
		//Rebalance() <--- used for testing purposes --> rebalances height before outputing the balance value 
		PrintHelper(root, 0);
	}
}

//Print helper Function recursively prints data
void AVL_Tree::PrintHelper(Node* node_ptr, int depth)
{
	//print indintation
	cout << setw(FOUR * depth) << "";
	//if current node is empty, label it as empty
	if (node_ptr == nullptr)
		cout << "[Empty]" << endl;
	//else if the node_pointer doesn't have any children
	else if (ChildrenCalc(node_ptr) == NO_CHILD)
	{
		//cout the data of the current node, and label this as a leaf
		cout << node_ptr->data;
		cout << " [Leaf]" << " " << /*node_ptr->bal <<*/ endl;
	}
	//if current node isn't empty, and does have children
	else
	{
		//cout the node's data
		cout << node_ptr->data << " " << /*node_ptr->bal <<*/ endl;
		//recursively call left node and add another depth to indent further with
		PrintHelper(node_ptr->left, depth + 1);
		//recusively call the right node and add another depth to indent the match with left
		PrintHelper(node_ptr->right, depth + 1);
	}
}

//children calculate function determines if there is a child to the current node, and gives location of it by using 0-3 as labels
int AVL_Tree::ChildrenCalc(Node* root)
{
	//set to 0 and assume no child 
	int tempChildren = NO_CHILD;
	//if left has a node
	if (root->left != nullptr)
	{
		//and right has a node too, return 3
		if (root->right != nullptr)
			tempChildren = LEFT_AND_RIGHT;
		//only left has a node, return 1
		else
			tempChildren = LEFT_ONLY;
	}
	else
		//there is only a right node if true - return 2
		if (root->right != nullptr)
			tempChildren = RIGHT_ONLY;
	//return int value
	return tempChildren;
}



//balance bool returns true/false depending on if there is an unbalanced tree
bool AVL_Tree::BalanceBool(Node* current)
{
	//if current is at nullptr, then there is no other path this way. return false
	if (current == nullptr)
		return false;
	//else, then this data might have an unbalanced value
	else
	{
		//return tree if the balance is above 1 or less than 1. -> this will call function to return a true
		if (current->bal > 1 || current->bal < -1)
			return true;
		else
			return (BalanceBool(current->left) || BalanceBool(current->right));
	}
}

//rebalance will:
//1) update the root -> this calculates the height, then balances the height for each node
//2) once updated, call a function that finds out if we actually need to rebalance the function
//3) if true, then call helper function that searches through the nodes to find any instances of rebalancing
//4) root will then update like before (height, then balances the nodes)
//5) balancebool is called again to see if any other fixes need to be made - this iteration may not be necessary.
void AVL_Tree::Rebalance()
{
	//height is updated after each insertion
	//rebalance -> Take each side's weight, and if it is not between -1 to 1, then it needs to be rebalanced, this function is called

	if (root != nullptr)
	{
		root->Update();
		while (BalanceBool(root))
		{
			HelpRebalance(root, nullptr);
			root->Update();
		}
	}
}

//void function that helps rebalance recursively
void AVL_Tree::HelpRebalance(Node* & current, Node* previous)
{
	if (current != nullptr)
	{
		if (current->left != nullptr)
			HelpRebalance(current->left, current);
		if (current->right != nullptr)
			HelpRebalance(current->right, current);

		//we will eventually pass thorugh everything to the left, then to the right.

		//look at the bal of this node - if it is greater/less than what is acceptable, then we return send this node to get rebalanced
		//after reblance, send root back to set height/balance again
		//then this recursive round can end

		//if the balance is smaller than negative 1 or greater than 1, then it is unbalanced
		if (current->bal < -1 || current->bal > 1)
		{

			//if greater, then the left is too unbalanced 
			if (current->bal > 1)
			{

				if (current->left->bal <= 0)
				{//LR

				 //if previous is null, then the root needs to be switched
					if (previous == nullptr)
						root = RotateLeftRight(current);
					//find where the previous node is connecting to this current node- connect the returning node to it to re-attatch the tree
					else
					{
						if (previous->left == current)
							previous->left = RotateLeftRight(current);
						else if (previous->right == current)
							previous->right = RotateLeftRight(current);
					}
				}

				else if (current->left->bal >= 1)
				{//LL

				 //if previous is null, then the root needs to be switched
					if (previous == nullptr)
						root = RotateLeftLeft(current);

					//find where the previous node is connecting to this current node- connect the returning node to it to re-attatch the tree
					else
					{
						if (previous->left == current)
							previous->left = RotateLeftLeft(current);
						else if (previous->right == current)
							previous->right = RotateLeftLeft(current);
					}
				}
			}

			else if (current->bal < -1)
			{
				if (current->right->bal == -1)
				{//RR

				 //if previous is null, then the root needs to be switched
					if (previous == nullptr)
						root = RotateRightRight(current);
					//find where the previous node is connecting to this current node- connect the returning node to it to re-attatch the tree
					else
					{
						if (previous->left == current)
							previous->left = RotateRightRight(current);
						else if (previous->right == current)
							previous->right = RotateRightRight(current);
					}
				}

				else if (current->right->bal == 1)
				{//RL

				 //if previous is null, then the root needs to be switched
					if (previous == nullptr)
						root = RotateRightLeft(current);
					//find where the previous node is connecting to this current node- connect the returning node to it to re-attatch the tree
					else
					{
						if (previous->left >= current)
							previous->left = RotateRightLeft(current);
						else if (previous->right == current)
							previous->right = RotateRightLeft(current);
					}
				}
			}
		}
	}
}

//rotates left left
Node* AVL_Tree::RotateLeftLeft(Node* & current)
{
	Node* tempNode = nullptr;

	//Function that shifts temp, which is the middle focus point for the rest of the node shifting

	tempNode = current->left;
	tempNode->right = current;
	current->left = nullptr;

	//current returns temp which is the new focus point that needs to get reattatched to the rest of the tree

	return tempNode;
}

//rotates left right
Node* AVL_Tree::RotateLeftRight(Node* & current)
{
	Node* tempNode = nullptr;

	//Function shift current temp, which is the middle value (left then right), making it the focus for the rest of shifting.

	tempNode = current->left->right;
	tempNode->left = current->left;
	tempNode->left->right = nullptr;
	tempNode->right = current;
	current->left = nullptr;

	//current returns temp which is the new focus point that needs to get reattatched to the rest of the tree

	return tempNode;
}

//rotates right right
Node* AVL_Tree::RotateRightRight(Node* & current)
{
	Node* tempNode = nullptr;

	//Function shifts current temp, which is middle value that is the focus of the shifting.

	tempNode = current->right;
	current->right = tempNode->left;
	tempNode->left = current;

	//current returns temp which is the new focus point that needs to get reattatched to the rest of the tree

	return tempNode;
}

//rotates right left
Node* AVL_Tree::RotateRightLeft(Node* & current)
{
	Node* tempNode = nullptr;

	//Function shifts to the right-then-left node, making it the new focus point that is returned back to be reconnected with the tree.

	tempNode = current->right->left;
	tempNode->left = current;
	current->right->left = tempNode->right;
	tempNode->right = current->right;
	current->right = nullptr;

	//current returns temp which is the new focus point that needs to get reattatched to the rest of the tree

	return tempNode;
}



void AVL_Tree::InOrder()
{
	//call inorder helper function if root exists
	if (root != nullptr)
		InOrderHelper(root);
}

void AVL_Tree::InOrderHelper(Node* current)
{
	//return if root is null
	if (current == nullptr)
		return;
	//left first
	InOrderHelper(current->left);
	//then current node
	cout << current->data << ' ';
	//then right node
	InOrderHelper(current->right);
}