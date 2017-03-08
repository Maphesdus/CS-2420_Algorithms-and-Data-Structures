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

#include <iostream>
#include <ostream>


using namespace std;

// (Constructor is handled in the header file.)

// Destructor:
/// Purpose: Destroy all Nodes in the Linked List.
/// Parameters: n/a
/// Returns: n/a
/// Pre-Conditions: n/a
/// Post-Conditions: All nodes are destroyed using recursion.
list::List::~List()
{
	if (head != nullptr)
		destroy(head);
}

// Destroy:
/// Purpose: Helper function for the destructor.
/// Parameters: Node pointer
/// Returns: n/a
/// Pre-Conditions: n/a
/// Post-Conditions: All Nodes in the Linked List have been destroyed.
void list::List::destroy(Node* n)
{
	if (n->next != nullptr)
		destroy(n->next);

	delete n;
	n = nullptr;
}

// addEnd:
/// Purpose: Insert a new Node at the end of the Linked List.
/// Parameters: int
/// Returns: void
/// Pre-Conditions: n/a
/// Post-Conditions: Add element "d" at the end of the list using recursion.
void list::List::addEnd(string key, double value)
{
	Node* n = new Node(key, value);
	addEnd_helper(head, n);
}

// addEnd_helper:
/// Purpose: Insert a new Node at the end of the Linked List.
/// Parameters: Two Node pointer references (Node*&, Node*&)
/// Returns: void
/// Pre-Conditions: n/a
/// Post-Conditions: Add element "d" at the end of the list using recursion.
void list::List::addEnd_helper(Node*& h, Node*& n)
{
	if (h == nullptr)
		h = n;

	else if (h->next == nullptr)
		h->next = n;

	else
		addEnd_helper(h->next, n);
}



// print:
/// Purpose: Print out the data values of all the Nodes in the Linked List.
/// Parameters: n/a
/// Returns: void
/// Pre-Conditions: n/a
/// Post-Conditions: All values in the Linked List have been printed.
void list::List::print()
{
	if (head == nullptr)
		cout << "[Empty]" << endl;

	else
		print_helper(head);
}

// print_helper:
/// Purpose: Print out the data values of all the Nodes in the Linked List.
/// Parameters: Node pointer
/// Returns: n/a
/// Pre-Conditions: n/a
/// Post-Conditions: Print the list using recursion.
void list::List::print_helper(Node* n)
{
	cout << n->compound << n->weight << endl;

	if (n->next != nullptr)
		print_helper(n->next);
}


// insert:
/// Purpose: Insert a new Node into sorted order sequence while maintaining order.
/// Parameters: int
/// Returns: void
/// Pre-Conditions: List is in sorted order (don't use addEnd with this function).
/// Post-Conditions: Integer "d" is inserted into the list so the list maintains sorted order using recursison.
void list::List::insert(string key, double value)
{


	if (head == nullptr)
	{
		Node* n = new Node(key, value);
		head = n;
	}

	else if (head->weight > value)
	{
		Node* n = new Node(key, value);
		n->next = head;
		head = n;
	}

	else
		insert_helper(head, key, value);
}


// insert_helper:
/// Purpose: Insert a new Node into sorted order sequence while maintaining order.
/// Parameters: Node pointer, int
/// Returns: void
/// Pre-Conditions: n/a
/// Post-Conditions: A new Node has been inserted into the sequence in order.
void list::List::insert_helper(Node* n1, string key, double value)
{
	if (n1->next == nullptr)
		n1->next = new Node(key, value);

	// Check "n->data" to see if it's less than "d", and that its next value is greater than "d".
	else if (n1->weight < value && n1->next->weight > value)
	{
		Node* n2 = new Node(key, value);
		n2->next = n1->next;
		n1->next = n2;		
	}

	else
		insert_helper(n1->next, key, value);
}


// find:
/// Purpose: Determine whether or not the specified integer is contained by any Node in the Linked List.
/// Parameters: int
/// Returns: bool
/// Pre-Conditions: n/a
/// Post-Conditions: If "d" is in the list then find returns true, else find returns false.
bool list::List::find(string key)
{
	return find_helper(head, key);
}

// find_helper:
/// Purpose: Determine whether or not the specified integer is contained by any Node in the Linked List.
/// Parameters: Node pointer, int
/// Returns: bool
/// Pre-Conditions:n/a
/// Post-Conditions: 
bool list::List::find_helper(Node* n, string key)
{
	if (n == nullptr || n->next == nullptr && n->compound != key)
		return false;

	else if (n != nullptr && n->compound == key)
		return true;

	else
		find_helper(n->next, key);
}

// size:
/// Purpose: Uses recursion to count the number of Nodes in the Linked List.
/// Parameters: n/a
/// Returns: int
/// Pre-Conditions: n/a
/// Post-Conditions: Size is returned (must be calculated using recursion).
int list::List::size()
{
	return size_helper(head);
}

// size_helper:
/// Purpose: Helper for the size() funciton.
/// Parameters: Node*
/// Returns: int
/// Pre-Conditions: size() function is called.
/// Post-Conditions: Size is returned using recursion.
int list::List::size_helper(Node* n)
{
	if (n == nullptr)
		return 0;

	else
		return 1 + size_helper(n->next);
}