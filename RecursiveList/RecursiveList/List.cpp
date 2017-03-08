// NAME: Adam Armstrong
// SECTION: CS 2420 - 002
// PROFESSOR: Todd S. Peterson
// Due: 1/21/2016

// DISCLAIMER:
// I, Adam Armstrong, have not used any code other than my own (or that in the textbook) for this project.
// I also have not used any function or data-structure from the Standard-Template Library.
// I also have not shared my code with any student in this class.
// I understand that any violation of this disclaimer will result in a 0 for the project.

//	Project 2: Recursive List

#include "List.h"

// http://www.cs.cmu.edu/~pattis/15-1XX/15-200/lectures/llrecursion/

// (Constructor is handled in the header file.)

// Destructor:
/// Purpose:
/// Parameters:
/// Returns: n/a
/// Pre-Conditions:
/// Post-Conditions: All nodes are destroyed using recursion.
list_2::List::~List()
{
	if (head != nullptr)
		destroy(head);
}

// Destroy:
/// Purpose: Helper function for the destructor.
/// Parameters:
/// Returns: n/a
/// Pre-Conditions:
/// Post-Conditions:
void list_2::List::destroy(Node* n)
{
	if (n->next != nullptr)
		destroy(n->next);

	delete n;
}

// addEnd:
/// Purpose: Insert a new Node at the end of the Linked List.
/// Parameters: int
/// Returns: void
/// Pre-Conditions: n/a
/// Post-Conditions: Add element "d" at the end of the list using recursion.
void list_2::List::addEnd(int d)
{
	Node* n = new Node(d);
	addEnd_helper(head, n);
}

// addEnd_helper:
/// Purpose: Insert a new Node at the end of the Linked List.
/// Parameters: Two Node pointer references (Node*&, Node*&)
/// Returns: void
/// Pre-Conditions: n/a
/// Post-Conditions: Add element "d" at the end of the list using recursion.
void list_2::List::addEnd_helper(Node*& head, Node*& n)
{
	if (head == nullptr)
		head = n;

	else if (head->next == nullptr)
		head->next = n;

	else
		addEnd_helper(head->next, n);
}



// print:
/// Purpose:
/// Parameters:
/// Returns: n/a
/// Pre-Conditions:
/// Post-Conditions: Print the list using recursion.
void list_2::List::print()
{
	if (head == nullptr)
		cout << "[Empty]" << endl;

	else
		print_helper(head);
}

// print_helper:
/// Purpose:
/// Parameters:
/// Returns: n/a
/// Pre-Conditions:
/// Post-Conditions: Print the list using recursion.
void list_2::List::print_helper(Node* n)
{
	cout << n->data << endl;

	if (n->next != nullptr)
		print_helper(n->next);
}


// insert:
/// Purpose:
/// Parameters: int
/// Returns: void
/// Pre-Conditions: List is in sorted order (don't use addEnd with this function).
/// Post-Conditions: Integer "d" is inserted into the list so the list maintains sorted order using recursison.
void list_2::List::insert(int d)
{


	if (head == nullptr)
	{
		Node* n = new Node(d);
		head = n;
	}

	else if (head->data > d)
	{
		Node* n = new Node(d);
		n->next = head;
		head = n;
	}

	else
		insert_helper(head, d);
}


// insert_helper:
/// Purpose:
/// Parameters: Node pointer, int
/// Returns: void
/// Pre-Conditions:
/// Post-Conditions:
void list_2::List::insert_helper(Node* n1, int d)
{
	if (n1->next == nullptr)
		n1->next = new Node(d);

	// Check "n->data" to see if it's less than "d", and that its next value is greater than "d".
	else if (n1->data < d && n1->next->data > d)
	{
		Node* n2 = new Node(d);
		n2->next = n1->next;
		n1->next = n2;		
	}

	else
		insert_helper(n1->next, d);
}


// find:
/// Purpose: Determine whether or not the specified integer is contained by any Node in the Linked List.
/// Parameters: int
/// Returns: bool
/// Pre-Conditions: n/a
/// Post-Conditions: If "d" is in the list then find returns true, else find returns false.
bool list_2::List::find(int d)
{
	return find_helper(head, d);
}

// find_helper:
/// Purpose: Determine whether or not the specified integer is contained by any Node in the Linked List.
/// Parameters: Node pointer, int
/// Returns: bool
/// Pre-Conditions:n/a
/// Post-Conditions: 
bool list_2::List::find_helper(Node* n, int d)
{
	if (n == nullptr || n->next == nullptr && n->data != d)
		return false;

	else if (n != nullptr && n->data == d)
		return true;

	else
		find_helper(n->next, d);
}

// size:
/// Purpose: Uses recursion to count the number of Nodes in the Linked List.
/// Parameters: n/a
/// Returns: int
/// Pre-Conditions: n/a
/// Post-Conditions: Size is returned (must be calculated using recursion).
int list_2::List::size()
{
	return size_helper(head);
}

// size_helper:
/// Purpose: Helper for the size() funciton.
/// Parameters: Node*
/// Returns: int
/// Pre-Conditions: size() function is called.
/// Post-Conditions: Size is returned using recursion.
int list_2::List::size_helper(Node* n)
{
	if (n == nullptr)
		return 0;

	else
		return 1 + size_helper(n->next);
}